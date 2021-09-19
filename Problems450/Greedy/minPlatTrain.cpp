#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minPlatforms(vector<int> arr,vector<int> dept){
    sort(arr.begin(),arr.end());
    sort(dept.begin(),dept.end());
    // int i = 1,j=0;
    int c = 1,n= arr.size();
    for(int i=1;i<n;i++){
        if(arr[i]<=dept[j]){
            c++;
        }
        else{
            j++;
        }
    }
    return c;
}