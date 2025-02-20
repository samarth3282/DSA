#include <bits/stdc++.h>
using namespace std;

/**
 * Function: lowerBoundLibrary
 * ----------------------------
 * Uses the C++ STL function `lower_bound` to find the first position
 * where `target` can be inserted in a sorted array `arr` while maintaining order.
 *
 * @param arr - Reference to a sorted vector of integers.
 * @param target - The value to find the lower bound for.
 * @return The index of the first element that is not less than `target`.
 *
 * T.C: O(log N) - `lower_bound` internally uses binary search.
 * S.C: O(1) - No extra space used.
 */
int lowerBoundLibrary(vector<int> &arr, int target)
{
    return (lower_bound(arr.begin(), arr.end(), target) - arr.begin());
}

/**
 * Function: lowerBoundOptimal
 * ----------------------------
 * Implements the lower bound logic using binary search manually.
 * Finds the first occurrence of an element greater than or equal to `target`.
 *
 * @param arr - Reference to a sorted vector of integers.
 * @param target - The value to find the lower bound for.
 * @return The index of the first element that is not less than `target`.
 *
 * Approach:
 * - Perform binary search with `low` and `high` pointers.
 * - If `arr[mid]` >= `target`, update `ans` and move `high` leftward.
 * - Otherwise, move `low` rightward.
 * - Finally, return `ans`, which stores the first occurrence of `target` or the
 *   correct insert position.
 *
 * T.C: O(log N) - Standard binary search.
 * S.C: O(1) - No additional space used.
 */
int lowerBoundOptimal(vector<int> &arr, int target)
{
    int ans = arr.size(); // Default answer is the size of the array (out of bounds case)
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2; // Compute mid index

        if (arr[mid] >= target) // Check if current element is >= target
        {
            ans = mid;      // Store potential answer
            high = mid - 1; // Move left
        }
        else
            low = mid + 1; // Move right
    }
    return ans;
}

/**
 * Function: runTestCases
 * ----------------------
 * Runs multiple test cases to check correctness of lower bound functions.
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
        5, // Single element equal to target (should return 0)
        6, // Single element smaller than target (should return 1)
        4, // Single element greater than target (should return 0)
        0, // Target smaller than all elements (should return 0)
        6, // Target greater than all elements (should return size of array)
        3, // Target in the middle (should return index of first occurrence of 3)
        2, // All elements equal to target (should return index of first 2)
        3, // Multiple occurrences of target (should return index of first 3)
        1, // Target at the beginning (should return first index >= 1)
        7, // Target at the end (should return size of array)
        5  // Large array case
    };

    for (size_t i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": Array = { ";
        for (int num : testCases[i])
            cout << num << " ";
        cout << "}, Target = " << targets[i] << endl;

        int libResult = lowerBoundLibrary(testCases[i], targets[i]);
        int optResult = lowerBoundOptimal(testCases[i], targets[i]);

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
