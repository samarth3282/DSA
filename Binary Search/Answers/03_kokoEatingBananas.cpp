#include <bits/stdc++.h>
using namespace std;

/**
 * Function: kokoEatingBananasBrute
 * --------------------------------
 * This function finds the minimum eating speed using a brute-force approach.
 * - Iterates over all possible speeds from 1 to max pile size.
 * - Checks total time required at each speed.
 * - Returns the first speed that fits within the given hours `h`.
 *
 * @param arr - Vector containing pile sizes.
 * @param h - Number of hours available.
 * @return Minimum eating speed needed.
 *
 * Time Complexity: O(N * maxPile) → (N = number of piles, maxPile = max bananas in a pile)
 * Space Complexity: O(1) → No extra space used.
 */
int kokoEatingBananasBrute(vector<int> &arr, int h)
{
    int maxPile = *max_element(arr.begin(), arr.end()); // Find the largest pile
    for (int speed = 1; speed <= maxPile; speed++)
    {
        int totalTime = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            totalTime += ceil((double)arr[j] / speed); // Accumulate total time
        }
        if (totalTime <= h)
            return speed; // Minimum valid speed found
    }
    return maxPile;
}

/**
 * Function: kokoEatingBananasOptimal
 * ----------------------------------
 * This function finds the minimum eating speed using Binary Search.
 * - The search space is between 1 and the maximum pile size.
 * - Uses binary search to find the smallest valid speed.
 * - If total hours needed is within limit `h`, reduce speed.
 * - Otherwise, increase speed.
 *
 * @param arr - Vector containing pile sizes.
 * @param h - Number of hours available.
 * @return Minimum eating speed needed.
 *
 * Time Complexity: O(N log maxPile) → Binary search reduces range exponentially.
 * Space Complexity: O(1) → No extra space used.
 */
int kokoEatingBananasOptimal(vector<int> &arr, int h)
{
    int low = 1, high = *max_element(arr.begin(), arr.end()); // Search range
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Avoid overflow
        int totalTime = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            totalTime += ceil((double)arr[i] / (double)mid);
        }

        if (totalTime <= h)
            high = mid - 1; // Try to minimize speed
        else
            low = mid + 1; // Increase speed
    }
    return low; // The minimum valid speed
}

// Driver Code with Robust Test Cases
int main()
{
    vector<vector<int>> testCases = {
        {3, 6, 7, 11},            // Normal case
        {10},                     // Single pile
        {1, 1, 1, 1, 1, 1, 1, 1}, // All small values
        {30, 11, 23, 4, 20},      // Already fits within h
        {100, 10, 10, 10},        // Large max pile
        {1000000000, 999999999},  // Extreme large values
        {30, 11, 23, 4, 20}       // Edge case: only 1 hour
    };

    vector<int> hours = {8, 5, 8, 5, 10, 2, 1};

    cout << "Running Test Cases...\n";
    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Brute Force Result: " << kokoEatingBananasBrute(testCases[i], hours[i]) << endl;
        cout << "Optimal Result: " << kokoEatingBananasOptimal(testCases[i], hours[i]) << endl;
        cout << "--------------------------\n";
    }

    return 0;
}
