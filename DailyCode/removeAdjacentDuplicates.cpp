#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int check(string &s)
{
    if (s.length() == 0)
    {
        return -1;
    }
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            s[i] = '#';
            s[i + 1] = '#';
            s.erase(remove(s.begin(), s.end(), '#'), s.end());
            cout << s << endl;
            return i;
        }
    }
    return -1;
}
string removeDuplicates(string s)
{
    if (check(s) == -1)
    {
        return s;
    }
    return removeDuplicates(s);
}
int main()
{
    string s = "abccbefggfe";
    cout << removeDuplicates(s) << endl;
    return 0;
}