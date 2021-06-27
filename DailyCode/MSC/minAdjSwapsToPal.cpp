#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minAdjSwaps(string s){
    int i = 0,j= s.length()-1;
    int swaps = 0,min_val = INT_MAX;
    while(i<j){
        if(s[i]!= s[j]){
            int c = i;
            while(s[c] != s[j] && c<j){
                swap(s[c],s[c+1]);
                c++;
                swaps++;
            }

            
        }
        i++;
        j--;
    }
    cout<<s<<endl;
    return swaps;
}
int main(){
    cout<<minAdjSwaps("mamad")<<endl;
    return 0;
}