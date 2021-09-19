#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dfs(int i,int n,int k,vector<int> &vis,vector<int> &path,vector<vector<int>> &graph){
    if(k<0)
        return true;
    vis[i] = 1;
    cout<<i<<endl;
    for(int j=0;j<n;j++){
        if(path[j] == 1)
            continue;
        if(graph[i][j] && !vis[j]){
            if(graph[i][j]>=k){
                cout<<j<<endl;
                return true;
            }
            path[j] = 1;
            if(dfs(j,n,k-graph[i][j],vis,path,graph))
                return true;
            path[j] = 0;
        }
    }
    vis[i] = 0;
    return false;
}
int main(){
    vector<vector<int>> graph({{0,2,0,6},
                               {0,0,5,0},
                               {0,0,0,0},
                               {0,0,0,0}});
    vector<int> path(4,0);
    vector<int> vis(4,0);
    cout<<dfs(0,4,7,vis,path,graph)<<endl;
    return 0;
}