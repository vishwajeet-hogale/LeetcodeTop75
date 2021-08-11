#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int maxBricks(vector<int> &bricks,int C){
    C--;
    int dp[bricks.size()+1][C+1];
    for(int i=0;i<=bricks.size();i++){
        for(int j =0;j<=C;j++){
            if(i==0 || j == 0){
                dp[i][j] = 0;
            }
            else if(bricks[i-1] <= j){
                dp[i][j] = max(1+dp[i-1][j-bricks[i-1]],dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
        
    }

    return dp[bricks.size()][C];
}
int getBricks(vector<int> &bricks){
    return maxBricks(bricks,5000);
}
int main(){
    vector<int> bricks({1000, 200, 150, 200});
    cout<<getBricks(bricks)<<endl;
    return 0;
}