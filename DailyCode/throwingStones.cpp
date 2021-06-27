#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int throwingStones(vector<int> &nums){
    int n = nums.size()-1;
    while(nums.size()!=2){
        int last = nums[n];
        int second_last = nums[n-1];
        nums.pop_back();
        nums.pop_back();
        if(last == second_last)
            continue;
        if(last > second_last){
            last -= min(last,second_last);
            nums.push_back(last);
        }
        else{
            second_last -= min(last,second_last);
            nums.push_back(second_last);
        }
        n--;
    }
    return max(nums[0],nums[1])-min(nums[0],nums[1]);
}
int main(){
    
    vector<int> nums({1,2,3,4});
    sort(nums.begin(),nums.end());
    cout<<throwingStones(nums)<<endl;
    return 0;
}