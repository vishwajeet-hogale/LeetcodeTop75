#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findNumberOfWays(string s){
    string str = "programming";
    int dp[1001][1001] ={0};
    int m = s.length();
    int n = str.length();
    // cout<<1<<endl;
    for(int i =0;i<=m;i++){
        dp[i][0] = 1;
    }
    for(int j =0;j<=n;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j =1;j<=n;j++){
            if(s[i-1]==str[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
                cout<<dp[i][j]<<endl;
            }
        }
    }
    // cout<<dp[m][n];
    return dp[m][n];
}
int main(){
    string s = "rammingabcprogrammingdefprog";
    // cin>>s;
    int res = findNumberOfWays(s);
    cout<<res<<endl;
    return 0;
}