#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int c =0;
int subSet(vector<int> &nums,int target,int n){
    if(target == 0){
        // c++;
        return 1;
    }
    if(n == 0){
        return 0;
    }
    if(target >= nums[n-1]){
        return subSet(nums,target-nums[n-1],n-1) + subSet(nums,target,n-1);
    }
    else{
        return subSet(nums,target,n-1);
    }
}
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    // nums.push_back(4);
    // nums.push_back(4);
    nums.push_back(8);
    nums.push_back(10);
    cout<<subSet(nums,12,nums.size())<<endl;
    return 0;
}