// Decode the string

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodedString(string &s)
    {
        // code here
        // stack<pair<string, int>>st;
        // stack<char>ans;
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ']')
            {
                string temp;
                while (!st.empty() && st.top() != '[')
                {
                    temp.push_back(st.top());
                    st.pop();
                }
                if (!st.empty() && st.top() == '[')
                    st.pop();
                reverse(temp.begin(), temp.end());
                string k;
                while (!st.empty() && st.top() >= '0' && st.top() <= '9')
                {
                    k.push_back(st.top());
                    st.pop();
                }
                reverse(k.begin(), k.end());
                int num = stoi(k);
                string temp2;
                for (int i = 0; i < num; i++)
                {
                    temp2.append(temp);
                }
                for (char ch : temp2)
                {
                    st.push(ch);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};