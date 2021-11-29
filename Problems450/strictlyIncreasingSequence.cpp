#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int helper(vector<int> &nums,int i,int N){
    if(i == N)
        return 1;
    if(nums[i-1]>nums[i]){
        for(int j =0;j<=nums[i-1];j++){
            int new_val = nums[i-1] - j;
            if(new_val >nums[i-2] && new_val < nums[i]){
                if(helper(nums,i+1,N))
                    return true;
            }
        }
    }
    else
        return helper(nums,i+1,N);
    return 0;
}
string solve(vector<int> &nums){
    int f = helper(nums,2,nums.size());
    if(f)
        return "Yes";
    return "No";
}
int main(){
    vector<int> nums({2,6,21,5});
    cout<<solve(nums)<<endl;
    return 0;
}