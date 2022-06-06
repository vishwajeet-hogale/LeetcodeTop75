#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,int i,int j,int ls1,int ls2){
    if(i>=ls1 || j >= ls2)
        return 0;
    if(s1[i] == s2[j])
        return 1 + lcs(s1,s2,i+1,j+1,ls1,ls2);
    return max(lcs(s1,s2,i+1,j,ls1,ls2),lcs(s1,s2,i,j+1,ls1,ls2));
}

int SCS(string s1 ,string s2){
    int ls1 = s1.length();
    int ls2 = s2.length();
    return ls1 + ls2 - lcs(s1,s2,0,0,ls1,ls2);
}
int main(){
    string s1 = "abdc";
    string s2 = "bc";
    cout<<SCS(s1,s2)<<endl;
    return 0;
}