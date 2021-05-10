#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[401][401];
bool getSubset(vector<int> &nums,int target, int i){
    if(target == 0){
        return true;
    }
    if(i == 0){
        return false;
    }
    if(nums[i] > target){
        return getSubset(nums,target,i-1);
    }
    else{
        return getSubset(nums,target,i-1) || getSubset(nums,target-nums[i],i-1);
    }
}
bool subsetSum(vector<int> &nums,int target){
    memset(dp,0,sizeof(dp));
    
    return getSubset(nums,target,nums.size()-1);

}
int main(){
    vector<int> nums;
    nums.push_back(1);
    // nums.push_back(2);
    nums.push_back(3);
    nums.push_back(5);
    cout<<subsetSum(nums,7)<<endl;
    return 0;
}