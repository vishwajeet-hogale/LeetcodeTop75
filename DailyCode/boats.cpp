#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int boatsMin(int limit,vector<int> &nums){
    // sort(nums.begin(),nums.end());
    int i = 0;
    int j = nums.size()-1;
    int c = 0;
    while(i<=j){
        if(nums[i] + nums[j] > limit){
            c++;
            j--;

        }
        else{
        i++;
        j--;
        c++;
        }
        
    }
    return c;
}
int main(){
    vector<int> nums({1,3,5,2});
    int limit = 5;
    cout<<boatsMin(limit,nums)<<endl;
    return 0;
}