#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<vector<int>> &graph,int n,vector<int> &vis,stack<int> &s){
    vis[i] = 1;
    for(int j=0;j<n;j++){
        if(graph[i][j] && !vis[j]){
            dfs(j,graph,n,vis,s);
        }
    }
    s.push(i);
}
int topologicalSort(vector<vector<int>> &graph,int n){
    vector<int> vis(n,0);
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!vis[i])
            dfs(i,graph,n,vis,s);
    }
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
    return 1;
}
int main(){
    vector<vector<int>> graph({{0,0,0,0,0,0},
                               {0,0,0,1,0,0},
                               {0,0,0,1,0,0},
                               {0,0,0,0,0,0},
                               {1,1,0,0,0,0},
                               {1,0,1,0,0,0}});
    cout<<topologicalSort(graph,6)<<endl;
    return 0;
}