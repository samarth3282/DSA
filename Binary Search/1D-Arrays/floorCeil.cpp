#include <bits/stdc++.h>
using namespace std;

/**
 * Function: findFloorBruteForce
 * -----------------------------
 * Finds the largest element in the sorted array that is <= `x` by linear search.
 *
 * @param arr - The input sorted array.
 * @param n - Size of the array.
 * @param x - The target value.
 * @return The floor value (largest number ≤ x), or -1 if not found.
 *
 * T.C: O(N) - Linear scan.
 * S.C: O(1) - No extra space used.
 */
int findFloorBruteForce(int arr[], int n, int x)
{
    int floor = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= x)
            floor = arr[i];
        else
            break; // Since the array is sorted, we can stop early
    }
    return floor;
}

/**
 * Function: findCeilBruteForce
 * ----------------------------
 * Finds the smallest element in the sorted array that is ≥ `x` by linear search.
 *
 * @param arr - The input sorted array.
 * @param n - Size of the array.
 * @param x - The target value.
 * @return The ceil value (smallest number ≥ x), or -1 if not found.
 *
 * T.C: O(N) - Linear scan.
 * S.C: O(1) - No extra space used.
 */
int findCeilBruteForce(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= x)
            return arr[i];
    }
    return -1;
}

/**
 * Function: findFloorOptimal
 * --------------------------
 * Uses binary search to find the largest element that is ≤ `x`.
 *
 * @param arr - The input sorted array.
 * @param n - Size of the array.
 * @param x - The target value.
 * @return The floor value (largest number ≤ x), or -1 if not found.
 *
 * Approach:
 * - Perform binary search with `low` and `high`.
 * - If `arr[mid] ≤ x`, store `ans` and move `low` rightward.
 * - Otherwise, move `high` leftward.
 *
 * T.C: O(log N) - Binary search.
 * S.C: O(1) - No extra space used.
 */
int findFloorOptimal(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
        {
            ans = arr[mid]; // Store potential floor
            low = mid + 1;  // Move right
        }
        else
        {
            high = mid - 1; // Move left
        }
    }
    return ans;
}

/**
 * Function: findCeilOptimal
 * -------------------------
 * Uses binary search to find the smallest element that is ≥ `x`.
 *
 * @param arr - The input sorted array.
 * @param n - Size of the array.
 * @param x - The target value.
 * @return The ceil value (smallest number ≥ x), or -1 if not found.
 *
 * Approach:
 * - Perform binary search with `low` and `high`.
 * - If `arr[mid] ≥ x`, store `ans` and move `high` leftward.
 * - Otherwise, move `low` rightward.
 *
 * T.C: O(log N) - Binary search.
 * S.C: O(1) - No extra space used.
 */
int findCeilOptimal(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = arr[mid]; // Store potential ceil
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
 * Function: getFloorAndCeilOptimal
 * --------------------------------
 * Finds both floor and ceil of `x` using binary search.
 *
 * @param arr - The input sorted array.
 * @param n - Size of the array.
 * @param x - The target value.
 * @return A pair of integers {floor, ceil}.
 *
 * T.C: O(log N) - Calls two binary searches.
 * S.C: O(1) - No extra space used.
 */
pair<int, int> getFloorAndCeilOptimal(int arr[], int n, int x)
{
    int floor = findFloorOptimal(arr, n, x);
    int ceil = findCeilOptimal(arr, n, x);
    return {floor, ceil};
}

/**
 * Function: runTestCases
 * ----------------------
 * Runs multiple test cases to validate both brute-force and optimal functions.
 */
void runTestCases()
{
    vector<vector<int>> testCases = {
        {},                      // 1. Empty array
        {5},                     // 2. Single element equal to x
        {5},                     // 3. Single element smaller than x
        {5},                     // 4. Single element greater than x
        {1, 3, 5, 7, 9},         // 5. x smaller than all elements
        {1, 3, 5, 7, 9},         // 6. x greater than all elements
        {1, 3, 5, 7, 9},         // 7. x in the middle
        {2, 2, 2, 2, 2},         // 8. All elements equal to x
        {1, 2, 3, 4, 5, 6, 7},   // 9. x at the beginning
        {1, 2, 3, 4, 5, 6, 7},   // 10. x at the end
        {1, 2, 3, 5, 6, 7, 8, 9} // 11. Large sorted array
    };

    vector<int> targets = {3, 5, 6, 4, 0, 10, 4, 2, 1, 7, 5};

    for (size_t i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": Array = { ";
        for (int num : testCases[i])
            cout << num << " ";
        cout << "}, Target = " << targets[i] << endl;

        int bruteFloor = findFloorBruteForce(testCases[i].data(), testCases[i].size(), targets[i]);
        int bruteCeil = findCeilBruteForce(testCases[i].data(), testCases[i].size(), targets[i]);

        pair<int, int> optResult = getFloorAndCeilOptimal(testCases[i].data(), testCases[i].size(), targets[i]);

        cout << "Brute Force Floor: " << bruteFloor << ", Ceil: " << bruteCeil << endl;
        cout << "Optimal Floor: " << optResult.first << ", Ceil: " << optResult.second << endl;
        cout << ((bruteFloor == optResult.first && bruteCeil == optResult.second) ? "✅ Test Passed" : "❌ Test Failed") << endl;
        cout << "------------------------------------------------------\n";
    }
}

int main()
{
    runTestCases();
    return 0;
}
