#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sb(int arr[], int n, int x)
    {
        // Your code goes here   
        int i=0,j=0,c = INT_MAX;
    int sum =0;
    while(i<=j && j<n){
        while(sum<=x && j<n)
            sum += arr[j++];
        while(sum>x && i<j){
            c = min(c,j-i);
            sum -= arr[+i];
            i++;
        }
        
        
    }
    return c;
    }