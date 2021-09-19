#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    //code here
    vector<int> res;
    priority_queue<int> pr;
    for(int i =0;i<K;i++){
        for(int j:arr[i]){
            cout<<j<endl;
            pr.push(j);
        }
    }
    while(!pr.empty()){
        res.push_back(pr.top());
        pr.pop();
    }
    return res;
}
int main(){
    vector<vector<int>> arr({{1,2,3},{4,5,6},{7,8,9}});
    vector<int> res = mergeKArrays(arr,3);
    return 0;
}