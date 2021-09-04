#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void printAllSubstrings(string curr,string str,int index,int n)
{
    if(index == n)
        return;
    if(!curr.empty()){
        cout<<curr<<endl;
        // return;
    }
    for(int i=index+1;i<n;i++){
        curr += str[i];
        printAllSubstrings(curr,str,i,n);
        curr = curr.erase(curr.size()-1);
    }
    return;
}
int main(){
    string s = "Vishwajeet";
    string curr ="";
    printAllSubstrings(curr,s,0,s.length());
    return 0;
}