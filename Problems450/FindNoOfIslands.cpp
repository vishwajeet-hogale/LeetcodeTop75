#include<iostream>
#include<bits/stdc++.h>
#define COL 501
using namespace std;

void dfs(int row,int col,int M[][COL],int vis[][COL],int n,int m){
    if(row<0 || col <0 || row>=n || col>=m || vis[row][col] || M[row][col] == 0)
        return;
    vis[row][col] = 1;
    dfs(row,col+1,M,vis,n,m);
    dfs(row,col-1,M,vis,n,m);
    dfs(row+1,col,M,vis,n,m);
    dfs(row-1,col,M,vis,n,m);
    dfs(row-1,col+1,M,vis,n,m);
    dfs(row-1,col-1,M,vis,n,m);
    dfs(row+1,col-1,M,vis,n,m);
    dfs(row+1,col+1,M,vis,n,m);
    // vis[row][col] = 0;
    return;
}
int countIslands(int M[][COL], int n, int m) {
    // your code goes here
    int c = 0;
    int vis[][COL] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j] && !vis[i][j]){
                c++;
                dfs(i,j,M,vis,n,m);
            }
        }
    }
    return c;
}