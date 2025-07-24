#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------------
   ✅ BRUTE FORCE APPROACH: Try All Partitions (Recursive)
   - Try every way to split array into m parts
   - For each partition, take max sum and track minimum of them

   Time Complexity: O(2^n * n) -> very slow for large input
   Space Complexity: O(n) for recursion stack
-----------------------------------------------------------*/
int getMaxPartitionSum(vector<int> &arr, int idx, int m)
{
    if (m == 1)
    {
        return accumulate(arr.begin() + idx, arr.end(), 0);
    }

    int minLargest = INT_MAX, currentSum = 0;

    for (int i = idx; i <= arr.size() - m; i++)
    {
        currentSum += arr[i];
        int largest = max(currentSum, getMaxPartitionSum(arr, i + 1, m - 1));
        minLargest = min(minLargest, largest);
    }
    return minLargest;
}

int splitArrayBruteForce(vector<int> &arr, int m)
{
    return getMaxPartitionSum(arr, 0, m);
}

/*----------------------------------------------------------
   ✅ BETTER APPROACH: Top-Down Memoization (DP)
   - Memoization of [idx][m] states to avoid recomputation

   Time Complexity: O(n^2 * m)
   Space Complexity: O(n * m)
-----------------------------------------------------------*/
int solveMemo(int idx, int m, vector<int> &arr, vector<vector<int>> &dp)
{
    if (m == 1)
        return accumulate(arr.begin() + idx, arr.end(), 0);

    if (dp[idx][m] != -1)
        return dp[idx][m];

    int minLargest = INT_MAX, currentSum = 0;
    for (int i = idx; i <= arr.size() - m; i++)
    {
        currentSum += arr[i];
        int largest = max(currentSum, solveMemo(i + 1, m - 1, arr, dp));
        minLargest = min(minLargest, largest);
    }

    return dp[idx][m] = minLargest;
}

int splitArrayMemo(vector<int> &arr, int m)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    return solveMemo(0, m, arr, dp);
}

/*----------------------------------------------------------
   ✅ OPTIMAL APPROACH: Binary Search on Answer
   - Lower bound = max element (each must be assigned at least once)
   - Upper bound = sum of all elements (all in one partition)
   - Goal: Find the minimum max partition sum possible

   Time Complexity: O(n * log(sum - maxElement))
   Space Complexity: O(1)
-----------------------------------------------------------*/
int countPartitionsWithMaxSum(vector<int> &arr, int maxAllowedSum)
{
    int studentCount = 1;
    int currentSum = 0;

    for (int pages : arr)
    {
        if (currentSum + pages <= maxAllowedSum)
        {
            currentSum += pages;
        }
        else
        {
            studentCount++;
            currentSum = pages;
        }
    }
    return studentCount;
}

int splitArrayBinarySearch(vector<int> &arr, int m)
{
    int low = *max_element(arr.begin(), arr.end());   // Minimum possible max sum
    int high = accumulate(arr.begin(), arr.end(), 0); // Max possible sum

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check how many partitions needed if max sum is 'mid'
        int partitions = countPartitionsWithMaxSum(arr, mid);

        if (partitions > m)
        {
            low = mid + 1; // Need more partitions → increase max sum
        }
        else
        {
            high = mid - 1; // Can do in ≤ m partitions → try smaller max sum
        }
    }
    return low;
}

/*----------------------------------------------------------
   ✅ DRIVER CODE + ROBUST TEST CASES
-----------------------------------------------------------*/
int main()
{
    vector<vector<int>> testCases = {
        {7, 2, 5, 10, 8},         // Normal case
        {1, 2, 3, 4, 5},          // Equal spacing
        {1, 4, 4},                // Small case
        {1, 1, 1, 1, 1, 1, 1, 1}, // All same elements
        {10},                     // Single element
        {1000, 1, 1, 1, 1, 1, 1}  // One large + many small
    };
    vector<int> mValues = {2, 2, 3, 4, 1, 2};

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test " << i + 1 << ":\n";
        cout << "Array: ";
        for (int x : testCases[i])
            cout << x << " ";
        cout << "\nPartitions: " << mValues[i] << "\n";

        // Uncomment any version to test
        // cout << "Brute: " << splitArrayBruteForce(testCases[i], mValues[i]) << "\n";
        // cout << "Memo: " << splitArrayMemo(testCases[i], mValues[i]) << "\n";
        cout << "Optimal: " << splitArrayBinarySearch(testCases[i], mValues[i]) << "\n";
        cout << "---------------------------\n";
    }

    return 0;
}
