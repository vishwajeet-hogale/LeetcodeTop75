#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int wanderingTraveller(string s){
    int ver = 0,hor = 0;
    for(char c:s){
        if(c == 'N')
            ver++;
        else if(c=='S')
            ver--;
        else if(c == 'E')
            hor++;
        else 
            hor--;
        if(hor != 0 && ver != 0)
            return 0;
        else
            break
    }
    
    return 1;
}
int main(){
    string s = "NE";
    cout<<wanderingTraveller(s)<<endl;
    return 0;
}