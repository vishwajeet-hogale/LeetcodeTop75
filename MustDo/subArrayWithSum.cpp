#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> &arr,int s,int n){
    int sum = arr[0];
        int low =0;
        int high = 0;
        while(low<n && high <n){
            if(sum ==s)
                return {low+1,high+1};
            else if(sum<s){
                high++;
                sum += arr[high];
            }
            else if(sum>s){
                sum -= arr[low];
                low++;
            }
        }
        return {-1};

}