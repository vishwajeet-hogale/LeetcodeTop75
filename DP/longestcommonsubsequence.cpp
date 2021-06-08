#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
// int longestSubsequence(string x,string y,int i,int j){
//     if(i == 0 || j == 0){
//         return 0;
//     }
//     if(x[i-1] == y[j-1]){
        
//         return 1 + longestSubsequence(x,y,i-1,j-1);
//     }
    
//     return max(longestSubsequence(x,y,i-1,j),longestSubsequence(x,y,i,j-1)) ;

// }
int longestSubsequence(string x,string y,int i,int j){
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
    return dp[x.length()][y.length()];

}
int main(){
    string x = "abedfhxxxr",y = "abcdxh";
    cout<<longestSubsequence(x,y,x.length(),y.length())<<endl;
    return 0;
}