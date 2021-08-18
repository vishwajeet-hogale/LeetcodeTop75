#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph({
    {1,1,1},
    {1,1,1},
    {0,0,0}
});
int dfs(vector<vector<int>> &graph,int row,int col){
    if(row<0 || row>= graph.size() || col <0 || col >= graph[0].size() || !graph[row][col])
        return 0;
    graph[row][col] = 0;
    int count = 1;
    count += dfs(graph,row+1,col);
    count += dfs(graph,row-1,col);
    count += dfs(graph,row,col+1);
    count += dfs(graph,row,col-1);
    return count;
}
int maxArea(vector<vector<int>> &graph){
    int m_area = INT_MIN;
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph[0].size();j++){
            if(graph[i][j]){
                m_area = max(m_area,dfs(graph,i,j));
            }
        }
    }
    return m_area;
}
int main(){
    cout<<maxArea(graph)<<endl;
    return 0;
}