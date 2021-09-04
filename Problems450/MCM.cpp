#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int matrixChainOrder(int p[],int i,int j){
    if( i>= j) return 0;
    int te= INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp = matrixChainOrder(p,i,k) + matrixChainOrder(p,k+1,j) + p[i-1]*p[k]*p[j];
        te = min(te,temp);
    }
    return te;
}
int main(){
    int p[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(p) / sizeof(p[0]);
    cout<<matrixChainOrder(p,1,n-1)<<endl;
    return 0;
}