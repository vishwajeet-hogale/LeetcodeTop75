#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int predictWinnner(vector<int> &nums,int i,int j,int chance){
    if(i>j)
        return 0;
    if(chance == 0)
        return max(nums[i]+predictWinnner(nums,i+1,j,1),nums[j]+predictWinnner(nums,i,j-1,1));
    else
        return min(predictWinnner(nums,i+1,j,0),predictWinnner(nums,i,j-1,0));
}
bool PredictTheWinner(vector<int>& nums){
    long long total = 0;
    int n = nums.size();
    for(int &i:nums)
        total += i;
    int player1 = predictWinnner(nums,0,n-1,0);
    total -= player1;
    cout<<player1<<endl;
    return player1 >= total;
}
int main(){
    vector<int> nums({1,40,50,23,47});
    cout<<PredictTheWinner(nums)<<endl;
    return 0;
}