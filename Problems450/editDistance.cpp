#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int editDistance(string s,string t){
    int n=s.length();int m=t.length();
    vector<vector<int>> dp(101,vector<int>(101,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1];
                // dp[i][j] = min(dp[i][j],dp[i-1][j-1]+2);
            }
            else{
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = min(dp[i][j],dp[i-1][j-1])+1;
            }
        }
    }
    return dp[n][m];
}
int main(){
    string s = "geek",t="gesek";
    cout<<editDistance(s,t)<<endl;
    return 0;
}