#include <bits/stdc++.h>
using namespace std;

void rec1(int index, vector<int> &ds, vector<int> &arr, int sum, int k)
{
    if (index == arr.size())
    {
        if (sum == k)
        {
            for (int i = 0; i < ds.size(); i++)
            {
                cout << ds[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    ds.push_back(arr[index]);
    sum += arr[index];
    rec1(index + 1, ds, arr, sum, k);
    ds.pop_back();
    sum -= arr[index];
    rec1(index + 1, ds, arr, sum, k);
}

void subsequenceWithSumK(vector<int> &arr, int k)
{
    vector<int> ds;
    rec1(0, ds, arr, 0, k);
}

bool rec2(int index, vector<int> &ds, vector<int> &arr, int sum, int k)
{
    if (index == arr.size())
    {
        if (sum == k)
        {
            for (int i = 0; i < ds.size(); i++)
            {
                cout << ds[i] << " ";
            }
            cout << endl;
            return true;
        }
        else
            return false;
    }

    ds.push_back(arr[index]);
    sum += arr[index];

    if (rec2(index + 1, ds, arr, sum, k))
        return true;

    ds.pop_back();
    sum -= arr[index];

    if (rec2(index + 1, ds, arr, sum, k))
        return true;

    return false;
}

void oneSubsequenceWithSumK(vector<int> &arr, int k)
{
    vector<int> ds;
    rec2(0, ds, arr, 0, k);
}

int rec3(int index, vector<int> &ds, vector<int> &arr, int sum, int k)
{
    if (index == arr.size())
    {
        if (sum == k)
            return 1;
        else
            return 0;
    }
    int cnt = 0;
    ds.push_back(arr[index]);
    sum += arr[index];
    cnt += rec3(index + 1, ds, arr, sum, k);
    ds.pop_back();
    sum -= arr[index];
    cnt += rec3(index + 1, ds, arr, sum, k);
    return cnt;
}

int countSubsequencesWithSumK(vector<int> &arr, int k)
{
    vector<int> ds;
    return rec3(0, ds, arr, 0, k);
}
int main()
{
    // vector<int> v;
    vector<int> arr = {1, 2, 1};
    cout << countSubsequencesWithSumK(arr, 2);
    return 0;
}
