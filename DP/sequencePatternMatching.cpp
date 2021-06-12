#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int isSubsequence(string x,string y){
    int n = x.length(), m = y.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j = 0;j<=m;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    if(dp[n][m] == m)
        return 1;
    return 0;
}
int main(){
    string x = "ADXCPY",y = "AGY";
    cout<< isSubsequence(x,y)<<endl;
    return 0;
}