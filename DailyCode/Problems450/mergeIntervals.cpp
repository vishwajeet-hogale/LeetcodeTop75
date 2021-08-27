#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<vector<int>> mergeInter(vector<vector<int>> intervals){
    sort(intervals.begin(),intervals.end());
    int x = intervals[0][0];
    int y = intervals[0][1];
    vector<vector<int>> res;
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<=y){
            if(intervals[i][1]>=y){
                y = intervals[i][1];
            }
        }
        else{
            res.push_back({x,y});
            x = intervals[i][0];
            y = intervals[i][1];
        }
    }
    res.push_back({x,y});
    return res;
}
int main(){

    vector<vector<int>> intervals({{1,3},{2,6},{8,10},{15,18}});
    vector<vector<int>> res = mergeInter(intervals);
    return 0;
}