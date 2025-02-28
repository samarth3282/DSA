#include <bits/stdc++.h>
using namespace std;
int numberOfSubarraysWithOddSum(vector<int> &arr)
{
    map<int, int> mpp;
    mpp[0] = 1;
    mpp[1] = 0;
    int cnt = 0;
    int preSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];
        if (preSum % 2 == 0)
        {
            cnt += mpp[1];
        }
        else
        {
            cnt += mpp[0];
        }

        if (preSum % 2 == 0)
            mpp[0]++;
        else
            mpp[1]++;
    }
    return cnt;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << numberOfSubarraysWithOddSum(arr);
    return 0;
}