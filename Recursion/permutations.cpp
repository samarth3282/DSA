#include <bits/stdc++.h>
using namespace std;

void rec(int index, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, vector<bool> &isTaken)
{
    if (index == arr.size())
    {
        ans.push_back(ds);
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

int main()
{
    vector<vector<int>> ans;
    vector<int> ds = {};
    vector<int> arr = {1, 2, 3};
    vector<bool> isTaken(arr.size(), false);
    rec(0, arr, ds, ans, isTaken);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}