// 1335. Minimum Difficulty of a Job Schedule
// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

class Solution {
private:
    long long dp[11][301][1002];
    long long solve(int i, int d, int m, vector<int> &arr){
        if(i==arr.size()) return d == 0 ? m : 1e9 ;
        if(dp[d][i][m] != -1) return dp[d][i][m];
        long long op1 = 1e9, op2 = 1e9;
        if(d > 0) op1 = max(arr[i], m) + solve(i+1,d-1,0,arr);
        op2 = solve(i+1,d,max(m,arr[i]),arr);
        return dp[d][i][m] = min(op1, op2);
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size()) return -1;
        memset(dp,-1,sizeof dp);
        return solve(0,d,0,jobDifficulty);
    }
};