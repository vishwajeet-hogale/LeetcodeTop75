#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int LCS(string x,string y){
    int n = x.length();int m = y.length();
    int dp[n+1][m+1]={-1};
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    
    for(int i=1;i<=m;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int minNumDeletions(string x,string y){
    int lcs = LCS(x,y);
    return x.length()-lcs;
}
int main(){
    cout<<minNumDeletions("abcdef","de")<<endl;
    return 0;
}