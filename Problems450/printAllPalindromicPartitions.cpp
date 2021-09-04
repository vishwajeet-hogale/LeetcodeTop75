#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int isPalindrome(string s){
    int i = 0;
    int j = s.length()-1;
    while(i<=j){
        if(s[i] != s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
vector<vector<string>> res;
void helper(string s,string temp){
    if(s.length() == 0){
        cout<<temp<<endl;
        return;
    }

    
    for(int j=0;j<s.length();j++){
        string prf = s.substr(0,j+1);
        string ros = s.substr(j+1);
        if(isPalindrome(prf)==1){
        
            helper(ros,temp+"("+prf+")");
      
        }
    }
}
int main(){
    string s = "nitin";
    string temp;
    helper(s,temp);
    return 0;
}