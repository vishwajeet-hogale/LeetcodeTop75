#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int dp[401][401];
void subsetSum(vector<int> &nums,int target){
    
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=nums.size();i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=target;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=nums.size();i++){
        for(int j=1;j<=target;j++){
            if(j==0){
                dp[i][j] = 1;
            }
            
            if(j>=nums[i-1]){
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
            else if(nums[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    

}
int targetSum(vector<int> &nums,int target){
    int range = 0;
    for(int &i:nums){
        range += i;
    }
    int new_tar =(target+range)/2;
    if(new_tar % 2 == 0){
        subsetSum(nums,new_tar);
        return dp[nums.size()][new_tar];
    }
    return 0;
    
    
    }
    
    

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    // nums.push_back(8);
    
    cout<<targetSum(nums,2)<<endl;
    return 0;

}