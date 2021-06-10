#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
/*Approach 
LPS(string x) -> LCS(string x, string reverse(x))
*/
int LPSDP(string x,string y){
    int n = x.length();
    int m = y.length();
    int dp[401][401] = {-1};
    for(int i=0;i<n+1;i++){
        dp[i][0] = 0;
   
    }
    for(int i=1;i<m+1;i++){
        dp[0][i] = 0;
   
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
int main(){
    string x = "axgcbt";
    reverse(x.begin(),x.end());
    string y = x;
    cout<<LPSDP(x,y)<<endl;
    return 0;
}