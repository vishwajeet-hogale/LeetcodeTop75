#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void init(vector<int> &table,string s2){

    int i=0,j=1;
    while(j<s2.length()){
        if(s2[i] == s2[j]){
            table[j] = i+1;
            i++;
            j++;
        }
        else if(s2[i] != s2[j]){
            table[j] = 0;
            j++;
        }

    }
    
}
bool checkForSubstringMatch(vector<int> &table,string s1,string s2){
    int i=0,j=0;
    while(i<s1.length()){
        if(s1[i] == s2[j]){
            j++;
            i++;
        }
        if(j == s2.length()){
            return true;
        }
        else if( i< s1.length() && s1[i] != s2[j]){
            if( j!= 0){
                j = table[j-1];
            }
            else{
                i++;
            }
        }
    }
    return false;
}
int main(){
    string s = "ABABCABAB";
    string s1 = "ABABDABACDABABCABAB";
    vector<int> table(s.size());
    init(table,s);
    cout<<checkForSubstringMatch(table,s1,s)<<endl;
    return 0;
}