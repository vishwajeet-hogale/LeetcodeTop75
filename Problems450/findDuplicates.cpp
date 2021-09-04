#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(int i:nums){
            if(m.find(i)!=m.end()){
                m[i]++;
            }
            else
                m[i] = 1;
        }
        for(auto x:m){
            if(x.second >1){
                return x.first;
            }
        }
        return -1;
    }