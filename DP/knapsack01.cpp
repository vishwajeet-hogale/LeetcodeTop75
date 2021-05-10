#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int knapsack(vector<int> &weights,vector<int> &profits,int capacity,int n){
    if(n== 0 || capacity == 0){
        return 0;
    }
    else if(weights[n-1] <= capacity){
        return max(profits[n-1]+knapsack(weights,profits,capacity-weights[n-1],n-1),knapsack(weights,profits,capacity,n-1));
    }
    else if(weights[n-1] > capacity){
        return knapsack(weights,profits,capacity,n-1);
    }
}
int main(){
    vector<int> weights,profits;
    weights.push_back(1);
    weights.push_back(3);
    weights.push_back(4);
    weights.push_back(5);
    profits.push_back(5);
    profits.push_back(6);
    profits.push_back(2);
    profits.push_back(7);
    cout<<knapsack(weights,profits,9,weights.size())<<endl;
    return 0;
}