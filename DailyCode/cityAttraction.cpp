#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int m1 = INT_MIN;
void dfs(int i,int pathSum,int sum,vector<vector<int>> grid,vector<int> b,int n,int max_t,vector<int> &vis){
    cout<<i<<",";
    sum += b[i];
    // vis[i] = 1;
    for(int j=i;j<n;j++){
        if(pathSum+grid[i][j] < max_t && grid[i][j] != 0 ){
            dfs(j,pathSum+grid[i][j],sum,grid,b,n,max_t,vis);
        }
        else{
            m1 = max(m1,sum);
            cout<<endl;
            // return;
        }
    }
}
int cityAttraction(vector<int> beauty,vector<int> u,vector<int> v,vector<int> t,int m,int n,int max_t){
    
    vector<vector<int>> grid(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        grid[u[i]][v[i]] = t[i];
        grid[v[i]][u[i]] = t[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j] <<"    ";

        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        vector<int> vis(n,0);
        vis[0] = 1;
        dfs(i,0,0,grid,beauty,n,max_t,vis);
    }
    return m1;
}
int main(){
    vector<int> beauty({5,10,10,10});
    vector<int> u({0,1,0});
    vector<int> v({1,2,3});
    vector<int> t({10,10,5});
    int max_t = 30;
    int n = 4;
    int m = 3;
    cout<<cityAttraction(beauty,u,v,t,m,n,max_t);
    return 0;
}