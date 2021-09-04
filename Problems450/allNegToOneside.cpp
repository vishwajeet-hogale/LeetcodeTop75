#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// 1,2,-3, 2,-2
vector<int> allNegToOneSide(vector<int> nums){
    map<int,int> m;
    for(int i:nums){
        if(m.find(i)!=m.end())
            m[i]++;
        else
            m[i] = 1;
    }
    int i =0;
    for(auto x:m){
        while(x.second !=0){
            nums[i] = x.first;
            i++;
            x.second--;
        }
    }
    return nums;
}
int main(){
    vector<int> nums({0,-22,2,-2,-1,10});
    vector<int> gg = allNegToOneSide(nums);
    for(int i:gg){
        cout<<i<<endl;
    }
    return 0;
}