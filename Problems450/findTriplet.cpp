#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[],int n,int X){
    int f = 0;
    sort(A,A+n);
    for(int i=0;i<n;i++){
        int l =i+1;
        int r = n-1;
        while(l<r){
            if(A[i]+A[l]+A[r] == X)
                return f;
            else if(A[i]+A[l]+A[r] < X)
                l++;
            else 
                r--;
        }
    }
    return false;
}