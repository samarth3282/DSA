#include <bits/stdc++.h>
using namespace std;

void subsequenceWithSumK(int start, int arr[], int size, vector<int> &v, int k)
{
    if (start == size)
    {
        int sum = 0;
        for (auto it : v)
        {
            sum += it;
        }
        if (sum == k)
        {
            if (v.size() == 0)
            {
                cout << "{}";
                cout << endl;
            }
            else
            {
                cout << "{";
                for (int i = 0; i < v.size(); i++)
                {
                    if (i == v.size() - 1)
                    {
                        cout << v[i] << "}";
                    }
                    else
                    {
                        cout << v[i] << ", ";
                    }
                }

                cout << endl;
            }
        }
        return;
    }
    v.push_back(arr[start]);
    subsequenceWithSumK(start + 1, arr, size, v, k);
    v.pop_back();
    subsequenceWithSumK(start + 1, arr, size, v, k);
}

bool oneSubsequenceWithSumK(int start, int arr[], int size, vector<int> &v, int k)
{
    if (start == size)
    {
        int sum = 0;
        for (auto it : v)
        {
            sum += it;
        }
        if (sum == k)
        {
            if (v.size() == 0)
            {
                cout << "{}";
                cout << endl;
            }
            else
            {
                cout << "{";
                for (int i = 0; i < v.size(); i++)
                {
                    if (i == v.size() - 1)
                    {
                        cout << v[i] << "}";
                    }
                    else
                    {
                        cout << v[i] << ", ";
                    }
                }

                cout << endl;
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    v.push_back(arr[start]);
    if (oneSubsequenceWithSumK(start + 1, arr, size, v, k) == true)
    {
        return true;
    }
    v.pop_back();
    if (oneSubsequenceWithSumK(start + 1, arr, size, v, k) == true)
    {
        return true;
    }
    return false;
}
int countSubsequenceWithSumK(int start, int arr[], int size, vector<int> &v, int k)
{
    if (start == size)
    {
        int sum = 0;
        for (auto it : v)
        {
            sum += it;
        }
        if (sum == k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    v.push_back(arr[start]);
    int l = countSubsequenceWithSumK(start + 1, arr, size, v, k);
    v.pop_back();
    int r = countSubsequenceWithSumK(start + 1, arr, size, v, k);
    return l + r;
}
int main()
{
    vector<int> v;
    int arr[] = {1, 2, 1};
    cout << countSubsequenceWithSumK(0, arr, 3, v, 2);
    return 0;
}