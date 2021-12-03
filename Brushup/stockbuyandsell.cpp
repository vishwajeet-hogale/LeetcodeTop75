#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int buysell(vector<int> &arr){
    int prof = 0;int mprice = INT_MAX;
    for(int i=0;i<arr.size();i++){
        mprice = min(mprice,arr[i]);
        prof = max(prof,arr[i]-mprice);
    }

    return prof;
}
int main(){
    vector<int> arr({8, 9, 2, 3, 5, 2, 4});
    cout<<buysell(arr)<<endl;
    return 0;
}