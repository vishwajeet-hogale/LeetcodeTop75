#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minEdge(vector<int> minD,vector<vector<int>> &graph,int n,vector<int> &vis){
    int m = INT_MAX;int pos = -1;
    for(int i=0;i<n;i++){
        if(minD[i]<=m && vis[i] == 0){
            m = minD[i];
            pos = i;
        }
    }
    return pos;
}
vector<int> djkstra(vector<vector<int>> &graph,int n){
    vector<int> vis(n,0);
    vector<int> minD(n,INT_MAX);
    minD[0] = 0;
    for(int i=0;i<n-1;i++){
        int u = minEdge(minD,graph,n,vis);
        vis[u] = 1;
        for(int j=0;j<n;j++){
            if(graph[u][j] && !vis[j] && minD[u] + graph[u][j] < minD[j] && minD[u] != INT_MAX){
                minD[j] = minD[u] + graph[u][j];
            }
        }
    }
    return minD;
}
int main(){
    vector<vector<int>> graph({ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } });
    int n = graph.size();
    vector<int> res = djkstra(graph,n);
    for(int i:res)
        cout<<i<<endl;
    return 0;
}