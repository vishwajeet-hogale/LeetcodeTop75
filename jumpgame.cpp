#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
bool canJump(vector<int> &nums){
    int reached = 0;
    for(int i = 0;i<nums.size();i++){
        if(reached < i){
            return false;
        }
        reached = max(reached,nums[i]+i);
    }
    return true;
}
int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(4);
    cout<<canJump(nums)<<endl;
    return 0;
}