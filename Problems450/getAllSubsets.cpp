#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
void helper(vector<int> A,vector<int> temp,int i,int n){
    res.push_back(temp);
    while(i<n){
        temp.push_back(A[i]);
        helper(A,temp,i+1,n);
        i++;
        temp.pop_back();
    }
}
vector<vector<int> > subsets(vector<int> &A) {
    vector<int> temp;
    sort(A.begin(),A.end());
    helper(A,temp,0,A.size());
    return res;
}
int main(){
    vector<int> arr({1,2,3});
    vector<vector<int>> r = subsets(arr);
    for(vector<int> i:r){
        for(int j:i){
            cout<<j<<",";

        }
        cout<<endl;
    }
    return 0;
}