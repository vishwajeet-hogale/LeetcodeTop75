#include<iostream>
#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int fewestCoins(vector<int> &coins,int amount){
    vector<int> dp(amount+1,amount+1);
    dp[0] = 0;
    for(int i=1;i<=amount;i++){
        for(int j = 0;j<coins.size();j++){
            if(coins[j]<=i){
                dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
            
        }
    }
    return dp[amount];
}
int main(){
    vector<int> coins({20,30,5,12});
    cout<<fewestCoins(coins,400)<<endl;
    return 0;
}