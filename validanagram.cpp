#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t) {
        map<char,int> m,t1;
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
            if(t1.find(c) == t1.end()){
                t1[c] = 1;
            }
            else
                t1[c]++;
        }
        for(char c:s){
            if(m[c] != t1[c])
                return false;
        }
        return true;
    }
int main(){
    string s = "anagram";
    string t = "naagram";
    cout<<isAnagram(s,t)<<endl;
    return 0;
}