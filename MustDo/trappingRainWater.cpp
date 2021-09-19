#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int trappingWater(vector<int> nums){
    int n = nums.size();
    if(n<=2)
        return 0;
    vector<int> l(n);

    vector<int> r(n);
    l[0] = 0;
    int lmax = nums[0];
    for(int i=1;i<n;i++){
        l[i] = lmax;
        lmax = max(lmax,nums[i]);
    }
    r[0] = 0;
    int rmax = nums[n-1];
    for(int i=n-2;i>=0;i--){
        r[i] = rmax;
        rmax = max(rmax,nums[i]);
    }
    int wat = 0;
    for(int i=1;i<n-1;i++){
        if(nums[i]<l[i] && nums[i]<r[i])
            wat += min(l[i],r[i]) - nums[i];
    }
    return wat;
}
int main(){

}