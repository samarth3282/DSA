// Min Add to Make Parentheses Valid

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minParentheses(string &s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty() || s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                if (st.top() == '(')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    st.push(')');
                }
            }
        }
        return st.size();
    }
};