#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int> > board,
            int row, int col)
{
    int i, j;
    int N = board.size();
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
int dfs(int col,vector<vector<int>> &grid,int n){
    if(col == n){
        cout<<"Solution : "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    int res = 0;
    for(int j=0;j<n;j++){
        if(isSafe(grid,j,col)){
            grid[j][col] = 1;
            res = dfs(col+1,grid,n) || res;
            grid[j][col] = 0;
        }
        
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n,0));
    cout<<dfs(0,grid,n)<<endl;
    return 0;
}