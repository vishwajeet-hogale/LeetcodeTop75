#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int dp[401][401];
int knapsack(vector<int> &weights,vector<int> &profits,int capacity,int n){
    if(dp[n][capacity] != 0){
        return dp[n][capacity];
    }
    if(n== 0 || capacity == 0){
        return 0;
    }

    else if(weights[n-1] <= capacity){
        dp[n][capacity] = max(profits[n-1]+knapsack(weights,profits,capacity-weights[n-1],n-1),knapsack(weights,profits,capacity,n-1));
    }
    else if(weights[n-1] > capacity){
        dp[n][capacity] =  knapsack(weights,profits,capacity,n-1);
    }
    // return dp[n][capacity];
}
int main(){
    memset(dp,0,sizeof(dp));
    vector<int> weights,profits;
    weights.push_back(10);
    weights.push_back(20);
    weights.push_back(30);
    // weights.push_back(5);
    profits.push_back(60);
    profits.push_back(100);
    profits.push_back(120);
    // profits.push_back(7);
    cout<<knapsack(weights,profits,50,weights.size())<<endl;
    return 0;
}