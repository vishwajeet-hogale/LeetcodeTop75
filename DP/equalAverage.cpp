#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int check(int sum,vector<int> &nums,vector<int> &temp,int i,int n,int N){
    if( i >=N){
        return 0;
    }
    if(n == 0)
        return sum==0;
    
    if(nums[i]<=sum){
        temp.push_back(nums[i]);
        if(check(sum-nums[i],nums,temp,i+1,n-1,N))
            return 1;
        temp.pop_back();
    }
    if(check(sum,nums,temp,i+1,n,N))
        return true;
    return false;
}
int main(){
    vector<int> nums({1,7,15,29,11,9});
    int sum = 0;
    for(int i:nums)
        sum += i;
    int N = nums.size();
    for(int i=1;i<=N-1;i++){
        if(sum*i % N == 0){
            int val = sum *i / N;
            vector<int> temp;
            if(check(val,nums,temp,0,i,N)){
                for(int i:temp)
                    cout<<i<<",";
                cout<<endl;
            }
        }
    }
    return 0;
}