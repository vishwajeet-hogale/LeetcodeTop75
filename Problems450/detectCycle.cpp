#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int f = 0;
void detectCycle(int i,vector<vector<int>> grid,int n,vector<int> &srcPath,vector<int> &vis){
    vis[i] = 1;
    srcPath[i] = 1;
    for(int j=0;j<n;j++){
        if(srcPath[j] == 1 && grid[i][j]){
            f = 1;return;
        }
        else if(!srcPath[j] && grid[i][j]){
             detectCycle(j,grid,n,srcPath,vis);
        }
    }
    srcPath[i] = 0;
    // return false;
}
int cycle(vector<vector<int>> grid){
    // int f = 0;
    for(int i=0;i<grid.size();i++){
        vector<int> vis(grid.size(),0);
        vector<int> srcPath(grid.size(),0);
        detectCycle(i,grid,grid.size(),srcPath,vis);
    }
    return f;
}
int main(){
    vector<vector<int>> grid({{0,1,0,0},{0,0,1,0},{0,0,0,1},{1,0,0,0}});
    cout<<cycle(grid)<<endl;
    return 0;
}