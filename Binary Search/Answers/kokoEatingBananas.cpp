#include <bits/stdc++.h>
using namespace std;
int kokoEatingBananasBrute(vector<int> &arr, int h)
{
    for (int i = 1; i < arr[max_element(arr.begin(), arr.end()) - arr.begin()]; i++)
    {
        int totalTime = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            totalTime = ceil(arr[j] / i);
        }
        if (totalTime <= h)
            return i;
    }
}
int main()
{

    return 0;
}