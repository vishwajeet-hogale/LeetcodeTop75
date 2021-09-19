#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int isPalindrome(string A){
    int i =0,j=A.length()-1;
    while(i<=j){
        if(A[i]!= A[j])
            return false;
        i++;
        j--;
    }
    return true;
}
vector<vector<string>> res;
void helper(string A,vector<string> temp){
    if(A.length() == 0){
        // string s = "";
        res.push_back(temp);
        
        return;
    }
    for(int i=1;i<=A.length();i++){
        string prefix = A.substr(0,i);
        string ros = A.substr(i);
        if(isPalindrome(prefix)){
            temp.push_back(prefix);
            helper(ros,temp);
            temp.pop_back();
        }
    }
}
vector<vector<string> > partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> temp;
    helper(A,temp);
    return res;
}
int main(){
    string s = "cccaacbcaabb";
    vector<vector<string>> r = partition(s);
    for(auto x:r){
        for(string i:x)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}