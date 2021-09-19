#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A) {

    int n = A.size();
    int sum = 0;
    for(int i:A)
        sum += i;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j==0)
                dp[i][j] = 1;
            if(A[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    int mi = INT_MAX;
    if(dp[n][sum]){
        for(int i=0;i<=sum/2;i++){
            if(dp[n][i] ){
                mi = min(mi,abs(2*i-sum));
            }
        }
    }
    return mi;
}
int main(){
    vector<int> A({ 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68, 100, 36, 95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69, 48, 45 });
    cout<<solve(A)<<endl;
    return 0;
}