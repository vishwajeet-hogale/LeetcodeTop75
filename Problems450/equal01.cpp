#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int balancedStrings(string s){
    int i=0,j=0;int bal = 0;
    for(char c:s){
        bal += (c == '0')?-1:1;
        if(bal == 0){
            j++;
        }
    }
    return j;
}
int main(){
    string s = "00110101010101";
    cout<<balancedStrings(s)<<endl;
    return 0;
}