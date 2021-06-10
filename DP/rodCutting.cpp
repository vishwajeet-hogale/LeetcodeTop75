#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int rodCutting(vector<int>&length,vector<int>&profit,int target){
    int dp[length.size()+1][target+1];
    int n = length.size();
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(j == 0 || i == 0)
                dp[i][j] = 0;
            else if(j>=length[i-1]){
                dp[i][j] = max(profit[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}
int main(){
    vector<int> length({1,2,3,4,5,6,7,8});
    vector<int> profit({1,5,8,9,10,17,17,20});
    int target = 8;
    cout<<rodCutting(length,profit,target)<<endl;
    return 0;

}