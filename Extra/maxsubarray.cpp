#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>& nums) {
        int max_so_far = INT_MIN;
        int max_ending = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<=max_ending + nums[i]){
                max_ending += nums[i];
            }
            else{
                max_ending = nums[i];
            }
            if(max_so_far < max_ending){
                max_so_far = max_ending;
            }
        }
        return max_so_far;
    }
int main(){
  
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(-1);

    nums.push_back(7);
    nums.push_back(8);

    int res = maxSubArray(nums);
    
    cout<<res<<endl;
    return 0;
}