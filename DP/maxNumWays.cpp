#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int SubsetSum(vector<int> &nums,int target,int i,int &max){
    if(target == 0)
    {
        
        return 1;
    }
}
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(5);
    int max;
    vector<int> r;
    cout<<coinChange(nums,max,r,0)<<endl;
    return 0;
}