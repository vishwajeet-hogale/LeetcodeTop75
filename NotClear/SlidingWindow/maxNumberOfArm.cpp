#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int check(int n){
    int num = n,rev = 0;
    while(n>0){
        int digit = n%10;
        rev += digit * digit * digit;
        n /= 10;
    }
    return num == rev;
}
int maxNumberOfAMNumbers(vector<int> nums,int k){
    int i=0,j=0,c = 0,n = nums.size(), m = INT_MIN;
    while(j<n){
        
        c += check(nums[j]);
        if(c == k)
            return c;
        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 == k){
            m = max(c,m);
            c -= check(nums[i]);
            i++;
            j++;
        }
    }
    return m;
}
int main(){
    vector<int> nums({28, 2, 3, 6, 153, 99, 828, 24});
    int k = 6;
    cout<<maxNumberOfAMNumbers(nums,k)<<endl;
    return 0;
}