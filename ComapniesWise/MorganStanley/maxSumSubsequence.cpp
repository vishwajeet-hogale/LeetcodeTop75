#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxSumInc(vector<int> nums){
    const int size = nums.size();
    int dp[size];
    for(int i=0;i<size;i++){
        dp[i] = nums[i];
    }
    for(int i=1;i<size;i++){
        for(int j=0;j<size;j++){
            if(nums[j]<nums[i] && dp[i] < nums[j]+dp[j]){
                dp[i] = dp[j]+nums[j];
            }
        }
    }
    int m = INT_MIN;
    for(int i=0;i<size;i++){
        m = max(m,dp[i]);
    }
    return m;
}
int main(){
    vector<int> nums({1,2,1,1,11,15,20});
    cout<<maxSumInc(nums)<<endl;
    return 0;
}