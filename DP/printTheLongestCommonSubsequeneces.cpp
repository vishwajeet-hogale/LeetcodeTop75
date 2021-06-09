#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int LCS(string x,string y,int i,int j){
    if(i==0 || j==0){
        return 0;
    }
    if(x[i-1] == y[j-1])
        return 1 + LCS(x,y,i-1,j-1);
    return max(LCS(x,y,i-1,j),LCS(x,y,i,j-1));
}
void LCSDP(string x,string y){
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
    string s = "";
    int i = n;
    int j = m;
    while(i>=0 && j>=0){
        
            if(x[i-1] == y[j-1]){
                s.push_back(x[i-1]);
                j--;
                i--;
            }
            else{
                if(dp[j-1][i] > dp[j][i-1])
                    j = j - 1;
                else
                    i = i - 1;
            }
        
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}
int main(){
    LCSDP("acbcf","abcbaf");
    return 0;
}