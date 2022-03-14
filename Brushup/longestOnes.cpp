#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums){
    int start = 0,cnt = 0;
    int m = 0,n = nums.size();
    for(int i=0;i<n;i++){
        
        if(nums[i] ==1)
            cnt++;
        else if(nums[i] == 0 && start==0){
            start++;
            cnt++;
        }
        else if(start == 1 && nums[i]==0){
            start = 0;
            cnt = 0;
        }
        m = max(cnt,m);
        
    }
    return m;
}

int main(){
    vector<int> nums({1,0,1,0,1,1,0,1,1,1,0,1});
    cout<<longestOnes(nums)<<endl;
    return 0;
}