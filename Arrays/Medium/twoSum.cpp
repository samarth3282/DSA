#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int arr[], int size, int k)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {
                if (arr[i] + arr[j] == k)
                {
                    return {i, j};
                }
            }
        }
    }
    return {};
}

vector<int> twoSumBetter(int arr[], int size, int k)
{
    map<int, int> mpp;
    for (int i = 0; i < size; i++)
    {
        int num = arr[i];
        int secondNum = k - arr[i];
        if (mpp.find(secondNum) != mpp.end())
        {
            return {i, mpp[secondNum]};
        }
        else
        {
            mpp[arr[i]] = i;
        }
    }
    return {};
}

vector<int> twoSumOptimal(vector<int> &arr, int k)
{
    map<int, int> mpp;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        mpp[arr[i]] = i;
    }

    sort(arr.begin(), arr.end());
    int l = 0;
    int r = arr.size() - 1;
    while (l < r)
    {
        int sum = arr[l] + arr[r];
        if (sum > k)
        {
            r--;
        }
        if (sum < k)
        {
            l++;
        }
        if (sum == k)
        {
            return {mpp[arr[l]], mpp[arr[r]]};
        }
    }
    return {};
}

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    vector<int> v = twoSumOptimal(arr, 14);
    for (auto it : v)
    {
        cout << it << " ";
    }
    return 0;
}