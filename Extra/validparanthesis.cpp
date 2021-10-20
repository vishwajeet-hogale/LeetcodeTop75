#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
       stack<char> stac;
    for(char c:s){
        if(c == '(')
            stac.push(')');
        else if(c == '{')
            stac.push('}');
        else if(c == '['){
            stac.push(']');
        }
        else if(c == ')' && !stac.empty()){
            char h = stac.top();
            if(c != h){
                return false;
            }
            stac.pop();
        }
        else if(c == '}' && !stac.empty()){
            char h = stac.top();
            if(c != h){
                return false;
            }
            stac.pop();
        }
        else if(c == ']' && !stac.empty()){
            char h = stac.top();
            if(c != h){
                return false;
            }
            stac.pop();
        }
        else{
            return false;
        }
    }
    return stac.empty(); 
}
int main(){
    string s = "(())[{()}]";
    cout<<isValid(s)<<endl;
    return 0;
}