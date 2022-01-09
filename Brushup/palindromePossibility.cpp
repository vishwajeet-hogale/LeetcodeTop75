#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int palindromePossibility(string s){
    unordered_map<char,int> mp;
    for(char c:s){
        mp[c]++;
    }
    unordered_map<int,vector<char>> res;
    for(auto x:mp){
        if(res.find(x.second)!=res.end()){
            res[x.second].push_back(x.first);
        }
        else{
            res[x.second] = {x.first};
        }
    }
    
    for(auto x:res){
        if(x.first%2!=0){
            if(res[x.first].size()>1)
                return 0;
        }
        
    }
    
    return 1;
}
int main(){
    string s = "aeaeb";
    cout<<palindromePossibility(s)<<endl;
    return 0;
}
// {2:{a,e}, 1:{b,t}}