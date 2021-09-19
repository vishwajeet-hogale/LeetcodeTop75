#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// {100,180,260,310,40,535,695}
int stockBuySell(vector<int> A, int n){
        // code here
        int b = A[0];
        int profit = 0;int st=0,end = 0;
        int totalProf = 0;
        for(int i=1;i<A.size();i++){
            if(b>A[i]){
                st = i;
                b = A[i];
                totalProf += profit;
                profit = 0;
                
            }
            int pr = A[i]-b;
            if(pr>profit){
                end = i;
                profit = pr;
            }
            
        }
        totalProf += profit;
        return totalProf;
}
int main(){
    cout<<stockBuySell({100,180,260,310,40,535,695},7)<<endl;
    return 0;
}