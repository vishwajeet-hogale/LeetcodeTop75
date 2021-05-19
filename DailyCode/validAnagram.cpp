#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t){
    map<char,int> m;
        if(s.length() != t.length()){
            return false;
        }
        for(char c:s){
            if(m.find(c) == m.end()){
                m[c] = 1;
            }
            else
                m[c]++;
        }
        for(char c:t){
            if(m.find(c) != m.end() && m[c] > 0){
                m[c]--;
            }
            
        }
        for(auto &x:m){
            if(x.second > 0)
                return false;
        }
        return true;
}