#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sumToTarget(vector<int> &arr,int i,int target,vector<int> temp,vector<vector<int>> &res,int n){
    
        // cout<<"1"<<endl;
    if(target == 0){
        res.push_back(temp);
        return;
    }
    if(target <0)
        return;
    while(i<n && target-arr[i]>=0){
    
            temp.push_back(arr[i]);
            sumToTarget(arr,i+1,target-arr[i],temp,res,n);
            i++;
            temp.pop_back();
        
    }

}
int main(){
    vector<int> arr({8, 2, 2, 4, 5, 6, 3});
    int target = 9;
    sort(arr.begin(),arr.end());
    vector<int> temp;vector<vector<int>> res;
    int n = arr.size();
    sumToTarget(arr,0,target,temp,res,n);
    for(auto i:res){
        for(int j:i){
            cout<<j<<",";
        }
        cout<<endl;
    }
    return 0;
}