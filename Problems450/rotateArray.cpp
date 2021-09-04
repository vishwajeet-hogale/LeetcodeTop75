#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> rotateArray(vector<int> nums){
    int ele = nums[0];
    for(int i=1;i<nums.size();i++){
        nums[i-1] = nums[i];
    }
    nums[nums.size()-1] = ele;
    return nums;
}
int main(){
    vector<int> nums({1,2,4,5,6});
    vector<int> res = rotateArray(nums);
    for(int i:res){
        cout<<i<<",";
    }
    cout<<endl;return 0;
}