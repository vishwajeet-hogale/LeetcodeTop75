#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<string> getList(string s1){
    vector<string> res;
    string w = "";
    for (auto x : s1) 
    {
        if (x == ' ')
        {
            res.push_back(w);
            w = "";
        }
        else {
            w = w + x;
        }
    }
     res.push_back(w);
    return res;
}
vector<string> unCommon(string s1,string s2){
    vector<string> str1 = getList(s1);
    vector<string> str2 = getList(s2);
    vector<string> res;
    int i=0,j=0;
    while(i<str1.size() && j<str2.size()){
        if(str1[i] != str2[j]){
            res.push_back(str1[i]);
            res.push_back(str2[j]);
        }
        i++;
        j++;
    }
    if(i < str1.size()){
        for(int x=i+1;i<str1.size();x++){
            res.push_back(str1[x]);
        }
    }
    else if(j < str2.size()){
        for(int x=j+1;i<str2.size();x++){
            res.push_back(str2[x]);
        }
    }
    return res;
}

int main(){
    string s1 = "Quick Fox";
    string s2 ="Brown Sheep";
    vector<string> res = unCommon(s1,s2);
    for(string &x:res){
        cout<<x<<endl;
    }
    return 0;

}