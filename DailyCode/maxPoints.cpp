#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
// int maxPoints(vector<int> &nums,int target){
//     int dp[1001][1001] ={-1};
//     int n = nums.size();
    
//     for(int i =0;i<=n;i++){
//         for(int j=0;j<=target;j++){
//             if(j == 0 || i == 0)
//                 dp[i][j] = 0;
//             if(j >= nums[i-1])
//                 dp[i][j] = max(dp[i-1][j],1+dp[i-1][j-nums[i-1]]);
//             else
//                 dp[i][j] = dp[i-1][j];
//         }
//     }
//     return dp[n][target];
// }
int maxPoints(vector<int> &nums,int target){
    sort(nums.begin(),nums.end());
    int l = 0;
    int r = nums.size()-1;
    int score = 0,ans = 0;
    while(r>=l){
        if(target>=nums[l]){
            score += 1;
            
            target -= nums[l];
            l++;
            ans = max(ans,score);
            
        }
        else if(target<nums[l] && score > 0){
            score -= 1;
            
            target += nums[r];
            r--;

        }
        else 
            return ans;
        

    }
    return ans;
}
int main(){
    vector<int> nums({100,150,200});
    int target = 200;
    cout<<maxPoints(nums,target)<<endl;
    return 0;
}