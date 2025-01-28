#include <bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumKBetter(int arr[], int size, int k)
{
    map<int, int> mpp;
    int maxLen = 0;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        if (mpp.find(sum - k) != mpp.end())
        {
            maxLen = max(maxLen, i - mpp[sum - k]);
        }
        else
        {
            mpp[sum] = i;
        }
    }
    return maxLen;
}
int longestSubarrayWithSumKOptimal(int arr[], int size, int k)
{
    int maxLen = 0;
    int left = 0;
    int right = 0;
    int sum = arr[0];
    while (right < size)
    {
        while (sum > k && left <= right)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < size)
        {
            sum += arr[right];
        }
    }
    return maxLen;
}
int main()
{
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    cout << longestSubarrayWithSumKOptimal (arr, 9, 6);
    return 0;
}