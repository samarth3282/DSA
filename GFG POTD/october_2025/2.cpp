// Unique K-Number Sum
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rec(int index, int k, int n, int sum, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr)
    {
        if (ds.size() == k || index == 9)
        {
            if (sum == n && ds.size() == k)
                ans.push_back(ds);
            return;
        }
        sum += arr[index];
        ds.push_back(arr[index]);
        rec(index + 1, k, n, sum, ds, ans, arr);
        sum -= arr[index];
        ds.pop_back();
        rec(index + 1, k, n, sum, ds, ans, arr);
    }
    vector<vector<int>> combinationSum(int n, int k)
    {
        // code here
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> ds = {};
        vector<vector<int>> ans;
        rec(0, k, n, 0, ds, ans, arr);
        return ans;
    }
};