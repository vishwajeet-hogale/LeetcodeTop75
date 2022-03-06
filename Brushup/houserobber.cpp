#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int houserobber(vector<int> &a){
    vector<int> dp(a.size(),0);
    dp[0] = a[0];
    dp[1] = max(a[0],a[1]);
    int n = a.size();
    for(int i=2;i<a.size();i++){
        dp[i] = max(dp[i-2] + a[i],dp[i-1]);
    }
    return dp[n-1];
}