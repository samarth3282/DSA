#include <bits/stdc++.h>
using namespace std;

/**
 * Function: isPossible
 * --------------------
 * Checks if it's possible to place `cows` with at least `dist` separation.
 * - Places first cow at `arr[0]`.
 * - Iterates through stalls and places a cow only if separation >= `dist`.
 * - If all `cows` are placed successfully, return true.
 *
 * @param arr - Sorted vector containing stall positions.
 * @param dist - Minimum required distance between cows.
 * @param cows - Number of cows to be placed.
 * @return True if cows can be placed with `dist`, otherwise False.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
bool isPossible(vector<int> &arr, int dist, int cows)
{
    int lastPlaced = arr[0], count = 1;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - lastPlaced >= dist)
        {
            count++;
            lastPlaced = arr[i];
            if (count == cows)
                return true;
        }
    }
    return false;
}

/**
 * Function: aggressiveCowsBrute
 * -----------------------------
 * Finds the largest minimum distance between cows using brute force.
 * - Iterates over all possible distances from `1` to `max-min`.
 * - Calls `isPossible` to check feasibility.
 * - Returns the maximum distance where cows can be placed.
 *
 * @param arr - Vector containing stall positions.
 * @param cows - Number of cows to be placed.
 * @return Maximum possible minimum distance between cows.
 *
 * Time Complexity: O(N * (max-min)) → Checking each distance.
 * Space Complexity: O(1)
 */
int aggressiveCowsBrute(vector<int> &arr, int cows)
{
    sort(arr.begin(), arr.end()); // Sorting stalls for sequential placement
    int minEl = arr[0], maxEl = arr[arr.size() - 1];

    for (int i = 1; i <= maxEl - minEl; i++)
    {
        if (!isPossible(arr, i, cows))
            return i - 1;
    }
    return -1;
}

/**
 * Function: aggressiveCowsOptimal
 * -------------------------------
 * Finds the largest minimum distance using binary search.
 * - Binary search on the minimum possible distance (low = 1, high = max-min).
 * - Uses `isPossible` to check feasibility.
 * - Returns the largest valid distance.
 *
 * @param arr - Vector containing stall positions.
 * @param cows - Number of cows to be placed.
 * @return Maximum possible minimum distance between cows.
 *
 * Time Complexity: O(N log(max-min)) → Binary search reduces range.
 * Space Complexity: O(1)
 */
int aggressiveCowsOptimal(vector<int> &arr, int cows)
{
    sort(arr.begin(), arr.end()); // Sorting is necessary for valid placement
    int low = 1, high = arr[arr.size() - 1] - arr[0], ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, mid, cows))
        {
            ans = mid;
            low = mid + 1; // Try larger minimum distance
        }
        else
        {
            high = mid - 1; // Reduce distance
        }
    }
    return ans;
}

// Driver Code with Robust Test Cases
int main()
{
    vector<vector<int>> testCases = {
        {1, 2, 8, 4, 9},           // Normal case
        {1, 3, 6, 10, 15},         // Large gaps between stalls
        {1, 2, 3, 4, 5},           // Small consecutive stalls
        {100, 200, 300, 400, 500}, // Large numbers
        {1, 5, 9, 13, 17},         // Even spacing
        {1, 3, 5, 7, 9, 11},       // Odd count of stalls
    };

    vector<int> cowCounts = {3, 2, 3, 2, 3, 3};

    cout << "Running Test Cases...\n";
    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Brute Force Result: " << aggressiveCowsBrute(testCases[i], cowCounts[i]) << endl;
        cout << "Optimal Result: " << aggressiveCowsOptimal(testCases[i], cowCounts[i]) << endl;
        cout << "--------------------------\n";
    }

    return 0;
}
