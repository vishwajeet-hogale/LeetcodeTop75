#include<iostream>
#include<bits/stdc++.h>       
using namespace std;
int check(vector<int> nums,int target, int i){
    if(target<=0){
        return target == 0;
    }
    if(i == 0)
        return 0;
    if(target >= nums[i-1]){
        return check(nums,target-nums[i-1],i) || check(nums,target,i-1);
    }
    else if(target < nums[i-1]){
        return check(nums,target,i-1);
    }
}
int main(){
    vector<int> nums({4,5});
    cout<<check(nums,100,2)<<endl;
    return 0;
}









