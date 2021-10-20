#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[401];
    
int money(vector<int>& nums, int i)
{
    if(i>=nums.size())
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    return dp[i]=max(money(nums,i+1),nums[i]+money(nums,i+2));
}
    
    int rob(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=money(nums,0);
        return ans;
    }
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    cout<<rob(nums)<<endl;
    return 0;
}