#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Interval{
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
};
int cmp(Interval a,Interval b){
    return a.start<b.start;
}
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
    int i =0;
    int n = intervals.size();
    sort(intervals.begin(),intervals.end(),cmp);
    while(i<n && intervals[i].end < newInterval.start){
        // Interval s(intervals[i].start,intervals[i].end);
        res.push_back(intervals[i++]);
        // i++;
    }
    Interval s;
    while (i<n && intervals[i].start <= newInterval.end)
    {
        s.start = min(newInterval.start,intervals[i].start);
        s.end = max(newInterval.end,intervals[i].end);
        i++;
    }
    res.push_back(s);
    
    while(i<n) res.push_back(intervals[i++]);
   
           
    return res;
}
int main(){
    Interval s(1,3),j(6,9),k(10,11),newInt(4,5);
    vector<Interval> intervals({s,j,k});
    // intervals.push_back({})
    vector<Interval> res = insert(intervals,newInt);
    // for(Interval x:res)
    //     cout<<x.start<<","<<x.end<<endl;
    return 0;
}