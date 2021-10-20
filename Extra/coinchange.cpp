#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        
        dp[0] = 0;
        for(int i =0;i<=amount ;i++){
            for(int j = 0;j<coins.size();j++){
                if(coins[j] <= i){
                    dp[i] = min(dp[i],1 + dp[i - coins[j]]);
                }
            }
        }
        if(dp[amount] > amount){
            return -1;
        }
        return dp[amount];
    }
int main(){
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    cout<<coinChange(coins,20)<<endl;
    return 0;
    
}