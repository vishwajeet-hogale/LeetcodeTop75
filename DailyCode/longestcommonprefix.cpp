#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string result="";
        int i=0,len=201,j,flag=0;
        for(i=0;i<strs.size();i++)
        {
            if(strs[i].length()<len)
                len=strs[i].length();
        }
        for(i=0;i<len;i++)
        {
            char ch=strs[0][i];
            for(j=1;j<strs.size();j++)
            {
                if(ch!=strs[j][i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                result=result+ch;
            }
            else
                break;
        }
        return result;

}