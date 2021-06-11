#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph({
    {1,1,0,0},
    {0,1,9,0},
    {0,1,1,0},
    {0,0,0,0}
});
int validPlace(int i,int j,vector<vector<int>> &vis){
    return i>=0 && j>= 0 && i<graph.size() && j<graph[0].size() && (graph[i][j] > 0 && !vis[i][j]);
}
int shortestDistance(vector<vector<int>> &graph){
    int dis = 0;
    vector<vector<int>> vis(graph.size(),vector<int>(graph[0].size(),0));
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));

    vis[0][0] = 1;
    int f = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i<size;i++){
            pair<int,int> m= q.front();
            int row = m.first;
            int col = m.second;
            q.pop();
            cout<<row<<","<<col<<endl;
            if(graph[row][col] == 9){
                f = 1;
                break;
            }
            vector<int> x_vecs({1,0,-1,0});
            vector<int> y_vecs({0,1,0,-1});
            for(int i=0;i<2;i++){
                int next_x = row + x_vecs[i];
                int next_y = col + y_vecs[i];
                if(validPlace(next_x,next_y,vis)){
                    vis[next_x][next_y] = 1;
                    q.push(make_pair(next_x,next_y));
                    
                }
            }
        }
        if(f)
            break;
        dis++;
    }
    return dis;
}
int main(){
    cout<<shortestDistance(graph)<<endl;
    return 0;
}