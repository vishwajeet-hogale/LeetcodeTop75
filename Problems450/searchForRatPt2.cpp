#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int valid(int row,int col, vector<vector<int>> &m,vector<vector<int>> &vis){
    return row>=0 && col >=0 && row<m.size() && col <m[0].size() && m[row][col] && vis[row][col] == 0;
}
vector<string> res;
void dfs(int row,int col,vector<vector<int>> &m,int n,string s,vector<vector<int>> &vis){
    if(!valid(row,col,m,vis))
        return;
    
    if(row == m.size()-1 && col == m[0].size()-1){
        res.push_back(s);
        // cout<<s<<endl;
        // s = "";
        return;
    }
    vis[row][col] = 1;
    if(valid(row+1,col,m,vis)){
        s.push_back('D');
        dfs(row+1,col,m,n,s,vis);
        s.pop_back();
    }
    if(valid(row-1,col,m,vis)){
        s.push_back('T');
        dfs(row-1,col,m,n,s,vis);
        s.pop_back();
    }
    if(valid(row,col+1,m,vis)){
        s.push_back('R');
        dfs(row,col+1,m,n,s,vis);
        s.pop_back();
    }
    if(valid(row,col-1,m,vis)){
        s.push_back('L');
        dfs(row,col-1,m,n,s,vis);
        s.pop_back();
    }
    vis[row][col] = 0;
    
    return;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s = "";
        vector<vector<int>> vis(m.size(),vector<int>(m[0].size(),0));
        dfs(0,0,m,m.size(),s,vis);
        return res;
    }
int main(){
    vector<vector<int>> m({ {1, 0, 0, 0},
                            {1, 1, 0, 1}, 
                            {1, 1, 0, 0},
                            {0, 1, 1, 1}});
    vector<string> re = findPath(m,m.size());
    for(string g : res)
        cout<<g<<endl;
    return 0;
}