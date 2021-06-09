#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Approach 
/* 
String 1 : abcde
String 2 : bcdfg
Output :    Insertion = 2
            Deletion = 2 

Find the LCS and count the number of letters missing in string 1 
Deletion = STring 1 - LCS 
Insertion = String 2 - LCS 
*/
int LCS(string x,string y){
    int n = x.length();int m = y.length();
    int dp[n+1][m+1]={-1};
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    
    for(int i=1;i<=m;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
void minNumDeletions(string x,string y){
    int lcs = LCS(x,y);
    cout<<"Insertion : "<<y.length()-lcs<<endl;
    cout<<"Deletion : "<<x.length()-lcs<<endl;
}
int main(){
   minNumDeletions("abcdef","dex");
    return 0;
}