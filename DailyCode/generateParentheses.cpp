#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<string> res;
void helper(int open,int close,string s){
    if(open == close && close ==0){
        res.push_back(s);
        cout<<s<<endl;
        return;
        
    }
    if(open>0){
        s.push_back('(');
        helper(open-1,close,s);
        s.pop_back();

    }

    if(open < close){
        s.push_back(')');
        helper(open,close - 1,s);
        s.pop_back();
    }
}
vector<string> generateParentheses(int n){
    string s = "";
    helper(n,n,s);
    
    return res;
}
int main(){
    res = generateParentheses(3);
    for(string s:res){
        cout<<s<<endl;
    }
    return 0;
}