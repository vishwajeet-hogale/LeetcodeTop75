#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string reverseString(string s){
    int start = 0;
    int end = s.length()-1;
    while(start<end){
        char c = s[start];
        s[start] = s[end];
        s[end] = c;
        start++;
        end--;
    }
    return s;

}
int main(){
    string s = "vishwa";
    cout<<reverseString(s)<<endl;
    return 0;
}