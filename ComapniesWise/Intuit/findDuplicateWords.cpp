#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

vector<string> getAllWords(string s){
    string s1 = "";vector<string> str;
    for(char c:s){
        if(c == ' '){
            cout<<s1<<endl;
            str.push_back(s1);
            s1 = "";
        }
        else
            s1 += c;
    }
    str.push_back(s1);
    return str;
}
vector<string> getDuplicates(string s){
    vector<string> res;
    vector<string> str = getAllWords(s);
    map<string,int> m;
    for(string g:str){
        
        if(m.find(g) == m.end())
            m[g] = 1;
        else{
            m[g]++;
            if(m[g]>1 ){
                res.push_back(g);
            }
                
        }
    }
    return res;
}
int main(){
    string s = "The boat is the ez boat";
    transform(s.begin(),s.end(),s.begin(),::tolower);
    vector<string> res =getDuplicates(s);
    for(string g:res)
        cout<<g<<",";
    cout<<endl;
    return 0;
}