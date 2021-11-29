#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxWindowSum(vector<int> &nums,int k){
    int m = INT_MIN;
    int i =0,n = nums.size();
    int j =0,sum = 0;
    while(j<n){
        sum += nums[j];
        if(j-i+1 <k){
            j++;
        }
        else if(j-i+1 == k){
            m = max(sum,m);
            sum -= nums[i];
            i++;
            j++;
        }
    }
    return m;
}
int main(){
    vector<int> nums({1, 4, 2, 10, 23, 3, 1, 0, 20});
    int k = 4;
    cout<<maxWindowSum(nums,k)<<endl;
    return 0;
}