#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> nums,int amount){
    vector<vector<int>> dp(1001,vector<int>(1001));
    int n = nums.size();
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;

    }
    for(int j=1;j<=amount;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            if(j == 0)
                dp[i][j] = 1;
            if(nums[i-1]<=j)
                dp[i][j] = dp[i-1][j] + dp[i][j-nums[i-1]];
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][amount];
}