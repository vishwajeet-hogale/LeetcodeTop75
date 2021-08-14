#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
vector<vector<int>> graph({
    {0,2,0},
    {8,6,3},
    {0,9,0}
});
class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&graph,int n,int m){
    
    if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || graph[i][j]==0)
        return 0;
    vis[i][j] =1;
    int left =  dfs(i,j-1,vis,graph,n,m);
    int right = dfs(i,j+1,vis,graph,n,m);
    int up = dfs(i-1,j,vis,graph,n,m);
    int down = dfs(i+1,j,vis,graph,n,m);
    vis[i][j] = 0;
    return max(left,max(right,max(up,down)))+ graph[i][j];
}
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       int max_gold = 0;

        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){

                    max_gold = max(max_gold,dfs(i,j,vis,grid,n,m));
                }
            }
        }
        return max_gold;
    }
};
int main(){
    Solution s1;
    cout<<s1.getMaximumGold(graph)<<endl;
    return 0;
}
