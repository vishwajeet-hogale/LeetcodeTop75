#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph({
    {1, 1, 0, 0, 0},
    {1, 1, 0, 1, 1},
    {0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
});

/* 

Approach : 
Loop through the matrix 
Whenever you encounter a "1", use dfs to check the neighbours at that part of the matrix
Every time the dfs ends and comes out of the stack we can say that we 
found the herd at that place. 
Hence we update a pointer "c" taht keeps track of the number of times DFS ran 
to count the number of herds.

Base problem : Counting number of connected components
*/
int validPlace(int i,int j,vector<vector<int>> &vis){
    return i>=0 && j >=0 && i<graph.size() && j < graph[0].size() && (graph[i][j] == 1 && vis[i][j] == 0);
}
void dfs(int row,int col,vector<vector<int>> &vis){
    if(!validPlace(row,col,vis))
        return;
    vis[row][col] = 1;
    vector<int> x_vecs({1,-1,0,0});
    vector<int> y_vecs({0,0,1,-1});
    for(int i=0;i<4;i++){
        int next_x = row + x_vecs[i];
        int next_y = col + y_vecs[i];
        if(validPlace(next_x,next_y,vis)){
            dfs(next_x,next_y,vis);
        }
    }
    
   
}
int sheepHerds(){
    vector<vector<int>> vis(graph.size(),vector<int>(graph[0].size(),0));
    int c = 0;
    for(int i =0;i<graph.size();i++){
        for(int j = 0;j<graph[0].size();j++){
            if(!vis[i][j] && graph[i][j] == 1){
                c++;
                dfs(i,j,vis);
            }
        }
    }
    return c;
}
int main(){
    cout<<sheepHerds()<<endl;
    return 0;
}