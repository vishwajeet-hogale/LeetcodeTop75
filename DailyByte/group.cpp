#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*  
You are given a list of values and a list of labels. The ith element in labels represents 
the label of the ith element. Similarly, the ith element in values represents the value associated 
with the ith element (i.e. together, an “item” could be thought of as a label and a price). 
Given a list of values, a list of labels, a limit, and wanted, return the sum of the most expensive items you can 
group such that the total number of items used is less than wanted and the number of any given label that is used is less than limit.
*/
int grouping(vector<int> values,vector<int> labels,int wanted ,int limit){
    priority_queue<pair<int,int>> pq;
    unordered_map<int,int> mp;
    for(int i=0;i<labels.size();i++){
        pq.push(make_pair(values[i],labels[i]));
        // mp[labels[i]] = 0;
    }
    int sum = 0;
    while(mp.size()<wanted){
        pair<int,int> top = pq.top();
        // if(mp.find(top.second)!=mp.end()){
        //     if(mp[top.second] < limit){
        //         // cout<<top.second<<endl;
        //         sum += top.first;
        //         mp[top.second]++;
        //         pq.pop();
        //     }
        //     else{
        //         pq.pop();
        //     }
        // }
        // else{
        // cout<<top.second<<endl;
        //     sum += top.first;
        //         mp[top.second]++;
        //         pq.pop();
        // }
        if(mp[top.second] < limit ){
                // cout<<top.second<<endl;
                sum += top.first;
                mp[top.second]++;
                
        }
        pq.pop();
        
        
    }
    return sum;
}
int main(){
    vector<int> values({5,4,3,2,1});
    vector<int> label({1,1,2,2,3});int wanted = 3;int limit = 2;
    cout<<grouping(values,label,wanted,limit)<<endl;
    return 0;
}