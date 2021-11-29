#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(string s){
        int i =0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int mn = INT_MAX;
    string s1 = "";
    map<string,int> m;
    int helper(string s){
        // if(!check(s))
        //     return false;
        if(m.find(s)!=m.end())
            return true;
        for(int j=s.length()-1;j>=0;j--){
            string suff = s.substr(j);
            reverse(suff.begin(),suff.end());
            string newS = suff + s;
            // cout<<newS<<endl;
            if(check(newS)){
                m[newS] = 1;
                int len = newS.length();
                if(len<mn){
                    mn = len;
                    s1 = newS;
                }
                return true;
            }
        }
        m[s] = 0;
        return false;
        
    }
    string shortestPalindrome(string s) {
        if(check(s))
            return s;
        int f = helper(s);
        return s1;
    }
};
int main(){
    Solution s1;
    string s = "aabbbaaabbbb";
    cout<<s1.shortestPalindrome(s)<<endl;
    return 0;
}