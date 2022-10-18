// 38. Count and Say

// https://leetcode.com/problems/count-and-say/
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";       
        
        string str = countAndSay(n-1);        
        string str1 = "";
        
        for(int i = 0; i<str.length(); i++) {  
            int count = 1;
            char ch = str[i];
            
            while(i < str.length()-1 && str[i] == str[i+1]) {
                count++;
                i++;
            }
            
            str1 += to_string(count) + string(1, str[i]);
        }
        return str1;       
    }
};