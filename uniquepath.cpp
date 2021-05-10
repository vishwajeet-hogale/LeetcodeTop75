#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[401][401];
int checkValid(int row,int col,int m,int n){
        if(row<m && col<n){
            return 1;
        }
        else{
            return 0;
        }
    }
    int checkEnd(int row,int col,int m,int n){
        if(row == m-1 && col == n-1){
            return 1;
        }
        return 0;
    }
    int getPaths(int row,int col,int m,int n){
        if(dp[row][col] != 0){
            return dp[row][col];
        }
        if(!checkValid(row,col,m,n)){
            return 0;
        }
        if(checkEnd(row,col,m,n)){
            return 1;
        }
        else{
        
            dp[row][col] = getPaths(row+1,col,m,n) + getPaths(row,col+1,m,n);
        }
        return dp[row][col];
    }
    int uniquePaths(int m, int n) {
        
        memset(dp,0,sizeof(dp));
        return getPaths(0,0,m,n);
    }
int main(){

    cout<<uniquePaths(23,12)<<endl;
    return 0;
}