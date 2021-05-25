#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkValidParenthesis(string s)
{
    stack<char> st;
    for (char c : s)
    {
        cout << c << endl;
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else if (c == ')' && !st.empty())
        {
            if (st.top() == '(')
            {
                st.pop();
            }
            else
                break;
        }
        else if (c == '}' && !st.empty())
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else
                break;
        }
        else if (c == ']' && !st.empty())
        {
            if (st.top() == '[')
            {
                st.pop();
            }
            else
                break;
        }
        else
        {
            return false;
        }
    }
    return st.empty();
}
int main()
{
    string s = "()";
    cout << checkValidParenthesis(s) << endl;
    return 0;
}