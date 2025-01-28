#include <bits/stdc++.h>
using namespace std;
bool isValid(string str)
{
    stack<char> st;
    for (auto it : str)
    {
        if (it == '(' || it == '{' || it == '[')
        {
            st.push(it);
        }
        else
        {
            if (st.empty() == true)
            {
                return false;
            }
            char topEl = st.top();
            st.pop();
            if (it == ')' and topEl == '(' or it == ']' and topEl == '[' or it == '}' and topEl == '{')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}
int main()
{
    return 0;
}