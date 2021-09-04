#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int nPr(int n, int r)
{
        // code here
        vector<vector<int>> dp(n+1,vector<int>(r+1,0));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=r;j++){
                if(j==0 || i==j)
                    dp[i][j] = 1;
                else{
                    dp[i][j] = (j*dp[i-1][j-1]+dp[i-1][j])%1000000007;
                }
            }
            
        }
        return dp[n][r];
        
}
int main(){
    cout<<nPr(2,1)<<endl;
    return 0;
}