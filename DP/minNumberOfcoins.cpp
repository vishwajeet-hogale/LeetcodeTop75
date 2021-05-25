#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// int coinChange(vector<int>& coins, int amount) {
//         int dp[coins.size()+1][amount+1];
//         // memset(dp,-1,sizeof(dp));
//         for(int i=1;i<coins.size()+1;i++){
//             dp[i][0] = 0;
//         }
//         for(int i=0;i<amount+1;i++){
//             dp[0][i] = INT_MAX-1;
//         }
//         for(int i=1;i<amount+1;i++){
//             if(i % coins[0] == 0){
//                 dp[1][i] = i/coins[0];
//             }
//             else{
//                 dp[1][i] = INT_MAX-1;
//             }
//         }
//         for(int i=2;i<coins.size()+1;i++){
//             for(int j=1;j<=amount;j++){
                
//                 // if(i==0){
//                 //     return 0;
//                 // }
//                 if(coins[i-1]<=j){
//                     dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
//                 }
//                 else{
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }
//         return dp[coins.size()][amount];
//     }
int coinChange(vector<int> &coins,int amount){
    vector<int> dp(amount+1,amount+1);
    dp[0] = 1;
    for(int i=1;i<=coins.size();i++){
        for(int j = 0;j<amount+1;j++){
            if(j == 0){
                return 1;
            }
            if(j>= coins[i-1]){
                dp[i]=min(dp[i-1],1+dp[i-1]);
            }
        }
    }
    return dp[amount] != amount+1 ? dp[amount] : -1;
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