#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countFriendsPairings(int n) 
{ 
    // code here
    // if(n<=2)
    //     return n;
    // int ans = 0;
    // ans += countFriendsPairings(n-1) + (n-1)*countFriendsPairings(n-2);
    // return ans % 1000000007;
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[0] = 0;
    dp[2] = 2;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1]%1000000007 + ((i-1)%1000000007)*dp[i-2]%1000000007;
    }
    return dp[n]%1000000007;
}
int main(){
    cout<<countFriendsPairings(6569)<<endl;
    return 0;
}