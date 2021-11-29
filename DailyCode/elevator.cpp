#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int search(vector<int> nums,int val){
    int i =0;
    int j = nums.size()-1;
    while(i<j){
        int mid = i +(j-i)/2;
        if(nums[mid] == val)
            return mid;
        else if(nums[mid]<val)
            j = mid -1;
        else 
            i = mid+1;
    }
    return -1;
}
void floor(string s,int f,vector<int> nums){
    vector<int> a(nums.begin(),nums.end());
    vector<int> d(nums.begin(),nums.end());
    if(s == "UP"){
        

    }
    if(s == "DN"){
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<f){
                cout<<nums[i];
                m[i] = 1;
            }

        }
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<nums.size();i++){
            if(m[i]==1)
                continue;
            q.push(nums[i]);
        }
        while(!q.empty()){
            cout<<q.top();
            q.pop();
        }

    }
}
int main(){
    string s = "UP";
    int f = 6;
    vector<int> nums({6,1,3,10,7,0,8});
    floor(s,f,nums);
    return 0;
}