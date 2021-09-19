#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void wordbreakutil(string A,unordered_set<string> mymap,string r, vector<string> & res){
    for(int i=1 ; i<=A.length() ; i++){
        string pre  = A.substr(0,i);
        if(mymap.find(pre) != mymap.end()){
            if(i == A.length()){
                r+=pre;
                res.push_back(r);
                return;
            }
                wordbreakutil(A.substr(i,A.size()-i), mymap , r+pre+" ",res);
        }
    }
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
   unordered_set<string> mymap;
   for(int i=0 ; i<B.size() ; i++)
   mymap.insert(B[i]);
   string r = "";
   vector<string> res;
   wordbreakutil(A,mymap,r,res);
   return res;
}
// int wordBreak(vector<string> dict,string s,vector<string> &temp){
//     if(s.length() == 0){
//         for(string i:temp)
//             cout<<i<<" ";
//         cout<<endl;
//         // return true;
//     }
//     int res = false;
//     for(string x:dict){
//         int len = x.length();
        
//         if(x.compare(s.substr(0,len))==0){
//             temp.push_back(x);
//             res = res || wordBreak(dict,s.substr(len),temp);
//             temp.pop_back();
//         }
//     }
//     return res;
// }
int main(){
    string s= "catsanddog";
    int n = 5;vector<string> temp;
    vector<string> dict({"cats", "cat", "and", "sand", "dog","ca","t"});
    cout<<wordBreak(dict,s,temp)<<endl;
    return 0;
}