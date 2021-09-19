#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>>dp(n,vector<int>(m,INT_MIN));
    dp[0][0]=1;
    for(int j=1;j<m;j++){
        if(dp[0][j-1]==INT_MIN) continue;
        dp[0][j]=A[0][j]>A[0][j-1]?dp[0][j-1]+1:INT_MIN;
    }
    for(int i=1;i<n;i++){
        if(dp[i-1][0]==INT_MIN) continue;
        dp[i][0]=A[i][0]>A[i-1][0]?dp[i-1][0]+1:INT_MIN;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(A[i][j]>A[i][j-1]){
                if(dp[i][j-1]!=INT_MIN)
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
            }
            if(A[i][j]>A[i-1][j]){
                if(dp[i-1][j]!=INT_MIN)
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
            }
        }
    }
    return dp[n-1][m-1]==INT_MIN?-1:dp[n-1][m-1];
}
int main(){
    vector<vector<int>> A({
  {92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68},
  {100, 36, 95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69, 48, 45, 63, 58},
  {38, 60, 24, 42, 30, 79, 17, 36, 91, 43, 89, 7, 41, 43, 65, 49, 47},
  {6, 91, 30, 71, 51, 7, 2, 94, 49, 30, 24, 85, 55, 57, 41, 67, 77},
  {32, 9, 45, 40, 27, 24, 38, 39, 19, 83, 30, 42, 34, 16, 40, 59, 5},
  {31, 78, 7, 74, 87, 22, 46, 25, 73, 71, 30, 78, 74, 98, 13, 87, 91},
  {62, 37, 56, 68, 56, 75, 32, 53, 51, 51, 42, 25, 67, 31, 8, 92, 8},
{38, 58, 88, 54, 84, 46, 10, 10, 59, 22, 89, 23, 47, 7, 31, 14, 69}
});
    cout<<solve(A)<<endl;
    return 0;

}