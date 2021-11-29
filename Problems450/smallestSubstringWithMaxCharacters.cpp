#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int get(string s){
    int i =0,j = 0, n = s.length();
    set<char> s1;
    for(char c:s)
        s1.insert(c);
    int k = s1.size();
    int ans = INT_MAX;
    unordered_map<char,int> m;
    while(j<n){
        m[s[j]] = j;
        if(m.size() < k)
            j++;
        else if(m.size() == k){
            char val = s[i];
            for(auto x:m){
                if(x.first == val)
                    i = x.second;
            }
            ans = min(ans,j-i+1);
            j++;
        }
        
    }
    return ans;
}
int main(){
    string s = "AABBBCBBA";
    cout<<get(s)<<endl;
    return 0;
}