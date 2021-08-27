#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int subArrayExists(int arr[],int n){
    int max_end = 0,f=0;
    map<int,int> m;
    for(int i=0;i<n;i++){
        max_end += arr[i];
        if(max_end==0 || m[max_end] || arr[i] ==0){
            f=1;break;
        }
        else 
            m[max_end] =1;
    }
    return f;
}