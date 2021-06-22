#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void getSum(vector<int> &r,vector<int> &nums,int target,int i){
    if(target == 0){
        res.push_back(r);
        return;
    }
    while(i<nums.size() && target-nums[i] >=0){
        r.push_back(nums[i]);
        getSum(r,nums,target-nums[i],i);
        i++;
        r.pop_back();

    }
}
int main(){
    vector<int> nums({2,4,6,3}),r;int target = 6;
    getSum(r,nums,target,0);
    for(vector<int> i:res){
        cout<<"(";
        for(int j:i){
            cout<<j<<",";
        }
        cout<<")"<<endl;
    }
    return 0;
}