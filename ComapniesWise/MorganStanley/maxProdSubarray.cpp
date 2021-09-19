#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxProdSubarray(vector<int> nums){
    int max_so_far = INT_MIN; int prod = 1;
    // int i=0,j=0;
 
        for(int j=0;j<nums.size();j++){
            prod *= nums[j];
            if(prod > max_so_far)
                max_so_far = prod;
            if(prod < max_so_far){
   
                prod = 1;
                // break;
            }
        }
    
    return max_so_far;
}
// 6,-3,-10,2,10
int main(){
    vector<int> nums({{6, -3, -10, 0, 2}});
    cout<<maxProdSubarray(nums)<<endl;
    return 0;
}