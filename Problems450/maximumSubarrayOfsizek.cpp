#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxSubarray(vector<int> &arr,int k){
    int i =0;
    int j = 0;
    int sum = 0;
    int m = INT_MIN;
    while(j<arr.size()){
        sum += arr[j];
        if(j-i+1<k){
            
            // m = max(m,sum);
            j++;
            
        }
        
        else if(j-i+1==k){
            m = max(m,sum);
            sum -= arr[i];
            i++;
            j++;
        }
        
        
    }
    return m;
}
int main(){
    vector<int> arr({1, 2, 3, 1, 4, 5, 2, 3, 8});
    cout<<maxSubarray(arr,3)<<endl;
    return 0;
}