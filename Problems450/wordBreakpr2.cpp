#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int wordBreak(vector<string> dict,string s,vector<string> &temp){
    if(s.length() == 0){
        for(string i:temp)
            cout<<i<<" ";
        cout<<endl;
        // return true;
    }
    int res = false;
    for(string x:dict){
        int len = x.length();
        
        if(x.compare(s.substr(0,len))==0){
            temp.push_back(x);
            res = res || wordBreak(dict,s.substr(len),temp);
            temp.pop_back();
        }
    }
    return res;
}
int main(){
    string s= "catsanddog";
    int n = 5;vector<string> temp;
    vector<string> dict({"cats", "cat", "and", "sand", "dog","ca","t"});
    cout<<wordBreak(dict,s,temp)<<endl;
    return 0;
}