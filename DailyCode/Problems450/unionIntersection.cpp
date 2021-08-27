#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int unionIntersection(vector<int> arr1,vector<int> arr2){
    map<int,int> m1,m2;
    int n = arr1.size(),m = arr2.size();
    while(n!=0 && m!=0){
        if(m1.find(arr1[n-1])!=m1.end())
            m1[arr1[n-1]]++;
        else
            m1[arr1[n-1]] = 1;
        if(m2.find(arr2[n-1])!=m1.end())
            m2[arr1[m-1]]++;
        else
            m1[arr1[n-1]] = 1;
    }
}