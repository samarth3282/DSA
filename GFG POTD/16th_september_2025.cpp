// Postfix Evaluation

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evaluatePostfix(vector<string> &arr)
    {
        stack<int> st;
        for (int i = 0; i < arr.size(); i++)
        {
            string token = arr[i];

            if (token != "+" && token != "-" && token != "*" && token != "/" && token != "^")
            {
                st.push(stoi(token));
            }
            else
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                if (token == "+")
                    st.push(num1 + num2);
                else if (token == "-")
                    st.push(num1 - num2);
                else if (token == "*")
                    st.push(num1 * num2);
                else if (token == "/")
                    st.push(floor((double)num1 / num2));
                else if (token == "^")
                    st.push(pow(num1, num2));
            }
        }
        return st.top();
    }
};
