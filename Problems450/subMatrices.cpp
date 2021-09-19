#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Valid(int row,int col,vector<vector<int>> &A,vector<vector<int>> &vis,int n,int m){
    if(row<0 || col <0 || row>=n || col >= m || vis[row][col])
        return false;
    return 1;
}
int helper(int row,int col,vector<vector<int>> &A,vector<vector<int>> &vis,int sum,int n,int m,vector<int> temp){
    if(row<0 || col <0 || row>=n || col >= m || vis[row][col])
        return false;
    if(sum == 0){
        for(int i:temp){
            cout<<i<<",";
        }
        cout<<endl;
        return true;
    }
    vis[row][col] = 1;
    vector<int> xdir({1,0,-1,0});
    vector<int> ydir({0,1,0,-1});
    // int res = 0;
    for(int i=0;i<4;i++){
        int new_x = row + xdir[i];
        int new_y = col + ydir[i];
        if(Valid(new_x,new_y,A,vis,3,3)){
            sum += A[new_x][new_y];
            temp.push_back(A[new_x][new_y]);
            if(helper(new_x,new_y,A,vis,sum,n,m,temp))
                return true;
          
            sum -= A[new_x][new_y];
            temp.pop_back();
        }
    }
    vis[row][col] = 0;
    return false;
}
int solve(vector<vector<int> > &A) {
    int c = 0;
    vector<vector<int> > vis(3,vector<int>(3,0));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            vector<int> temp;
            temp.push_back(A[i][j]);
            if(helper(i,j,A,vis,A[i][j],3,3,temp)){
                c++;
            }
        }
    }
    return c;
}
int main(){
    vector<vector<int>> A({{-3,2,3},{-5,7,9},{8,-8,-8}});
    cout<<solve(A)<<endl;
    return 0;
}
