#include <bits/stdc++.h>
using namespace std;
int smallestDivisorOptimal(vector<int> &arr, int threshold)
{
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    while (low <= high)
    {
        int divisor = (low + ((high - low) / 2));
        int sumOfDivided = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sumOfDivided += (arr[i] + divisor - 1) / divisor;
        }
        if (sumOfDivided <= threshold)
            high = divisor - 1;
        else
            low = divisor + 1;
    }
    return low;
}
int main()
{

    return 0;
}