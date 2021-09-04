#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int maxProduct(int *arr, int n) {
	    // code here
        int prod = arr[0];int max_prod = arr[0],min_prod = arr[0];
        for(int i=0;i<n;i++){
            int choice1 = max_prod*arr[i];
            int choice2 = min_prod * arr[i];
            max_prod = max(arr[i],max(choice1,choice2));
            min_prod = min(arr[i],min(choice1,choice2));
            prod = max(prod,max_prod);
        }
        return prod;
 }