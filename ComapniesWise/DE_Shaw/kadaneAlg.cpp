#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[],int n){
    int max_so_far = INT_MIN,max_end = 0;
    for(int i=0;i<n;i++){
        max_end = max_end + arr[i];
        if(max_end > max_so_far)
            max_so_far = max_end;
        if(max_end < 0)
            max_end = 0;

    }
    return max_so_far;
}