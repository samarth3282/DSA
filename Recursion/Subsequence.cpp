#include <bits/stdc++.h>
using namespace std;

void subsequence(int start, vector<int> &arr, int size, vector<int> &v)
{
    if (start == size)
        return;
}
void subsequence(int start, int arr[], int size, vector<int> &v)
{
    if (start == size)
    {
        if (v.size() == 0)
        {
            cout << "{}";
        }
        else
        {
            cout << "{";
            for (auto it : v)
            {
                if (it == v.back())
                {
                    cout << it << "}";
                }
                else
                {
                    cout << it << ", ";
                }
            }
        }
        cout << endl;
        return;
    }
    v.push_back(arr[start]); // Take
    subsequence(start + 1, arr, size, v);
    v.pop_back();
    subsequence(start + 1, arr, size, v); // Not Take
}
int main()
{
    vector<int> v;
    int arr[] = {3, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    subsequence(0, arr, size, v);
    return 0;
}