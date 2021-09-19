#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int invalid(int row,int col,int n,int m,vector<vector<int>> &vis,vector<vector<int>> &graph){
    return (row<0 || col<0 || row>=n || col >= m || vis[row][col] || !graph[row][col]);
}
int mdis = INT_MIN;
void dfs(int n,int m,int row,int col,int x,int y,vector<vector<int>> &vis,vector<vector<int>> &graph,int dist){
    if(row== x && col == y){
        mdis = max(mdis,dist);
        return;
    }
    vis[row][col] = 1;
    if(!invalid(row,col+1,n,m,vis,graph)){
        dfs(n,m,row,col+1,x,y,vis,graph,dist+1);
    }
    if(!invalid(row,col-1,n,m,vis,graph)){
        dfs(n,m,row,col-1,x,y,vis,graph,dist+1);
    }
    if(!invalid(row+1,col,n,m,vis,graph)){
        dfs(n,m,row+1,col,x,y,vis,graph,dist+1);
    }
    if(!invalid(row-1,col,n,m,vis,graph)){
        dfs(n,m,row-1,col,x,y,vis,graph,dist+1);
    }
    vis[row][col] = 0;
        
}
int main(){
    vector<vector<int>> graph({ { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } });
    int n = graph.size();
    int m = graph[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    dfs(n,m,0,0,1,7,vis,graph,0);
    cout<<mdis<<endl;
    return 0;
}