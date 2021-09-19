#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<string> res;
void helper(string s,int i,int n){
    if(i==n){
        res.push_back(s);
        return;
    }
    for(int j=i;j<n;j++){
        swap(s[i],s[j]);
        helper(s,i+1,n);
        swap(s[i],s[j]);
    }
}
vector<string>find_permutation(string S)
{

    helper(S,0,S.length());
    sort(res.begin(),res.end());
    return res;
}