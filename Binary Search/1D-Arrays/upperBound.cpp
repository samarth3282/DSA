#include <bits/stdc++.h>
using namespace std;

/**
 * Function: upperBoundLibrary
 * ----------------------------
 * Uses the C++ STL function `upper_bound` to find the first position
 * where `target` would appear *after* its last occurrence in a sorted array `arr`.
 *
 * @param arr - Reference to a sorted vector of integers.
 * @param target - The value to find the upper bound for.
 * @return The index of the first element strictly greater than `target`.
 *
 * T.C: O(log N) - `upper_bound` internally uses binary search.
 * S.C: O(1) - No extra space used.
 */
int upperBoundLibrary(vector<int> &arr, int target)
{
    return (upper_bound(arr.begin(), arr.end(), target) - arr.begin());
}

/**
 * Function: upperBoundOptimal
 * ----------------------------
 * Implements the upper bound logic using binary search manually.
 * Finds the first occurrence of an element strictly greater than `target`.
 *
 * @param arr - Reference to a sorted vector of integers.
 * @param target - The value to find the upper bound for.
 * @return The index of the first element greater than `target`.
 *         If no such element exists, returns the array size.
 *
 * Approach:
 * - Perform binary search with `low` and `high` pointers.
 * - If `arr[mid]` > `target`, store `ans` and move `high` leftward.
 * - Otherwise, move `low` rightward.
 * - Finally, return `ans`, which stores the first element greater than `target`.
 *
 * T.C: O(log N) - Standard binary search.
 * S.C: O(1) - No extra space used.
 */
int upperBoundOptimal(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size(); // Default to array size, meaning no greater element exists

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > target) // Check if current element is greater than the target
        {
            ans = mid;      // Store potential answer
            high = mid - 1; // Move left to find first occurrence
        }
        else
        {
            low = mid + 1; // Move right
        }
    }
    return ans;
}

/**
 * Function: runTestCases
 * ----------------------
 * Runs multiple test cases to check correctness of upper bound functions.
 * Prints results from both library and optimal implementations.
 */
void runTestCases()
{
    vector<vector<int>> testCases = {
        {},                             // 1. Empty array
        {5},                            // 2. Single element equal to target
        {5},                            // 3. Single element smaller than target
        {5},                            // 4. Single element greater than target
        {1, 2, 3, 4, 5},                // 5. Target smaller than all elements
        {1, 2, 3, 4, 5},                // 6. Target greater than all elements
        {1, 2, 3, 4, 5},                // 7. Target in the middle (normal case)
        {2, 2, 2, 2, 2},                // 8. All elements equal to target
        {1, 2, 2, 3, 3, 3, 4},          // 9. Multiple occurrences of target
        {1, 2, 3, 4, 5, 6, 7},          // 10. Target at the beginning
        {1, 2, 3, 4, 5, 6, 7},          // 11. Target at the end
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} // 12. Large sorted array
    };

    vector<int> targets = {
        3, // Empty array (should return 0)
        5, // Single element equal to target (should return 1)
        6, // Single element smaller than target (should return 1)
        4, // Single element greater than target (should return 0)
        0, // Target smaller than all elements (should return 0)
        6, // Target greater than all elements (should return size of array)
        3, // Target in the middle (should return index after last occurrence of 3)
        2, // All elements equal to target (should return index after last 2)
        3, // Multiple occurrences of target (should return index after last 3)
        1, // Target at the beginning (should return first index > 1)
        7, // Target at the end (should return size of array)
        5  // Large array case
    };

    for (size_t i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": Array = { ";
        for (int num : testCases[i])
            cout << num << " ";
        cout << "}, Target = " << targets[i] << endl;

        int libResult = upperBoundLibrary(testCases[i], targets[i]);
        int optResult = upperBoundOptimal(testCases[i], targets[i]);

        cout << "Library Function Output: " << libResult << endl;
        cout << "Optimal Function Output: " << optResult << endl;
        cout << (libResult == optResult ? "✅ Test Passed" : "❌ Test Failed") << endl;
        cout << "------------------------------------------------------\n";
    }
}

int main()
{
    runTestCases();
    return 0;
}