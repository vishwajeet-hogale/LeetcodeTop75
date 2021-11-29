#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Version 1 : Until l and r are asjacent to each other 
int lowerBound1(vector<int> arr,int target){
    int m = -1,l = 0;int r = n-1;
    while(l+1!=r){
        m = (l+r)/2;
        if(arr[m]<target)
            l = m;
        else
            r = m;
    }
    return a[r] == target?r:-1;
}

/* version 2 : hardcoding for n = 1000 
*/
int lowerBound2(vector<int> arr,int target){
    int l =-1,nexti;int i = 512; // exact power of two; highest power < 1000; i is used for partitioning and no of elements
    if(a[511] < target){ // keeping the right partiotion as a power of 2 
        l = 1000-512;
    }
    // At every iteration the search window decreases making the algorithm faster untill l is adjacent to the target element.
    while(i!=1){
        nexti = i/2;
        if(a[l+nexti]<target)
            l += nexti;
        i = nexti;
    }
    int r = l +1;
    return a[r] == target?r:-1;

}

// Version 3 : nexti variable can be sdropped from the previous version
int lowerBound3(vector<int> arr,int target){
    int l =-1,nexti;int i = 512; // exact power of two; highest power < 1000; i is used for partitioning and no of elements
    if(a[511] < target){ // keeping the right partiotion as a power of 2 
        l = 1000-512;
    }
    // At every iteration the search window decreases making the algorithm faster untill l is adjacent to the target element.
    while(i!=1){
        i = i/2;
        if(a[l+ i]<target)
            l += i;
    
    }
    int r = l +1;
    return a[r] == target?r:-1;
}