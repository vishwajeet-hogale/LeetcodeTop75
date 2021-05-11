#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int knapsack(vector<int> &weights,vector<int> &profits,int capacity,int n){
    int dp[weights.size()+1][capacity+1];
    for(int i=0;i<=weights.size();i++){
        for(int j =0;j<=capacity;j++){
            if(i==0 || j == 0){
                dp[i][j] = 0;
            }
            else if(weights[i-1] <= j){
                dp[i][j] = max(profits[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
        
    }

    return dp[weights.size()][capacity];
}

int main(){
    // memset(dp,-1,sizeof(dp));
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