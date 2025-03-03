#include <bits/stdc++.h>
using namespace std;
int countNumberOfStations(vector<int> &arr, double dist)
{
    int cnt = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int numberInBetween = (arr[i + 1] - arr[i]) / dist;
        cnt += numberInBetween;
    }
    return cnt;
}

double findSmallestMaxDist(vector<int> &arr, int k)
{
    double low = 0, high = 0;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        high = max((double)(arr[i + 1] - arr[i]), high);
    }

    double diff = 1e-6; // Precision for floating-point binary search
    while (high - low > diff)
    {
        double mid = low + (high - low) / 2.0;

        if (countNumberOfStations(arr, mid) > k)
        {
            low = mid; // Need to increase distance, so move right
        }
        else
        {
            high = mid; // Reduce distance, move left
        }
    }
    return high;
}
int main()
{

    return 0;
}