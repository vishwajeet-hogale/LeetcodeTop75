#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string integerToRoman(int n){
    vector<int>numbers({1000,500,100,50,10,6,5,4,1});
    vector<string> romans({"M","D","C","L","X","VI","V","IV","I"});
    string s = "";
    while(n > 0){
        for(int i=0;i<9;i++){
            if(n >= numbers[i]){
                n = n-numbers[i];
                s += romans[i];
                break;
            }
        }
    }
    return s;
}
int main(){
    cout<<integerToRoman(206)<<endl;
    return 0;
}