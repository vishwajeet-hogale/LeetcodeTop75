#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int dfs(int i,int j,int M,int N){
    if(i==M-1 && j == N-1)
        return 1;
    if(i<0 || i>=M || j < 0 || j >= N)
        return 0;
    return dfs(i+1,j,M,N) + dfs(i,j+1,M,N);
}
int main(){
    int M = 4,N = 3;
    int res = dfs(0,0,M,N);
    cout<<res<<endl;
    return 0;
}