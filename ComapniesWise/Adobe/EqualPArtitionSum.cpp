#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int helper(vector<int> &ar,int amount){
    int dp[401][401] = {-1};
    for(int i=0;i<ar.size()+1;i++)
        dp[i][0] = 1;
    for(int i=1;i<=amount;i++)
        dp[0][i] = 0;
    for(int i=1;i<=ar.size()+1;i++){
        for(int j=1;j<=amount;j++){
            if(j==0)
                dp[i][j] = 1;
            if(i == 0)
                dp[i][j] = 0;
            if(ar[i-1]>=j)
                dp[i][j] = dp[i-1][j-ar[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[ar.size()][amount];
}
int subsetSum(){
    vector<int> ar({1,6,5,11});
    int s = 0;
    for(int i:ar)
        s += i;
    if(s%2 == 0)
        return helper(ar,s/2);
    return 0;
}
int main(){
    cout<<subsetSum()<<endl;
    return 0;
}