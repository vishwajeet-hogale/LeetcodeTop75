#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int helper(vector<int> &a,int start,int end){
    if((end-start+1) <= 1){
        return end-start+1;
    }
    for(int i=start;i<=end-1;i++){
        if(abs(a[i+1]-a[i]) != 1){
           
            return max(helper(a,i+1,end),helper(a,start,i));
        }
    }
    return (end-start+1);
}
int findMaxGroupSize(vector<int> &a){
    int start =0,end = a.size()-1;
    sort(a.begin(),a.end());
    return helper(a,start,end);
}
int main(){
    vector<int> a({1,2,3,-2,-1,0});
    cout<<findMaxGroupSize(a)<<endl;
    return 0;
}