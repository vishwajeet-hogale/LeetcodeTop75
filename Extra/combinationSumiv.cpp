#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int memo[20001];
int dfs(vector<int> &nums, int sum) {
        if (memo[sum] != -1) {
            return memo[sum];
        }
        if (sum <= 0) {
            return sum == 0;
        }
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum - nums[i] >= 0) {
                result += dfs(nums, sum - nums[i]);
            }
        }
        memo[sum] = result;
        return result;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(memo, -1, sizeof(memo));
        return dfs(nums, target);
    }

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    cout<<combinationSum4(nums,4)<<endl;
    return 0;
}