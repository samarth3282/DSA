#include <bits/stdc++.h>
using namespace std;
int capacityToShipBrute(vector<int> &arr, int d)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for (int cap = low; cap <= high; cap++)
    {
        int load = 0, day = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (load + arr[i] > cap)
            {
                day++, load = arr[i];
            }
            else
            {
                load = load + arr[i];
            }
        }
        if (day <= d)
            return cap;
    }
}

int capToShipBetter(vector<int> &arr, int d)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int cap = ((low + high) / 2);
        int load = 0, day = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (load + arr[i] > cap)
            {
                day++, load = arr[i];
            }
            else
            {
                load += arr[i];
            }
        }

        if (day <= d)
        {
            high = cap - 1;
        }
        else
        {
            low = cap + 1;
        }
    }
    return low;
}
int main()
{

    return 0;
}