1531. String Compression II


// https://leetcode.com/problems/string-compression-ii/

class Solution {
public:
    inline int getLength(int cnt) {
        return cnt == 1 ? 1 : (cnt < 10 ? 2 : (cnt < 100 ? 3 : 4));
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        int d[n+1][k+1];
        for (int i = n; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                if (i == n) {d[n][j] = 0; continue;}
                d[i][j] = j > 0 ? d[i+1][j-1] : INT_MAX;
                int m = j, cnt = 0;
                for (int l = i; l < n && m >= 0; l++) {
                    if (s[l] == s[i]) {
                        cnt++;
                        d[i][j] = min(d[i][j], getLength(cnt) + d[l+1][m]);
                    } else {
                        m--;
                    }
                }
            }
        }
        return d[0][k];
    }
};