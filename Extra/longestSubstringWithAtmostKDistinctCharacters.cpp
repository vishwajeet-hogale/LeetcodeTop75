#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int longestKCharacters(string s,int k){
    int start = 0, ans = 0;
    unordered_map<int,int> mp;
    int n = s.length();
    for(int i =0;i<n;i++){
        mp[s[i]]++;
        if(mp.size()<=k){
            ans = max(ans,i-start+1);
        }
        else if(mp.size()>k){
            while(mp.size()>k){
                mp[s[start]]--;
                if(mp[s[start]] == 0){
                    mp.erase(s[start]);
                }
                start++;
            }
            ans = max(ans,i-start+1);
        }
    }
    return ans;
}
int main()
{
    string s = "aaabbbbccccccdccccd";
    cout<<longestKCharacters(s,3)<<endl;
    return 0;
}