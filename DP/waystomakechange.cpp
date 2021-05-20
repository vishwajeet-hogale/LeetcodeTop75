#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
        int dp[coins.size()+1][amount+1];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<coins.size()+1;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<amount+1;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<coins.size()+1;i++){
            for(int j=1;j<=amount;j++){
                if(j==0){
                    return 1;
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
        return dp[coins.size()][amount];
    }
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(5);
    cout<<coinChange(nums,8)<<endl;
    return 0;
}