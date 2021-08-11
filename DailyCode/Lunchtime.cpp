#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
//FD FD FD 
//Sliding window problem
int no_of_meals(string s){
    int i = 0,j=0;
    int c = 0;
    int n = s.length();
    for(int i=0;i<n;i++){
        int f = 0,d=0;
        for(int j = i;j<n;j++){
            cout<<s[j];
            
            if(s[j] == 'F')
                f++;
            else if(s[j]=='D')
                d++;
            if(f == d && f!=0 && d!=0){
                c++;
                cout<<endl;
                i = j;
                break;
            }
            
        }
    }
    return c;

}
int main(){
    string s = "FDFFDFDD";
    cout<<no_of_meals(s)<<endl;
    return 0;
}