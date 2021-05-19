#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int jewelsAndStones(string jewels,string stones){
    map<char,int> m;
    for(char c:jewels){
        if(m.find(c) != m.end()){
            m[c]++;
        }
        else{
            m[c] = 1;
        }
    }
    int cnt =0;
    for(char c:stones){
        if(m.find(c) != m.end()){
            if(m[c] > 0){
                cnt++;
                // m[c]--;
            }
        }
    }
    return cnt;
}
int main(){
    string jewels = "Af";
    string stones = "AaaddfFf";
    cout<<jewelsAndStones(jewels,stones)<<endl;
    return 0;
}