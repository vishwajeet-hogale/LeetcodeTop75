#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums,int target){
    map<int,int> m;
    vector<int> res;
    for(int i=0;i<nums.size();i++){
        int diff = target-nums[i];
        if(m.find(diff) != m.end()){
            res.push_back(m[diff]);
            res.push_back(i);
        }
        m[nums[i]] = i;
    }
    return res;
}
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    vector<int> res = twoSum(nums,9);
    cout<<"(";
    for(int &i:res){
        cout<<i<<",";
    }
    cout<<")"<<endl;
    return 0;    
}