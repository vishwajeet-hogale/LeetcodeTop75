#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxAbsDiff(vector<int> nums){
    sort(nums.begin(),nums.end());
    int i = 0;
    int j = nums.size();
    int n = j;
    vector<int> aux;
    j = j-1;
    while(i<j){
        aux.push_back(nums[i]);
        aux.push_back(nums[j]);
        i++;
        j--;
    }
    if(n%2 !=0){
        aux.push_back(nums[n/2]);
    }
    int s = 0;
    for(int i=0;i<n-1;i++){
        s += abs(aux[i]-aux[i+1]);
    }
    s += abs(aux[n-1]-aux[0]);
    return s;
}
int main(){
    vector<int> nums({1,2,4,8});
    cout<<maxAbsDiff(nums)<<endl;
    return 0;
}