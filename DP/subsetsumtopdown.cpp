#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[401][401];

bool getSubset(vector<int> &nums,int target, int i){
    
    for(int i=0;i<=nums.size();i++){
        dp[i][0] = 1;
    }
    
    for(int i=1;i<=target;i++){
        dp[0][i] = 0;
    }
    for(int i =1;i<=nums.size();i++){
        for(int j=1;j<=target;j++){
            
            if(j == 0){
                dp[i][j] = 1;
            }
            else if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[nums.size()][target];
}
bool subsetSum(vector<int> &nums,int target){
    memset(dp,-1,sizeof(dp));
    
    return getSubset(nums,target,nums.size());

}
int main(){
    vector<int> nums;
    nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(3);
    nums.push_back(5);
    cout<<subsetSum(nums,8)<<endl;
    return 0;
}