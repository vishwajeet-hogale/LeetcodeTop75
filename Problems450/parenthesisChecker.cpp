#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int parenthesisCheck(string s){
    stack<char> st;
    map<char,char> m;
    m[')'] = '(';
    m['}'] = '{';
    m[']'] = '[';
    st.push(s[0]);
    for(int i=1;i<s.length();i++){
        if(s[i] =='(' || s[i]=='{' || s[i] == '[')
            st.push(s[i]);
        else if((s[i]=='}' || s[i]==')' || s[i]==']') && !st.empty()){
            if(m[s[i]] == st.top()){
                st.pop();
            }
            else{
                return 0;
            }
        }
    }
    return st.empty();
}
int main(){
    string s = "([]";
    cout<<parenthesisCheck(s)<<endl;
    return 0;
}