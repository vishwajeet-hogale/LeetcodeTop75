#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int editDistance(string s,string t){
    vector<vector<int>> dp(s.length()+1,vector<int>(t.length(),0));
    for(int i=0;i<=t.length();i++){
        dp[0][i] = i;
    }
    for(int i=0;i<=s.length();i++){
        dp[i][0] = i;
    }
    for(int i=1;i<=s.length();i++){
        for(int j=1;j<=t.length();j++){
            if(s[i-1] == t[j-1])
                dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]);
            else
                dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1,2+dp[i-1][j-1]);
        }
    }
    return dp[s.length()][t.length()];
}