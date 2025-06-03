#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumKBrutest(vector<int> &arr, int k)
{
    int maxLen = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == k)
                maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

int longestSubarrayWithSumKBrute(vector<int> &arr, int k){
    int maxLen = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for(int j = i;j<arr.size();j++){
            sum+=arr[j];
            if(sum==k) maxLen = max(maxLen, j-i+1);
        }
    }
    return maxLen;
}
/**
 * Function: longestSubarrayWithSumKBetter
 * --------------------------------------
 * Better Approach using Hash Map (Prefix Sum)
 * Efficiently tracks cumulative sums and their first occurrence.
 *
 * @param arr[] - Input array of integers.
 * @param size - Size of the array.
 * @param k - Target sum for the subarray.
 * @return Length of the longest subarray with sum k.
 *
 * Time Complexity: O(n) - Single traversal with constant operations.
 * Space Complexity: O(n) - Hash map stores prefix sums.
 */
int longestSubarrayWithSumKBetter(int arr[], int size, int k)
{
    map<int, int> mpp; // Tracks prefix sums and their first occurrence
    int maxLen = 0;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];

        // If the sum itself matches k
        if (sum == k)
        {
            maxLen = i + 1;
        }

        // If (sum - k) exists in map, a valid subarray is found
        if (mpp.find(sum - k) != mpp.end())
        {
            maxLen = max(maxLen, i - mpp[sum - k]);
        }

        // Store the first occurrence of the current sum
        if (mpp.find(sum) == mpp.end())
        {
            mpp[sum] = i;
        }
    }

    return maxLen;
}

/**
 * Function: longestSubarrayWithSumKOptimal
 * ----------------------------------------
 * Optimal Approach using Two Pointers (Sliding Window)
 * Efficiently finds the longest subarray with sum k in O(n) time.
 *
 * @param arr[] - Input array of integers.
 * @param size - Size of the array.
 * @param k - Target sum for the subarray.
 * @return Length of the longest subarray with sum k.
 *
 * Time Complexity: O(n) - Single pass through the array with dynamic window adjustments.
 * Space Complexity: O(1) - Only variables used; no extra data structure required.
 */
int longestSubarrayWithSumKOptimal(int arr[], int size, int k)
{
    int maxLen = 0;
    int left = 0;
    int sum = 0;

    for (int right = 0; right < size; right++)
    {
        sum += arr[right];

        // Shrink the window if sum exceeds k
        while (sum > k && left <= right)
        {
            sum -= arr[left];
            left++;
        }

        // Check if current window matches the required sum
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
    }

    return maxLen;
}

// Driver Code with Robust Test Cases
int main()
{
    int testCases[][9] = {
        {1, 2, 3, 1, 1, 1, 1, 3, 3}, // Standard case
        {3, 4, 1, 1, 2, 1, 3},       // Multiple valid subarrays
        {1, 1, 1, 1, 1},             // Entire array sums to k
        {1, 2, 3, 4, 5},             // No valid subarray
        {0, 0, 0, 0, 0},             // Array filled with zeros
        {2, -1, 2, 1, 3, -2, 1}      // Contains negative numbers
    };

    int kValues[] = {6, 5, 5, 15, 0, 3};

    for (int i = 0; i < 6; i++)
    {
        cout << "Test Case " << i + 1 << ": ";
        cout << "Better Approach = " << longestSubarrayWithSumKBetter(testCases[i], 9, kValues[i]) << ", ";
        cout << "Optimal Approach = " << longestSubarrayWithSumKOptimal(testCases[i], 9, kValues[i]) << endl;
    }

    return 0;
}

int longestSubarrayWithSumK(vector<int> &arr, int k){
    
}