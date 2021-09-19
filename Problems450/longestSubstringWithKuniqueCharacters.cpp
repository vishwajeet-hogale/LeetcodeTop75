#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int longestSubstringUnique(string s,int k){
    int i =0;
    int mx = INT_MIN;
    int j = 0;
    int n = s.length();
    unordered_map<char,int> m;
    while(j<n){
        m[s[j]]++;
        if(m.size()<k)
            j++;
        else if(m.size() == k){
            mx = max(mx,j-i+1);
            
            j++;
        }
        else{
            while(m.size()>k){
                m[s[i]]--;
                if(m[s[i]] == 0){
                    m.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return mx;
}
int main(){
    string s = "aabacbebabe";
    cout<<longestSubstringUnique(s,3)<<endl;
    return 0;
}