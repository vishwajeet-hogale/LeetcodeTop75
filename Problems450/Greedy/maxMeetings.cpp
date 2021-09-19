#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cmp(vector<int> a,vector<int> b){
    return a[1]<b[1];
}
int maxMeetings(vector<int> start,vector<int> end,int n){
    vector<vector<int>> res;
    for(int i=0;i<n;i++){
        res.push_back({start[i],end[i],i});
    }
    sort(res.begin(),res.end(),cmp);
    int c = 0;
    int tl = res[0][1];
    for(int i=1;i<n;i++){
        if(res[i][0]>=tl){
            c++;
            tl = res[i][1];
        }

    }
    return c+1;
}
int main(){
    vector<int> start({ 1, 3, 0, 5, 8, 5 });
    vector<int> end({ 2, 4, 6, 7, 9, 9 });
    int n = start.size();
    cout<<maxMeetings(start,end,n)<<endl;
    return 0;
}