#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void maxMin(vector<int> nums,int k){
    int ma = INT_MIN,mi = INT_MAX;
    sort(nums.begin(),nums.end());
    ma = nums[nums.size()-k];
    mi = nums[k-1];
    cout<<ma<<":"<<mi<<endl;
}
int main(){
    vector<int> nums({9,2,3,4,5});
    maxMin(nums,1);
    return 0;
}