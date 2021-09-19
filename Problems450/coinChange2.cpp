#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// int coinChange()
 int change(int amount, vector<int>& coins) {
        int N = coins.size()+1;
         int dp[N][amount+1];
        
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<N;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<amount+1;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<N;i++){
            for(int j=1;j<=amount;j++){
                if(j==0){
                    dp[i][j] = 1;
                }
                // if(i==0){
                //     return 0;
                // }
                if(coins[i-1]<=j){
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N-1][amount];
    }