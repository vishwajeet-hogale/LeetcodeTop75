#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string check(string s)
{
    string str = "";
    for (char c : s)
    {
        if (c != '#')
            str.push_back(c);
        else
            str.pop_back();
    }
    cout << str << endl;
    return str;
}
bool compareKeystrokes(string s, string t)
{
    string s1 = check(s);
    string t1 = check(t);
    return s1.compare(t1) == 0;
}
int main()
{
    string s = "ABC#D", t = "CD##AB";
    cout << compareKeystrokes(s, t) << endl;
    return 0;
}