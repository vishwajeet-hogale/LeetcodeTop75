#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string reverseWordWise(string s){
    int start = 0;
    string s1= "";
    stack<string> s2;
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            s2.push(s1);
            s1 = "";
        }
        else
            s1 += s[i];
    }
    s2.push(s1);
    string new_string = "";
    while(!s2.empty()){
        new_string += s2.top()+' ';
        s2.pop();
    }
    return new_string;
}
int main(){
    cout<<reverseWordWise("I like this program very much")<<endl;
    return 0;
}