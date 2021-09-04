#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cmp(pair<string,int> a,pair<string,int> b){
    return a.second>b.second;
}
string secFrequent(string arr[],int n){
    unordered_map<string,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    vector<pair<string,int>> ss;
    for(auto x:m){
        ss.push_back(make_pair(x.first,x.second));
    }
    sort(ss.begin(),ss.end(),cmp);
    return ss[1].first;
}