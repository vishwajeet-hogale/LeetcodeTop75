#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char spotTheDifference(string s,string t){
    map<char,int> m;
    for(char c:s){
        if(m.find(c) != m.end())
            m[c]++;
        else
            m[c]=1;
    }
    for(char c:t){
        if(m[c]){
            m[c]--;
        }
        else{
            return c;
        }
        if(m.find(c) == m.end()){
            return c;
        }
        
    }
    return ' ';
}
int main(){
    string s = "a";
    string t = "aa";
    cout<<spotTheDifference(s,t)<<endl;
    return 0;
}