#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int isSafe(vector<vector<char>>& grid,int row,int col,vector<vector<char>>& vis){
    return (row>=0) && (row<grid.size()) && (col >=0) && (col<grid[0].size()) && (grid[row][col] == '1') && !vis[row][col]; 
}
void dfs(vector<vector<char>>& grid,int row,int col,vector<vector<char>>& vis){
    if(row<0 || row>=grid.size() || col<0 || col >= grid[0].size() || vis[row][col] || grid[row][col] == '0')
        return;
    vis[row][col] = 1;
    vector<int> x_dim({0,1,0,-1,1,1,-1,-1});
    vector<int> y_dim({-1,0,1,0,-1,1,1,-1});
    for(int i=0;i<x_dim.size();i++){
        int next_x = row + x_dim[i];
        int next_y = col + y_dim[i];
        if(isSafe(grid,next_x,next_y,vis))
            dfs(grid,next_x,next_y,vis);
    }
    
}
int numIslands(vector<vector<char>>& grid){
    vector<vector<char>> vis(grid.size(),vector<char>(grid[0].size(),0));
    int c = 0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(isSafe(grid,i,j,vis)){
                dfs(grid,i,j,vis);
                c++;
            }
        }
    }
    return c;
}