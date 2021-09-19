#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int countPairs(vector<int> nums,int sum) // Just counts the number of paairs 
{
    unordered_map<int,int> m;
    for(int i:nums)
        m[i]++;
    int c = 0;
    for(int i:nums){
        if(m.find(sum-i)!=m.end()){
            c += m[sum-i];
        }
        if(sum - i == i)
            c--;
    }
    return c/2;
}
