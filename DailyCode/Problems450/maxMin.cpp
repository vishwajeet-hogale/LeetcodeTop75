#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void maxMin(vector<int> nums){
    int ma = INT_MIN,mi = INT_MAX;
    for(int i=0;i<nums.size();i++){
        ma = max(ma,nums[i]);
        mi = min(mi,nums[i]);
    }
    cout<<ma<<":"<<mi<<endl; 
}
int main(){
    vector<int> nums({1,2,3,4,5});
    maxMin(nums);
    return 0;
}