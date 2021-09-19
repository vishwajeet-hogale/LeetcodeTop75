#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> slidingwindowMax(vector<int> arr,int k){
    vector<int> res;
    int i =0;
    int n = arr.size();
    // priority_queue<int> pr;
    for(int i=0;i<=n-k;i++){
        priority_queue<int> pr;
        for(int j =i;j<i+k;j++){
            pr.push(arr[j]);
        }
        res.push_back(pr.top());
        cout<<pr.top()<<endl;
    }

    return res;
}
int main(){
    vector<int> arr({1, 2, 3, 1, 4, 5, 2, 3, 6});
    vector<int> res = slidingwindowMax(arr,3);
    return 0;
}