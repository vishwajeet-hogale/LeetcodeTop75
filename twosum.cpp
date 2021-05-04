#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> r;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int com = target-nums[i];
            
            if(m.find(com) != m.end()){
                
                r.push_back(i);
                r.push_back(m.find(com)->second);
                return r;
            }
            m[nums[i]] = i;
        }
        return r;
    }
int main(){
    cout<<"(";
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(7);

    nums.push_back(10);
    nums.push_back(12);
    nums.push_back(3);
    vector<int> res = twoSum(nums,22);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<",";
    }
    cout<<")"<<endl;
    return 0;
}