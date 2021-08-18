#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// int minNumberOfJumps(vector<int> &arr){
//     int jumps = 0,currstart = 0,currend=0;
//     for(int i=0;i<arr.size();i++){
//         currend = max(currend,i+arr[i]);
//         if(i==currend){
//             jumps++;
//             currstart = currend;
//         }
//         if(currstart>=n-1)
//             break;
//     }
//     if(currstart<n-1)
//         return -1;
//     return jumps;
// }
// dp approach : Find the minimum jump required to reach each position of the array i 
// bottom up approach
int dpMinJumps(vector<int> &arr){
    vector<int> dp(arr.size(),INT_MAX);
    dp[0] = 0;
    for(int i=1;i<arr.size();i++){
        for(int j = 0;j<i;j++){
            if(dp[j]!=INT_MAX and arr[j]+j >= i){
                if(dp[j]+1<dp[i])
                    dp[i] = dp[j]+1;
            }

        }
    }
    for(int i:dp)
        cout<<dp[i]<<",";
    cout<<endl;
    return dp[arr.size()-1]!=INT_MAX?dp[arr.size()-1]:-1;
}
int main(){
    vector<int> arr({1,4,3,2,6,7});
    cout<<dpMinJumps(arr)<<endl;
    return 0;
}

