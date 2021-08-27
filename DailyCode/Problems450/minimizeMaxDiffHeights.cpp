#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);int ma = INT_MIN,mi= INT_MAX;
        int res = arr[n-1]-arr[0];
        for(int i=1;i<=n-1;i++){
            if(arr[i]>=k && arr[n-1] >=k){
            ma = max(arr[i-1]+k,arr[n-1]-k);
            mi = min(arr[i]-k,arr[0]+k);
            res = min(res,ma-mi);
            }
            
        }
        return res;
    }