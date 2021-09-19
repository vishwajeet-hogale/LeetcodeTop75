#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> candyShop(int candies[],int N,int K){
    sort(candies,candies+N);
    int j = N-1;int smin = 0,smax = 0;
    int i =0 ;
    while(i<=j){
        smin += candies[i];
        i++;
        j = j - K;
    }
    reverse(candies,candies+N);
    i = 0;j= N-1;
    while(i<=j){
        smax += candies[i];
        i++;
        j = j - K;
    }
    return {smin,smax};
}