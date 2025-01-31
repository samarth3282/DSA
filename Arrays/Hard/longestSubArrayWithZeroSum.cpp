#include <bits/stdc++.h>
using namespace std;

int longestSubArrayWithZeroSumBrute(vector<int> &arr)
{
    int longestLength = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == 0)
            {
                longestLength = max(longestLength, j - i + 1);
            }
        }
    }
    return longestLength == INT_MIN ? 0 : longestLength;
}

int longestSubArrayWithZeroSumBetter(vector<int> &arr)
{
    int longestLength = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int sum = 0;
            sum += arr[j];
            if (sum == 0)
                longestLength = max(longestLength, j - i + 1);
        }
    }
    return longestLength == INT_MIN ? 0 : longestLength;
}

int longestSubArrayWithZeroSumOptimal(vector<int> &arr)
{
    int longestLength = INT_MIN;
    map<int, int> preSum;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            longestLength = max(longestLength, i + 1);
        }
        else
        {
            if (preSum.find(sum) != preSum.end())
            {
                longestLength = max(longestLength, i - preSum[sum]);
            }
            else
            {
                preSum[sum] = i;
            }
        }
    }
    return longestLength == INT_MIN ? 0 : longestLength;
}
int main()
{

    return 0;
}