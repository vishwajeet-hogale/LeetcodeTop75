#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//001
int minFlips(string s){
    int f1 =0,f2 =0;
    for(int i=0;i<s.length();i++){
        if( i % 2 == s[i]-'0')
            f1++;
        else 
            f2++;
    }
    return s.length()-max(f1,f2);
}