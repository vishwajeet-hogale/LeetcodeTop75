#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void perm(string s,int i,int n){
    if(i==n)
    {
        cout<<s<<endl;
        return;
    }
    for(int j=i;j<n;j++){
        swap(s[i],s[j]);
        perm(s,i+1,n);
        swap(s[i],s[j]);
    }
}
int main(){
    string s= "ABCD";
    perm(s,0,s.length());
    return 0;
}