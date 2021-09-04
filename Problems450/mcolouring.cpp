#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int safe(int node,vector<vector<int>> graph,vector<int> colour,int n,int col){
    for(int i=0;i<n;i++){
        if(graph[node][i] && colour[i] == col)
            return false;
    }
    return true;
}
int dfs(int i,vector<vector<int>> graph,vector<int> &colour,int n,int m){
    if(i==n)
        return true;
    for(int j=0;j<n;j++){
        if(safe(i,graph,colour,n,j)){
            colour[i] = j;
            if(dfs(i+1,graph,colour,n,m))
                return true;
            colour[i] = 0;
        }
    }
    return false;
}
