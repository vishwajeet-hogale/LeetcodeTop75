#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> sort1(vector<int> &nums){
    priority_queue<int,vector<int>,greater<int>> even,odd;
    for(int i:nums){
        if(i%2 == 0)
            even.push(i);
        else
            odd.push(i);
    }
    for(int i=0;i<nums.size();i++){
        if(i%2 == 0){
            nums[i] = even.top();
            even.pop();
        }
        else{
            nums[i] = odd.top();
            odd.pop();
        }
    }
    return nums;
}
int main(){
    vector<int> nums({1,2,3,4});
    vector<int> res = sort1(nums);
    for(int i:res)
        cout<<i<<",";
    cout<<endl;
    return 0;
}