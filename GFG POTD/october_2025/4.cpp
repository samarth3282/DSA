// Expression Add Operators
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evaluateExpression(string s)
    {
        stack<int> st;
        long num = 0;
        char lastOp = '+';

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (isdigit(ch))
            {
                num = num * 10 + (ch - '0');
            }
            if (!isdigit(ch) || i == s.size() - 1)
            {
                if (lastOp == '+')
                    st.push(num);
                else if (lastOp == '-')
                    st.push(-num);
                else if (lastOp == '*')
                {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                }
                lastOp = ch;
                num = 0;
            }
        }

        int result = 0;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        return result;
    }

    void rec(int index, string temp, vector<string> &ans, string &str, int target)
    {
        if (index == str.size())
        {
            if (evaluateExpression(temp) == target)
                ans.push_back(temp);
            return;
        }

        for (int i = index; i < str.size(); i++)
        {
            string curNum = str.substr(index, i - index + 1);

            if (curNum.size() > 1 && curNum[0] == '0')
                break;

            if (index == 0)
            {
                rec(i + 1, curNum, ans, str, target);
            }
            else
            {
                rec(i + 1, temp + "+" + curNum, ans, str, target);
                rec(i + 1, temp + "-" + curNum, ans, str, target);
                rec(i + 1, temp + "*" + curNum, ans, str, target);
            }
        }
    }

    vector<string> findExpr(string &s, int target)
    {
        vector<string> ans;
        rec(0, "", ans, s, target);
        return ans;
    }
};