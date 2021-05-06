#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
void findNumbers(vector<int> &coins,vector<int> &r,int target,int i,int &min){
    // if(target <0){
    //     return;
    // }
    if(target == 0){
        if(min>=r.size()){
            min = r.size();
        }
        cout<<"(";
        for(int &x:r){
            cout<<x<<",";
        }
        cout<<")"<<endl;
        
        return;
    }
    while(i<coins.size() && target-coins[i]>=0){
            r.push_back(coins[i]);
            findNumbers(coins,r,target-coins[i],i,min);
            i++;
            r.pop_back();
        }
}
int coinChange(vector<int>& coins, int amount) {
        vector<int> r;
        int min = amount+1;
        findNumbers(coins,r,amount,0,min);
        
        return min;
        
    }
int main(){
    vector<int> coins;
    coins.push_back(195);
    coins.push_back(265);
    coins.push_back(404);
    coins.push_back(396);
    cout<<coinChange(coins,11)<<endl;
    return 0;
    
}