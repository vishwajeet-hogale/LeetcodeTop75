#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int> arr){
    vector<int> dp(arr.size(),1);
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<=i;j++){
            if(arr[j]<arr[i] && dp[i] < dp[j]+1)
                dp[i] = dp[j]+1;

        }
    }
    int val = INT_MIN;
    for(int i=0;i<arr.size();i++){
        val = max(val,dp[i]);
    }
    return val;
}