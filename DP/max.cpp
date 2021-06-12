#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max1(vector<int> &arr,int L , int R){
    int j = arr[L] | arr[L+1];
    for(int i=L;i<=R;i++){
        j = j | arr[i];
    }
    cout<<j<<endl;
    return j;
}
int m = 0;
int maxFun(vector<int> &arr1,vector<int> & arr2){
    for(int i=0;i<arr1.size();i++){
        for(int k = i+1;k<arr1.size();i++){
            int x = max1(arr1,i,k) + max1(arr2,i,k);
            if(x > m)
                m = x;
        }
    }
    return m;
}
int main(){
    vector<int> arr1({1,2,4,8});
    vector<int> arr2({1,2,4,8});
    cout<<maxFun(arr1,arr2)<<endl;
    return 0;

}

