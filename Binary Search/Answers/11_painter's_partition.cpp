#include <bits/stdc++.h>
using namespace std;

// 💡 Brute Force: Try all possible partitions into k subarrays, get the max among minimums
// Time: O(2^n), Space: O(n) - Not feasible for large n
int getMaxSumBruteForce(vector<int> &arr, int k, int idx, vector<int> &partitions)
{
    if (idx == arr.size())
    {
        if (partitions.size() != k)
            return INT_MAX;
        int maxSum = 0;
        for (int p : partitions)
            maxSum = max(maxSum, p);
        return maxSum;
    }

    int minMaxSum = INT_MAX;
    int currSum = 0;

    for (int i = idx; i < arr.size(); i++)
    {
        currSum += arr[i];
        partitions.push_back(currSum);
        minMaxSum = min(minMaxSum, getMaxSumBruteForce(arr, k, i + 1, partitions));
        partitions.pop_back();
    }
    return minMaxSum;
}

// 💡 Better Approach: Use recursion + memoization (Top Down)
// Time: O(k * n^2), Space: O(k * n)
int partitionWithMemo(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 1)
    {
        return accumulate(arr.begin() + i, arr.end(), 0);
    }
    if (dp[k][i] != -1)
        return dp[k][i];

    int sum = 0, result = INT_MAX;
    for (int j = i; j < arr.size(); j++)
    {
        sum += arr[j];
        int temp = max(sum, partitionWithMemo(j + 1, k - 1, arr, dp));
        result = min(result, temp);
    }

    return dp[k][i] = result;
}

// ✅ Optimal Approach: Binary Search + Greedy Partitioning
// Time: O(n * log(sum - max)), Space: O(1)
bool isFeasible(vector<int> &arr, int maxTime, int painters)
{
    int requiredPainters = 1, currSum = 0;
    for (int time : arr)
    {
        if (time > maxTime)
            return false; // Single board exceeds mid (invalid)
        if (currSum + time <= maxTime)
        {
            currSum += time;
        }
        else
        {
            requiredPainters++;
            currSum = time;
        }
    }
    return requiredPainters <= painters;
}

int paintersPartitionBinarySearch(vector<int> &arr, int painters)
{
    int low = *max_element(arr.begin(), arr.end());   // At least the largest board
    int high = accumulate(arr.begin(), arr.end(), 0); // At most total sum

    int answer = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isFeasible(arr, mid, painters))
        {
            answer = mid; // Try for a smaller max time
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // Increase max time
        }
    }
    return answer;
}

// 🧪 Utility to run multiple test cases
void runTestCases()
{
    vector<vector<int>> testCases = {
        {10, 20, 30, 40},
        {5, 5, 5, 5},
        {1, 8, 11, 3, 2},
        {1, 2, 3, 4, 5},
        {7},
        {1, 2, 3}};
    vector<int> painters = {2, 2, 3, 2, 1, 2};

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case #" << i + 1 << " : ";
        int result = paintersPartitionBinarySearch(testCases[i], painters[i]);
        cout << "Min time = " << result << endl;
    }
}

int main()
{
    // ✅ Test Brute Force (for small inputs only)
    vector<int> arr1 = {10, 20, 30, 40};
    vector<int> part;
    cout << "Brute Force (Only feasible for small n): " << getMaxSumBruteForce(arr1, 2, 0, part) << endl;

    // ✅ Test Better (Memoization)
    vector<int> arr2 = {10, 20, 30, 40};
    int k = 2;
    vector<vector<int>> dp(k + 1, vector<int>(arr2.size(), -1));
    cout << "Better (Memoization): " << partitionWithMemo(0, k, arr2, dp) << endl;

    // ✅ Test Optimal
    cout << "Optimal Binary Search Result:\n";
    runTestCases();

    return 0;
}
