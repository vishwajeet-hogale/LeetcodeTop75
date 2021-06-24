#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26,0);
        for(char c:s)
            cnt[c-'a']++;
        vector<int> s1;int j = 0;
        for(int i =0;i<26;i++){
            while(cnt[i] >0 && find(s1.begin(),s1.end(),cnt[i]) != s1.end()){
                cnt[i]--;
                j++;
            }
            s1.push_back(cnt[i]);
        }
        return j;
    }
};