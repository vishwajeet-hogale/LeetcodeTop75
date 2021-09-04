#include<iostream>
#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int wordBreak(string s,vector<string> &dict){
    if(s.length() == 0)
        return true;
    if(m.find(s) != m.end()){
        return m[s];
    }
    for(string c:dict){
        int l = c.length();
        string temp = s.substr(0,l);
        if(temp.compare(c) == 0){
            if(wordBreak(s.substr(l),dict)){
                m[s] = 1;
                return true;
            }
        }
    }
    return m[s] = 0;
}