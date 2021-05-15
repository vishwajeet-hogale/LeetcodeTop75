#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int> &nums1,vector<int> &nums2){
    
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    vector<int>ans;
    vector<int>visited(1001,0);
    int i=0;
    int j=0;
    while(i<nums1.size()&&j<nums2.size()){
        if(nums1[i]==nums2[j]){
            if(visited[nums1[i]]==0){
                ans.push_back(nums1[i]);
                visited[nums1[i]]=1;
            }
            i++;j++;
        }
        else if(nums1[i]>nums2[j]){
            j++;
        }
        else{
            i++;
        }
        
        
    }
    return ans;
}
int main(){
    vector<int> num1,num2;
    num1.push_back(1);
    num1.push_back(2);
    // num1.push_back(2);
    num2.push_back(2);
    num2.push_back(23);
    num2.push_back(3);
    
    vector<int> res = intersection(num1,num2);
    if(res.size())
        for(int &x:res){
            cout<<x<<endl;
        }
    else
        cout<<"Empty"<<endl;
    return 0;
    
    
}