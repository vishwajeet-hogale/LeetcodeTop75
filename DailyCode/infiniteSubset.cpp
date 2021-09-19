#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int infinitesubsetcoinchange(vector<int> nums,int target,int i){
    if(target ==0)
        return 1;
    if(i==0)
        return 0;
    if(nums[i-1]<=target){
        return infinitesubsetcoinchange(nums,target-nums[i-1],i) + infinitesubsetcoinchange(nums,target,i-1);
    return infinitesubsetcoinchange(nums,target,i-1); 
    }
}
int main(){
    
}