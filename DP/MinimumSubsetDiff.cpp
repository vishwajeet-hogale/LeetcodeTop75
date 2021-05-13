#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[401][401];

bool SubSet(vector<int> &nums,int target,int i){
    
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
int main(){
  
    memset(dp,-1,sizeof(dp));
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(5);
    nums.push_back(11);
    int range = 0;
    for(int &i:nums){
        range += i;
    }
    
    vector<int> res;
    if(SubSet(nums,range,nums.size())){
        for(int i=0;i<=range;i++){
            if(dp[nums.size()][i] == 1 && i <= range/2){
                // cout<<i<<endl;
                res.push_back(i);
            }
        }
        int min = INT_MAX;
        for(int i=0;i<res.size();i++){
            if(range-2*res[i] < min){
                min = range-2*res[i];
            }
        }
        cout<<min<<endl;
    }
    return 0;

}