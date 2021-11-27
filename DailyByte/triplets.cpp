#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> tripletsSumToZero(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    for(int i =0;i<n-1;i++){
        int l = i+1;
        int r = n-1;
        while(l<r){
            int sum = nums[i] + nums[l] + nums[r];
            if(sum == 0){
                res.push_back({nums[i],nums[l],nums[r]});
                l++;
                r--;
            }
            else if(sum > 0){
                r--;
            }
            else {
                l++;
            }
        }
    }
    return res;
}
int main(){
    vector<int> nums({0, -1, 1, 1, 2, -2});
    vector<vector<int>> res = tripletsSumToZero(nums);
    for(auto i:res){
        for(int j:i){
            cout<<j<<",";
        }
        cout<<endl;
    }
    return 0;

}