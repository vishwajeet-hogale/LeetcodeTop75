#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    
map<int,string> m;
void init(){

    m[2] = "abc";
    m[3] = "def";
    m[4] = "ghi";
    m[5] = "jkl";
    m[6] = "mno";
    m[7] = "pqrs";
    m[8] = "tuv";
    m[9] = "wxyz";
}
    void backtrack(string digits,string temp){
        if(digits.length() == 0){
            res.push_back(temp);
            return;
        }
        for(char c:m[digits[0]-'0']){

            backtrack(digits.substr(1),temp + c);
        }
    }
    vector<string> letterCombinations(string digits) {
        init();
       if(digits.length())
            backtrack(digits,"");
        return res;
    }
};