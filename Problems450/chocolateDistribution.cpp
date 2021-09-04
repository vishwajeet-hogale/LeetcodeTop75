#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long findMinDiff(vector<long long> arr, long long n, long long m){
    //code
        int mi = INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0;i+m-1<n;i++){
            int d = arr[i+m-1]-arr[i];
            if(d<mi)
                mi = d;
        }
        return mi;
    } 