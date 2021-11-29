#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int check(vector<int> &b1,vector<int> &b2,vector<int> &fruits,int i,int N,int f){
    if(i == N)
        return true;
    if(find(b1.begin(),b1.end(),fruits[i]) != b1.end() && f == 1)
        return false;
    if(find(b2.begin(),b2.end(),fruits[i]) != b2.end() && f == 0)
        return false;
    b1.push_back(fruits[i]);
    int option1 = check(b1,b2,fruits,i+1,N,1);
    b1.pop_back();
    b2.push_back(fruits[i]);
    int option2 = check(b1,b2,fruits,i+1,N,0);
    b2.pop_back();
    return option1 || option2;
}
int main(){
    vector<int> b1,b2;
    vector<int> fruits({1,1,2});
    int res = check(b1,b2,fruits,0,fruits.size(),1)||check(b1,b2,fruits,0,fruits.size(),0);
    cout<<res<<endl;
    return 0;
}