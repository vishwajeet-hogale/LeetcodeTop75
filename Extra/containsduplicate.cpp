#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
       map<int,int> m; 
       for(int &i:nums){
           m[i] = 1;
         
       } 
      
       for(int &i:nums){
         
           if(m[i] > 1){
               return true;
           }
           m[i] += 1;
       }
       return false;
}
// bool containsDuplicate(vector<int>& nums) {
//        sort(nums.begin(),nums.end());
//        for(int x=0;x<nums.size();){
//            if(nums[x]==nums[x+1]){
//                return true;
//            }
//        }
//        return false;
// }
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    cout<<containsDuplicate(nums)<<endl;
    return 0;
}