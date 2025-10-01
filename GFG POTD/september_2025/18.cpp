// Next Greater Element in Circular Array

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreater(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            st.push(arr[i]);
        }
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (st.top() != -1 && st.top() <= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(curr);
        }
        return ans;
    }
};