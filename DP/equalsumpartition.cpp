#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[201][10000];
bool getSubset(vector<int> &nums,int target, int i){
    if(target == 0){
        return true;
    }
    if(dp[i][target] != -1){
        return dp[i][target];
    }
    if(i == 0){
        return false;
    }
    if(nums[i] > target){
        dp[i][target] = getSubset(nums,target,i-1);
    }
    else{
        dp[i][target] = getSubset(nums,target,i-1) || getSubset(nums,target-nums[i],i-1);
    }
    return dp[i][target];
}
bool subsetSum(vector<int> &nums,int target){
    memset(dp,-1,sizeof(dp));
    
    return getSubset(nums,target,nums.size()-1);

}
bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i =0;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum % 2 !=0){
            return false;
        }
        return subsetSum(nums,sum/2);
}
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(11);
    nums.push_back(5);
    nums.push_back(5);
    cout<<canPartition(nums)<<endl;
    return 0;
}