#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> sortZOT(vector<int> nums){
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
    vector<int> nums({0,2,2,2,1,0});
    vector<int> gg = sortZOT(nums);
    for(int i:gg){
        cout<<i<<endl;
    }
    return 0;
}