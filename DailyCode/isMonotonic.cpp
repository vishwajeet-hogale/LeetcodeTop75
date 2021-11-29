#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int isMonotonic(vector<int> nums){
    int f1 = 1;
    int n = nums.size();
    for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1]){
            f1 = 0;
            break;
        }
    }
    int f2 = 1;
    for(int i=0;i<n-1;i++){
        if(nums[i]<nums[i+1]){
            f2 = 0;
            break;
        }
    }
    return f1 || f2;
}
int main(){
    vector<int> nums({1,2,3,5,7});
    cout<<isMonotonic(nums)<<endl;
    return 0;
}