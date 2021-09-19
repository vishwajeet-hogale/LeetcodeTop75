#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int subsetSum(int arr[],int sum,int N){
    vector<vector<int>> dp(101,vector<int>(100001));
    for(int i=0;i<=N;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=sum;j++){
            if(j==0)
                dp[i][j] = 1;
            else if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[N][sum];
}
int equalPartition(int N, int arr[])
{
    // code here
    int sum = 0;
    for(int i=0;i<N;i++){
        sum += arr[i];
    }
    if(sum % 2 == 0){
        return subsetSum(arr,sum/2,N);
    }
    return 0;
}