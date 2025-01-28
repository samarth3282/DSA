#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a[" << i << "]: ";
        cin >> arr[i];
    }

    // precompute
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // iterate in the map

    // for (auto it : mpp)
    // {
    //     cout << it.first << "->" << it.second;
    // }

    int q;
    cout << "Enter the number of test cases: ";
    cin >> q;
    while (q--)
    {
        int num;
        cout << "Enter the number: ";
        cin >> num;
        // fetch
        cout << num << " appears " << mpp[num] << " times" << endl;
    }

    return 0;
}