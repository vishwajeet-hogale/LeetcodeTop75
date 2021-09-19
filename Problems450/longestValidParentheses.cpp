#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int valid(string s){
    stack<char> st;
    for(char c:s){
        if(c == '('){
            st.push(c);
        }
        else if(c==')' && !st.empty()){
            if(st.top() == '(')
                st.pop();
        }
        else
            return 0;
    }
    return s.empty();
}
// int m = INT_MIN;
void helper(string s,int &m){
    if(valid(s)){
        int size = s.length();
        cout<<s<<endl;
        m = max(m,size);
        // return;
    }
    for(int i=1;i<=s.length();i++){
        string prf = s.substr(0,i);
        string ros = s.substr(i);
        
    }
}
int longestValidParentheses(string s){
    int m = INT_MIN;
    helper(s,m);
    cout<<m<<endl;
    return m;    
}
int main(){
    string s = "(()";
    cout<<longestValidParentheses(s)<<endl;
    return 0;
}