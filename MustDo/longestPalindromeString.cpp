#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string LPS(string x,string y){
    int n = x.length(),m=y.length();
    int dp[401][401]={-1};
    for(int i=0;i<n+1;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<m+1;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    string s ="";
    while(i>=0 && j>=0){
        if(x[i-1] == y[j-1]){
            s += x[i];
            i--;
            j--;
            
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else
                j--;
        }
    }
    reverse(s.begin(),s.end());
    return s;
}
string longestPalin (string S) {
        // code here
    string s1 = S;
    reverse(s1.begin(),s1.end());
    return LPS(S,s1);
}
int main(){
    string s = "abbkba";
    cout<<longestPalin(s)<<endl;
    return 0;
}