#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int a1[100000]={0};
    map<char,int>m1;
    for(int i=0;i<tasks.size();i++)
        m1[tasks[i]]++;
    
    vector<pair<int,char>>v1;
    for(auto it=m1.begin();it!=m1.end();it++)
    {
        v1.push_back({it->second,it->first});
    }
    sort(v1.rbegin(),v1.rend());
    
    //greedy character with highest letter frequency and number of gaps required between them
    int max_val=v1[0].first-1; 
    
    //number of total slots between highest frequency letter: ie A _ _ A _ _ A
    int idle_slots=(max_val)*n; 
    
    for(int i=1;i<v1.size();i++)
    {
        
        //fill the slots with freq of letters and if char frequency is highest than fill max_val because that's the highest number that can fit inside gaps             
        idle_slots-=min(max_val,v1[i].first);
    }
    
  // if idle_slots are negative which means idle slots are completly filled thats why task.size() is answer else if idle_slots are left than answer is remaining idle slots + task.size() 
    return idle_slots>0?idle_slots+tasks.size():tasks.size();
    }
};