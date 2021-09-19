#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
map<string,bool> m;
int wordBreak(string s,vector<string> dict){
    if(s.length() == 0)
        return   true;
    if(m.find(s) != m.end())
        return m[s];
    for(string i:dict){
        string s1 = s.substr(0,i.length());
        if(wordBreak(s.substr(i.length()),dict)){
            m[s] = true;
            return true;
        }
    }
    m[s] = false;
    return false;
}