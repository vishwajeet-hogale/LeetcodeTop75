#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Kadane's algorithm
int maxSubarray(vector<int> arr){
    int max_so_far = INT_MIN,max_end = 0;
    for(int i=0;i<arr.size();i++){
        max_so_far = max_so_far + arr[i];
        if(max_so_far < max_end)
            max_so_far = max_end;
        if(max_end < 0)
            max_end = 0;
        
    }
    return max_so_far;
}