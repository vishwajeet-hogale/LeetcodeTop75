#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findElement(int arr[],int n){
    int left[n],right[n];
    left[0] = INT_MIN;
    right[n-1] = INT_MAX;
    for(int i=0;i<n-1;i++){
        left[i+1] = max(arr[i],left[i]);
    }
    for(int i=n-1;i>0;i--){
        right[i-1] = min(right[i],arr[i]);
    }
    for(int i =1;i<n-1;i++){
        if(left[i]<=arr[i] && right[i]>=arr[i])
            return arr[i];
    }
    return -1;
}

