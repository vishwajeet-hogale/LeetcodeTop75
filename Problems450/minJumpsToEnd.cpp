#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minJumps(vector<int> nums){
    if(!nums[0])
        return -1;
    // int n = nums.size();
    int steps = nums[0];
    int jump = 1;int maxReach = nums[0];
    for(int i=1;i<nums.size();i++){
        if(i==nums.size()-1)
            return jump;
        maxReach = max(maxReach,i+nums[i]);
        steps--;
        if(steps == 0){
            jump++;
            if(i>=maxReach)
                return -1;
            steps = maxReach - i;
        }
    }
    return -1;
}