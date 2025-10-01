// Generate all binary strings
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rec(int index, int n, string &temp, vector<string> &ans)
    {
        if (index == n)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back('0');
        rec(index + 1, n, temp, ans);
        temp.pop_back();

        temp.push_back('1');
        rec(index + 1, n, temp, ans);
        temp.pop_back();
    }
    vector<string> binstr(int n)
    {
        // code here
        string temp;
        vector<string> ans;
        rec(0, n, temp, ans);
        return ans;
    }
};