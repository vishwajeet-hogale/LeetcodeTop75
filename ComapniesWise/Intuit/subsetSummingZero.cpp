#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsetSummingZero(vector<int> arr){
    int sum = 0;int start = 0,end = 0;
    vector<vector<int>> res;int i =0;
    while(i<arr.size()){
        sum += arr[i];
        end = i;
        if(sum == 0){
            vector<int> a({start,end});
            cout<<start<<","<<end<<endl;
            res.push_back(a);
            start = i;
            end = i;
            
            sum = 0;
            continue;
        }
        i++;
        
    }
    return res;
}

// void cimbi(vector<int> arr,int i,int s,vector<int> &r){
//     if(s == 0){
//         r1.push_back(r);
//         for(int i:r)
//             cout<<i<<",";
//         cout<<endl;
//         return;
//     }
//     while(i<arr.size() && s-arr[i] >=0){
//         r.push_back(arr[i]);
//         cimbi(arr,i,s-arr[i],r);
//         i++;
//         r.pop_back();
//     }
// }
int main(){
    vector<int> arr({1,1,2,2});
    vector<vector<int>> res = subsetSummingZero(arr);
    vector<int> r;
    // sort(arr.begin(),arr.end());
    
    // cimbi(arr,0,10,r);
    return 0;
}