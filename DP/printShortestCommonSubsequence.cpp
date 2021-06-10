#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printSCS(string x,string y){
    int n =  x.length();
    int m = y.length();
    int dp[n+1][m+1];
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
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i =n;
    int j = m;
    string s = "";
    while(i>=0 || j>=0){
        if(x[i-1]==y[j-1]){
            s += x[i-1];
            i--;
            j--;
        }
        else{
            
            
            if(dp[i-1][j] > dp[i][j-1]){
                s += x[i-1];
                i--;
            }
            else
                s += y[j-1];
                j--;
        }
    }
    while(i>=0)
    {
        s += x[i-1];
        i--;
    }
    while(j>=0)
    {
        s += y[j-1];
        j--;
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}
int main(){
    string x = "ACBCF";
    string y = "ABCDAF";
    printSCS(x,y);
    return 0;
}