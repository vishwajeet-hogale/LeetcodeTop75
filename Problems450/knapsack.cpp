#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n) 
{ 
    // Your code here
    vector<vector<int>> dp(1001,vector<int>(1001));
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(j == 0 || i== 0)
                dp[i][j] = 0;
            else if(wt[i-1]<=j)
                dp[i][j] = max(dp[i-1][j],val[i-1] + dp[i-1][j-wt[i-1]]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}