#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> nums,int k,int M){
    int i =0,j=0,sum=0,n=nums.size(),c =0;
    while(j<n){
        sum += nums[j];
        if(j-i+1 <k)
            j++;
        else if(j-i+1 == k){
            int res = sum/k;
            if(res>=M)
                c++;
            sum -= nums[i];
            i++;
            j++;
        }
    }
    return c;
}
int main(){
    vector<int> nums({3, 6, 3, 2, 1, 3, 9});
    int k =2,M = 4;
    cout<<countSubarrays(nums,k,M)<<endl;
    return 0;
}