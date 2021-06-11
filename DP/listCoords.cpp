#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findCrossOverPoint(vector<int> &points,int x,int start,int end){
    if(points[start]> x)
        return start;
    if(points[end] <= x)
        return end;
    int mid = (start + end) / 2;
    if(points[mid] <= x && points[mid+1] > x)
        return mid;
    if(points[mid]<x){
        return findCrossOverPoint(points,x,mid+1,end);
   
       
    }
     return findCrossOverPoint(points,x,start,mid-1);
}
vector<int> kClosestPoints(vector<int> &points,int x,int value){
    
    vector<int> res;
    int l = findCrossOverPoint(points,value,0,points.size()-1);
    int r = l+1;
    l = points[l] == value ? l-1:l;
    while(l>= 0 && r< points.size() && x){

        if(value - points[l] < points[r] - value)
            res.push_back(points[l--]);
        else
            res.push_back(points[r++]);
        x--;
    }
    while (x && l >= 0){
        res.push_back(points[l--]); x--;
    }
 

    while (x && r < points.size()){
        res.push_back(points[r++]), x--;
    }
    return res;
}
int main(){
    vector<int> points({12,16,22,30,35,39,42,45,48,50,53,55});
    vector<int> res = kClosestPoints(points,5,35);
    for(int i:res)
        cout<<i<<endl;
    return 0;
}