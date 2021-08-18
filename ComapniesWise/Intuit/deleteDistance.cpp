#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int distance(string x,string y){
    int dp[401][401] = {-1};
    for(int i=0;i<x.length()+1;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<y.length()+1;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<x.length()+1;i++){
        for(int j=1;j<y.length()+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return x.length()+y.length()-2*dp[x.length()][y.length()];

}
int main(){
    string s ="algo",t = "daily";
    cout<<distance(s,t)<<endl;
    return 0;
}