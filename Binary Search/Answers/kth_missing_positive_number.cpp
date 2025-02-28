#include <bits/stdc++.h>
using namespace std;

int kthMissingPositiveNumberBrute(vector<int> &arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= k)
            k++;
        else
            break;
    }
    return k;
}

int kthMissingPositiveNumberOptimal(vector<int> &arr, int k)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = ((low + high) / 2);
        if (arr[mid] - mid - 1 < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low + k;
}
int main()
{

    return 0;
}