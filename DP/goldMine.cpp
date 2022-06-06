#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lookup[1000][1000] = {INT_MIN};
int rec(vector<vector<int>> &grid,int i,int j,int n,int m){
    
    if(i == n || j<0 || j == m){
        return 0;
    }
    return grid[i][j] + max(rec(grid,i+1,j-1,n,m),max(rec(grid,i+1,j,n,m),rec(grid,i+1,j+1,n,m)));
    
    
}

int goldmine(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int max_gold = INT_MIN;
    for(int i =0;i<m;i++){
        max_gold = max(max_gold,rec(grid,0,i,n,m));
        // cout<<max_gold<<endl;
    }
    return max_gold;
}

int main(){
    vector<vector<int>> grid({
        {3,2,12,15,10},
        {6,19,7,11,17},
        {8,5,12,32,21},
        {3,20,2,9,7}
    });
    cout<<goldmine(grid)<<endl;
    return 0;
}