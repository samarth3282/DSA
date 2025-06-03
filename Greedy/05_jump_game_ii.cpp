#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------
📌 BRUTE-FORCE RECURSIVE APPROACH
--------------------------------------------
Approach:
- From each index, try all possible jumps from 1 to arr[index].
- Recurse for each and take the minimum.
- Base case: If index reaches or crosses last index, return number of jumps taken.

Time Complexity: O(2^n) — Worst-case exponential due to overlapping subproblems.
Space Complexity: O(n) — Due to recursion stack.
*/
int minimumJumpsBrute(vector<int> &arr, int index, int jumps)
{
    if (index >= arr.size() - 1)
        return jumps;

    int mini = INT_MAX;
    for (int i = 1; i <= arr[index]; i++)
    {
        mini = min(mini, minimumJumpsBrute(arr, index + i, jumps + 1));
    }
    return mini;
}

/*
--------------------------------------------
📌 BETTER APPROACH (Top-Down DP with Memoization)
--------------------------------------------
Approach:
- Same as brute-force but store already computed results to avoid recomputation.

Time Complexity: O(n^2) — Worst case: each index tries all possible jumps.
Space Complexity: O(n) — For recursion + memoization array.
*/
int minimumJumpsMemoHelper(vector<int> &arr, int index, vector<int> &dp)
{
    if (index >= arr.size() - 1)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int mini = INT_MAX;
    for (int jump = 1; jump <= arr[index]; jump++)
    {
        int nextIndex = index + jump;
        if (nextIndex < arr.size())
        {
            int jumpsNeeded = minimumJumpsMemoHelper(arr, nextIndex, dp);
            if (jumpsNeeded != INT_MAX)
                mini = min(mini, 1 + jumpsNeeded);
        }
    }

    return dp[index] = mini;
}

int minimumJumpsMemo(vector<int> &arr)
{
    vector<int> dp(arr.size(), -1);
    return minimumJumpsMemoHelper(arr, 0, dp);
}

/*
--------------------------------------------
📌 OPTIMAL APPROACH (Greedy)
--------------------------------------------
Approach:
- At each level, keep track of the farthest index reachable.
- Increase jump count when you complete a "level" (range).

Time Complexity: O(n)
Space Complexity: O(1)
*/
int minimumJumpsOptimal(vector<int> &arr)
{
    int l = 0, r = 0, jumps = 0;
    while (r < arr.size() - 1)
    {
        int farthest = 0;
        for (int i = l; i <= r; i++)
        {
            farthest = max(farthest, i + arr[i]);
        }
        if (farthest == r)
            return -1; // Cannot proceed further
        l = r + 1;
        r = farthest;
        jumps++;
    }
    return jumps;
}

/*
--------------------------------------------
📌 HELPER FUNCTION TO RUN TEST CASES
--------------------------------------------
*/
void runTest(vector<int> arr)
{
    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    cout << "Brute Force Result: " << minimumJumpsBrute(arr, 0, 0) << "\n";
    cout << "Memoized Result   : " << minimumJumpsMemo(arr) << "\n";
    cout << "Optimal Result    : " << minimumJumpsOptimal(arr) << "\n\n";
}

/*
--------------------------------------------
📌 MAIN FUNCTION
--------------------------------------------
*/
int main()
{
    // 🔍 Test Case 1
    runTest({2, 3, 1, 1, 4}); // Expected: 2

    // 🔍 Test Case 2
    runTest({1, 3, 6, 1, 0, 9}); // Expected: 3

    // 🔍 Test Case 3
    runTest({1, 1, 1, 1}); // Expected: 3

    // 🔍 Test Case 4 (Edge Case)
    runTest({0}); // Expected: 0 (Already at destination)

    // 🔍 Test Case 5 (Unreachable Case)
    runTest({3, 2, 1, 0, 4}); // Expected: -1 (Only optimal handles this)

    return 0;
}
