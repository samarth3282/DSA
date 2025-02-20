#include <bits/stdc++.h>
using namespace std;

/**
 * Function: insertPositionBruteForce
 * -----------------------------------
 * Finds the insert position of `target` in a sorted array by iterating through it.
 *
 * @param arr - Reference to a sorted vector of integers.
 * @param target - The value to insert.
 * @return The index where `target` should be inserted to maintain sorted order.
 *
 * Approach:
 * - Iterate through the array and find the first position where `arr[i] >= target`.
 * - If no such position exists, return `arr.size()` (insert at the end).
 *
 * T.C: O(N) - Linear scan.
 * S.C: O(1) - No extra space used.
 */
int insertPositionBruteForce(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= target)
            return i;
    }
    return arr.size();
}

/**
 * Function: insertPositionOptimal
 * --------------------------------
 * Uses binary search to efficiently find the insert position of `target` in a sorted array.
 *
 * @param arr - Reference to a sorted vector of integers.
 * @param target - The value to insert.
 * @return The index where `target` should be inserted.
 *
 * Approach:
 * - Perform binary search with `low` and `high` pointers.
 * - If `arr[mid] >= target`, update `ans` and move `high` leftward.
 * - Otherwise, move `low` rightward.
 * - The `ans` variable will store the final insert position.
 *
 * T.C: O(log N) - Binary search.
 * S.C: O(1) - No additional space used.
 */
int insertPositionOptimal(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size(); // Default position is the end

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Prevent overflow

        if (arr[mid] >= target)
        {
            ans = mid;      // Store potential insert position
            high = mid - 1; // Move left
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
 * Runs multiple test cases to validate both brute-force and optimal functions.
 * Prints results to compare correctness.
 */
void runTestCases()
{
    vector<vector<int>> testCases = {
        {},                      // 1. Empty array
        {5},                     // 2. Single element equal to target
        {5},                     // 3. Single element smaller than target
        {5},                     // 4. Single element greater than target
        {1, 3, 5, 7, 9},         // 5. Target smaller than all elements
        {1, 3, 5, 7, 9},         // 6. Target greater than all elements
        {1, 3, 5, 7, 9},         // 7. Target in the middle
        {2, 2, 2, 2, 2},         // 8. All elements equal to target
        {1, 2, 3, 4, 5, 6, 7},   // 9. Target at the beginning
        {1, 2, 3, 4, 5, 6, 7},   // 10. Target at the end
        {1, 2, 3, 5, 6, 7, 8, 9} // 11. Large sorted array
    };

    vector<int> targets = {
        3,  // Empty array (should return 0)
        5,  // Single element equal to target (should return 0)
        6,  // Single element smaller than target (should return 1)
        4,  // Single element greater than target (should return 0)
        0,  // Target smaller than all elements (should return 0)
        10, // Target greater than all elements (should return size of array)
        4,  // Target in the middle (should return correct index)
        2,  // All elements equal to target (should return first index)
        1,  // Target at the beginning (should return 0)
        7,  // Target at the end (should return correct index)
        5   // Large array case (should return correct index)
    };

    for (size_t i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": Array = { ";
        for (int num : testCases[i])
            cout << num << " ";
        cout << "}, Target = " << targets[i] << endl;

        int bruteResult = insertPositionBruteForce(testCases[i], targets[i]);
        int optResult = insertPositionOptimal(testCases[i], targets[i]);

        cout << "Brute Force Output: " << bruteResult << endl;
        cout << "Optimal Output: " << optResult << endl;
        cout << (bruteResult == optResult ? "✅ Test Passed" : "❌ Test Failed") << endl;
        cout << "------------------------------------------------------\n";
    }
}

int main()
{
    runTestCases();
    return 0;
}