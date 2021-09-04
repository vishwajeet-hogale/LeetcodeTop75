#include<iostream>
#include<bits/stdc++.h>
using namespace  std;

void dfs(int i,vector<int> &vis,vector<vector<int>> grid,int n){
    vis[i] = 1;
    cout<<i<<",";
    for(int j=0;j<n;j++){
        if(!vis[j] && grid[i][j]){
            dfs(j,vis,grid,n);
        }
    }
}
int main(){
    vector<vector<int>> grid({{0,1,1,0},{0,0,1,0},{1,0,0,1},{0,0,0,1}});
    int n = grid.size();
    vector<int> vis(n,0);
    dfs(0,vis,grid,n);
    return 0;
}