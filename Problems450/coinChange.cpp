#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> nums,int amount){
    vector<int> dp(amount+1,amount+1);
    dp[0] = 0;
    for(int i=1;i<=amount;i++){
        for(int j=0;j<nums.size();j++){
            if(i>= nums[j]){
                dp[i] = min(dp[i],1+dp[i-nums[j]]);
            }
        }
    }
    return (dp[amount] == amount+1 )?-1:dp[amount];
}
int main(){
    vector<int> nums({1,2,3});
    int amount = 10;
    cout<<coinChange(nums,amount)<<endl;
    return 0;
}