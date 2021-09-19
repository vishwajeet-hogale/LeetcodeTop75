#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int countTriplet(int arr[], int n)
{
	    int count = 0;
        sort(arr, arr + n);
        for(int i = n-1; i >= 2; i--){
        int j = 0, k = i-1;
        while(j < k){
        if(arr[j] + arr[k] > arr[i])
        k--;
        else if(arr[j] + arr[k] < arr[i])
        j++;
        else{
        count++;
        j++;
        k--;
        }
        }
        }
        return count;
}