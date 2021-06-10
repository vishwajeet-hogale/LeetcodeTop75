#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int>&nums,int target,int i){
    if(target == 0){
        return 1;
    }
  
    if(i==0)
        return  0;
    if(target>=nums[i-1]){
        return coinChange(nums,target-nums[i-1],i-1) + coinChange(nums,target,i-1);
    }

    return coinChange(nums,target,i-1);
    
   
}
int numberOfWaysToMakeChange(int n){
    vector<int> nums;
    for(int i=1;i<n;i++){
        nums.push_back(i);
    }
    return coinChange(nums,n,n-1);
}
int main(){
    cout<<numberOfWaysToMakeChange(10)<<endl;
    return 0;
}