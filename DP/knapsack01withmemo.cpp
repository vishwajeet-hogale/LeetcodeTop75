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
        dp[n][capacity] = max(profits[n]+knapsack(weights,profits,capacity-weights[n],n-1),knapsack(weights,profits,capacity,n-1));
    }
    else if(weights[n] > capacity){
        dp[n][capacity] =  knapsack(weights,profits,capacity,n-1);
    }
    // return dp[n][capacity];
}
int main(){
    memset(dp,0,sizeof(dp));
    vector<int> weights,profits;
    weights.push_back(1);
    weights.push_back(3);
    weights.push_back(4);
    weights.push_back(5);
    profits.push_back(5);
    profits.push_back(6);
    profits.push_back(2);
    profits.push_back(7);
    cout<<knapsack(weights,profits,9,weights.size()-1)<<endl;
    return 0;
}