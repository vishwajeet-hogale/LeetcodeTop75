#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
 string longestPalindrome(string s) {
         int maxLen=1;     //atleast the length of palindrome will 1 or greater than 1
    int start=0,end=0;
    
         //odd length palindromic string
        for(int i=0;i<s.length()-1;i++){
        int l=i,r=i;
        while(l>=0 && r<s.length()){
            if(s[l]==s[r]){
                l--;r++;
            }
            else{
                break;
            }
        }
        int currentLen=r-l-1;
        if(maxLen<currentLen) {start=l+1; end=r-1;}
        maxLen=max(maxLen,currentLen);
        }
    
       //even length palindromic string
    for(int i=0;i<s.length()-1;i++){
        int l=i,r=i+1;
        while(l>=0 && r<s.length()){
            if(s[l]==s[r]){
                l--;r++;
            }
            else{
                break;
            }
        }
        int currentLen=r-l-1;
        if(maxLen<currentLen) {start=l+1; end=r-1;}
        maxLen=max(maxLen,currentLen);
        }
    
    
return s.substr(start,maxLen);
}

int main(){
    string s = "abaabac";
    cout<<longestPalindrome(s)<<endl;
    return 0;
}