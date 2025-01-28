#include <bits/stdc++.h>
using namespace std;
int maxSubarraySumBrute(int arr[], int size)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}

int maxSubarraySumBetter(int arr[], int size)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}

vector<int> maxSubarraySumOptimal(int arr[], int size)
{
    int sum = 0;
    int maxSum = INT_MIN;
    int ansStart = -1;
    int ansEnd = -1;
    int start;
    for (int i = 0; i < size; i++)
    {
        if (sum == 0)
        {
            start = i;
        }

        sum += arr[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    vector<int> ans;
    for (int i = ansStart; i <= ansEnd; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}
int maxSubarraySumOptimal2(int arr[], int size)
{
    int sum = 0;
    int maxSum = INT_MIN;
    int length = 0;
    for (int i = 0; i < size; i++)
    {

        sum += arr[i];
        if (sum > maxSum)
        {
            maxSum = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum == INT_MIN ? INT_MIN : maxSum;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << maxSubarraySumBrute(arr, size) << endl;
    cout << maxSubarraySumBetter(arr, size) << endl;
    cout << maxSubarraySumOptimal2(arr, size) << endl;
    vector<int> ans = maxSubarraySumOptimal(arr, size);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}