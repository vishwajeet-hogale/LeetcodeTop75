#include<iostream>
#include<bits/stdc++.h>
using namespace std;    

int twoCityScheduling(vector<vector<int>> costs){
        vector<pair<int,int>>savings;
        int n=costs.size();
        for(int i=0;i<n;i++){
            savings.push_back({(costs[i][1]-costs[i][0]),i});
        }
        sort(savings.begin(),savings.end());
        int answer=0;
        for(int i=0;i<n/2;i++){  answer+=costs[savings[i].second][1]; }
            
        for(int i=n/2;i<n;i++){
                   answer+=costs[savings[i].second][0];
            
        }
        return answer;
}
int main(){
    vector<vector<int>> costs{
        {40,30},
        {300,200},
        {50,50},
        {30,60}
    };
    cout<<twoCityScheduling(costs)<<endl;
    return 0;
}