#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
bool checkPal(string s){
        string str = s;
        reverse(s.begin(),s.end());
        if(str.compare(s) == 0){
            return true;
        }
        return false;
    }
    int countSubstrings(string s) {
        int c =0;
        for(int i=0;i<s.length();i++){
            for(int j =1; j<=s.length()-i;j++){
                string str = s.substr(i,j);
                if(checkPal(str)){
                    cout<<str<<endl;
                    
                    c++;
                }
            }
        }
        return c;
    }

int main(){
    string s = "abaabac";
    cout<<countSubstrings(s)<<endl;
    return 0;
}