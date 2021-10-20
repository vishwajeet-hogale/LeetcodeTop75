#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int longestSubstringWithAtmostTwoDistinctCharacters(string s){
    unordered_map<char,int> mp;
    int ans = 0;
    int st = 0;
    for(int i = 0;i<s.length();i++){
        mp[s[i]]++;
        if(mp.size() <= 2){
            ans = max(ans,i-st+1);
        }
        else if(mp.size()>2){
            while(mp.size()>2){
                mp[s[st]]--;
                if(mp[s[st]] == 0)
                    mp.erase(s[st]);
                st++;
            }
            ans = max(ans,i-st+1);
        }
    }
    return ans;
}
int main(){
    string s = "aabbxbbbbaacccccbb";
    cout<<longestSubstringWithAtmostTwoDistinctCharacters(s)<<endl;
    return 0;
}