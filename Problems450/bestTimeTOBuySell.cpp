#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        
        int m = 0;int g = INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<g)
                g = prices[i];
            else if(prices[i]-g > m)
                m = prices[i]-g;
        }
        return m;
    }