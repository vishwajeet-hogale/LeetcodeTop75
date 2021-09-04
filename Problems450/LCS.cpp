#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int arr[], int n)
{
      //Your code here
     unordered_set<int> S;
    int ans = 0;
 
    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
 
    // check each possible sequence from
    // the start then update optimal length
    for (int i = 0; i < n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i] - 1) == S.end())
        {
            // Then check for next elements
            // in the sequence
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;
 
            // update  optimal length if
            // this length is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}
int main(){
    int arr[] = {6 ,6 ,2 ,3 ,1 ,4 ,1, 5 ,6 ,2 ,8 ,7 ,4 ,2 ,1 ,3, 4 ,5 ,9 ,6};
    cout<<findLongestConseqSubseq(arr,20)<<endl;
    return 0;
}