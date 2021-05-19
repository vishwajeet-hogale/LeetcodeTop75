#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s){
    int l = 0;
        unordered_map<char,pair<int,int>> m;
        
        while(l<s.length()){
            
            if(m.find(s[l]) != m.end()){
                m[s[l]].first++;
            }
            else{
                m[s[l]] = make_pair(1,l);
            }
            // if(m.find(s[r]) != m.end()){
            //     m[s[r]].first++;
            // }
            // else{
            //     m[s[r]] = make_pair(1,r);
            // }
            l++;
            
        }
        for(char c:s){
            
            if(m[c].first == 1){
                return m[c].second;
            }
        }
        return -1;
}