#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------
// ✅ Brute Force Approach (Recursive DFS)
// --------------------------------------------------------
// Try jumping from each index recursively.
// If any path reaches the end, return true.
//
// Time Complexity: O(2^n) — Exponential due to all possible jump paths.
// Space Complexity: O(n) — Call stack due to recursion.
bool canReachEndBrute(int index, vector<int> &arr)
{
    int n = arr.size();
    if (index == n - 1)
        return true; // Base case: Reached the last index

    int maxJump = arr[index];
    for (int i = 1; i <= maxJump; i++)
    {
        if (index + i < n && canReachEndBrute(index + i, arr))
        {
            return true;
        }
    }
    return false;
}

// --------------------------------------------------------
// ✅ Optimal Greedy Approach
// --------------------------------------------------------
// Maintain the farthest index we can reach.
// If current index exceeds that, return false.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
bool canReachEndOptimal(vector<int> &arr)
{
    int maxReach = arr[0];
    int n = arr.size();

    for (int i = 1; i <= maxReach; i++)
    {
        if (i >= n)
            return true;                      // Already able to reach or cross the end
        maxReach = max(maxReach, i + arr[i]); // Update max reachable index
    }

    return maxReach >= n - 1;
}

// --------------------------------------------------------
// ✅ Utility: Run Robust Test Cases
// --------------------------------------------------------
void runTests()
{
    vector<vector<int>> testCases = {
        {2, 3, 1, 1, 4},      // true: jump 2->3->end
        {3, 2, 1, 0, 4},      // false: stuck at 0
        {0},                  // true: already at the end
        {2, 0, 0},            // true: can reach end
        {1, 1, 1, 0},         // true
        {1, 0, 1, 0},         // false
        {5, 4, 3, 2, 1, 0, 0} // false
    };

    for (int i = 0; i < testCases.size(); ++i)
    {
        vector<int> arr = testCases[i];
        cout << "Test Case " << i + 1 << ": ";
        cout << (canReachEndOptimal(arr) ? "Can Reach" : "Cannot Reach") << endl;
    }
}

// --------------------------------------------------------
// ✅ Main Driver
// --------------------------------------------------------
int main()
{
    runTests();

    // Optional: Try Brute Force on small inputs
    vector<int> small = {2, 3, 1, 1, 4};
    cout << "\n[Brute] Small Input: ";
    cout << (canReachEndBrute(0, small) ? "Can Reach" : "Cannot Reach") << endl;

    return 0;
}
