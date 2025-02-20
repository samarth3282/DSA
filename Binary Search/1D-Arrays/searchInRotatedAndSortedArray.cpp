#include <bits/stdc++.h>
using namespace std;

/**
 * Function: searchBruteForce
 * --------------------------
 * Performs a linear search on the rotated sorted array to find `target`.
 *
 * @param arr - Reference to a vector of integers (rotated sorted array).
 * @param target - The element to find.
 * @return The index of `target`, or -1 if not found.
 *
 * T.C: O(N) - Linear search through the array.
 * S.C: O(1) - No extra space used.
 */
int searchBruteForce(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

/**
 * Function: searchInRotatedAndSorted
 * ----------------------------------
 * Uses binary search to find the index of `target` in a rotated sorted array.
 *
 * @param arr - Reference to a vector of integers (rotated sorted array).
 * @param target - The element to find.
 * @return The index of `target`, or -1 if not found.
 *
 * Approach:
 * - Perform binary search with `low` and `high`.
 * - Check if `arr[mid]` is the target.
 * - Determine which half (left or right) is sorted.
 * - If `target` lies in the sorted half, move `low` or `high` accordingly.
 *
 * T.C: O(log N) - Binary search reduces search space by half each time.
 * S.C: O(1) - No extra space used.
 */
int searchInRotatedAndSorted(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid; // Found target

        // Check which half is sorted
        if (arr[low] <= arr[mid]) // Left half is sorted
        {
            if (arr[low] <= target && target <= arr[mid])
                high = mid - 1; // Search in the left half
            else
                low = mid + 1; // Search in the right half
        }
        else // Right half is sorted
        {
            if (arr[mid] <= target && target <= arr[high])
                low = mid + 1; // Search in the right half
            else
                high = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

/**
 * Function: runTestCases
 * ----------------------
 * Runs multiple test cases to validate both brute-force and optimal functions.
 */
void runTestCases()
{
    vector<vector<int>> testCases = {
        {4, 5, 6, 7, 0, 1, 2}, // 1. Normal rotated case
        {6, 7, 1, 2, 3, 4, 5}, // 2. Rotated at mid
        {1},                   // 3. Single element - match
        {1},                   // 4. Single element - no match
        {},                    // 5. Empty array
        {3, 4, 5, 1, 2},       // 6. Small rotated case
        {1, 2, 3, 4, 5},       // 7. Not rotated (normal sorted array)
        {10, 20, 30, 40, 50},  // 8. No rotation and target absent
    };

    vector<int> targets = {0, 3, 1, 2, 5, 4, 2, 35}; // Targets for each test case

    for (size_t i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": Array = { ";
        for (int num : testCases[i])
            cout << num << " ";
        cout << "}, Target = " << targets[i] << endl;

        int bruteIndex = searchBruteForce(testCases[i], targets[i]);
        int optIndex = searchInRotatedAndSorted(testCases[i], targets[i]);

        cout << "Brute Force Index: " << bruteIndex << endl;
        cout << "Optimal Index: " << optIndex << endl;
        cout << ((bruteIndex == optIndex) ? "✅ Test Passed" : "❌ Test Failed") << endl;
        cout << "------------------------------------------------------\n";
    }
}

int main()
{
    runTestCases();
    return 0;
}
