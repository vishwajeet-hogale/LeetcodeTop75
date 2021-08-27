//Kadane's Alg
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int largestSubArray(vector<int> nums){
    int msf = INT_MIN, m_end = 0;
    for(int i:nums){
        m_end += i;
        if(msf < m_end)
            msf = m_end;
        if(m_end <0)
            m_end = 0;
    }
    return msf;
}
int main(){
    vector<int> nums({0,0,-1,2,4,6,-2});
    cout<<largestSubArray(nums)<<endl;
    return 0;
}