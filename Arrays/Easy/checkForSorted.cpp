#include <bits/stdc++.h>
using namespace std;
bool checkForSorted(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = {10, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << checkForSorted(arr1) << endl;
    cout << checkForSorted(arr2);
    return 0;
}