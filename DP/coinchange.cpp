#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[401];
int coinChangeSolutions(vector<int> &nums,int target){
    if(dp[target] != -1)
    {
        return dp[target];
    }
    if(target <= 0){
        return target == 0;
    }
    
    int res = 0;
    for(int i =0;i<nums.size();i++){
        if(target - nums[i] >= 0)
            res += coinChangeSolutions(nums,target-nums[i]);
    }
    dp[target] = res;
    return dp[target];
}
int main(){
    memset(dp,-1,sizeof(dp));
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    cout<<coinChangeSolutions(nums,4)<<endl;
    return 0;
}