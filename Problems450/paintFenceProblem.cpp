#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int paintFence(int n,int k){
     int same = k*1;
     int diff = k*(k-1);
     int total = same + diff;
     for(int i = 3;i<=n;i++){
         same = diff*1;
         diff = total*(k-1);
         total = same + diff;

     }
     return total;
}
int main(){
    cout<<paintFence(8,3)<<endl;
    return 0;
}