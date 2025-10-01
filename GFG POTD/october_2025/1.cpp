// All Unique Permutations of an array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rec(int index, vector<int> &arr, vector<int> &ds, set<vector<int>> &ans, vector<bool> &isTaken)
    {
        if (index == arr.size())
        {
            ans.insert(ds);
            return;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (!isTaken[i])
            {
                isTaken[i] = true;
                ds.push_back(arr[i]);
                rec(index + 1, arr, ds, ans, isTaken);
                ds.pop_back();
                isTaken[i] = false;
            }
        }
    }

    vector<vector<int>> uniquePerms(vector<int> &arr)
    {
        // code here
        set<vector<int>> ans;
        vector<int> ds = {};
        // vector<int> arr = {1, 2, 3};
        vector<bool> isTaken(arr.size(), false);
        rec(0, arr, ds, ans, isTaken);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};