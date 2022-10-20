// 12. Integer to Roman

// https://leetcode.com/problems/integer-to-roman/

SOLUTION1 :
class Solution {
public:
    string intToRoman(int num) {
        int normal[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        for(int i=0;i<13;i++){
            while(num>=normal[i]){
                res.append(roman[i]);
                num-=normal[i];
            }
        }
        return res;
    }
};


SOLUTION 2:
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> vect = {{1000, "M"},{900, "CM"} , {500, "D"},{400, "CD"} , {100, "C"} , {90, "XC"}, {50, "L"}, {40, "XL"},{10, "X"}, {9, "IX"},{5, "V"} , {4, "IV"},{1, "I"} };
        string res = "";
        while(num > 0){
            for(auto x : vect){
                if(num >= x.first){
                    res += x.second;
                    num = num - x.first;
                    break;
                }
            }
        }
        return res;
    }
};