#include <bits/stdc++.h>
using namespace std;

/**
 * Function: findUniqueElementBruteForce
 * -------------------------------------
 * Uses two nested loops to check the frequency of each element.
 * If an element appears only once, returns it.
 *
 * @param arr - Reference to an integer vector.
 * @return The unique element in the array.
 *
 * Approach:
 * - Iterate through the array using two loops.
 * - Count occurrences of each element.
 * - If an element appears only once, return it.
 *
 * T.C: O(N^2) - Nested loops.
 * S.C: O(1) - No extra space used.
 */
int findUniqueElementBruteForce(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count == 1)
            return arr[i]; // Unique element found
    }
    return -1; // No unique element
}

/**
 * Function: findUniqueElementUsingMap
 * -----------------------------------
 * Uses an unordered_map (hash table) to count occurrences of each element.
 * Returns the element with frequency = 1.
 *
 * @param arr - Reference to an integer vector.
 * @return The unique element in the array.
 *
 * Approach:
 * - Use a hash map to store frequency counts.
 * - Iterate through the array and return the element with count = 1.
 *
 * T.C: O(N) - Single pass to build map, single pass to find unique element.
 * S.C: O(N) - Extra space for hash map.
 */
int findUniqueElementUsingMap(vector<int> &arr)
{
    unordered_map<int, int> freqMap;
    for (int num : arr)
        freqMap[num]++;

    for (int num : arr)
    {
        if (freqMap[num] == 1)
            return num;
    }
    return -1; // No unique element
}

/**
 * Function: singleNonDuplicateIndexChecking
 * --------------------------------------
 * Finds the single non-duplicate element using index checking.
 * - Compares each element with its neighbors.
 *
 * T.C: O(N) - Linear traversal.
 * S.C: O(1) - No extra space used.
 */
int singleNonDuplicateIndexChecking(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];

    for (int i = 0; i < n; i++)
    {
        if ((i == 0 && arr[i] != arr[i + 1]) ||
            (i == n - 1 && arr[i] != arr[i - 1]) ||
            (i > 0 && i < n - 1 && arr[i] != arr[i - 1] && arr[i] != arr[i + 1]))
            return arr[i];
    }
    return -1;
}

/**
 * Function: findUniqueElementUsingXOR
 * -----------------------------------
 * Uses XOR operation to find the unique element in an array where all other
 * elements appear twice.
 *
 * @param arr - Reference to an integer vector.
 * @return The unique element in the array.
 *
 * Approach:
 * - XOR of two same numbers is 0.
 * - XOR of a number with 0 is the number itself.
 * - XORing all elements cancels out pairs, leaving the unique element.
 *
 * T.C: O(N) - Single pass through the array.
 * S.C: O(1) - No extra space used.
 */
int findUniqueElementUsingXOR(vector<int> &arr)
{
    int uniqueElement = 0;
    for (int num : arr)
        uniqueElement ^= num; // XOR each element

    return uniqueElement;
}

/**
 * Function: findUniqueElementOptimal
 * ----------------------------------
 * Uses the XOR approach but assumes numbers appear an odd number of times.
 * Works for large numbers efficiently.
 *
 * @param arr - Reference to an integer vector.
 * @return The unique element in the array.
 *
 * Approach:
 * - If numbers appear thrice except for one, use bit manipulation:
 *   - Maintain a count of bits at each position.
 *   - Use modulo 3 operation to extract the unique element.
 *
 * T.C: O(N) - Single pass through the array.
 * S.C: O(1) - Constant extra space used.
 */
int findUniqueElementOptimal(vector<int> &arr)
{
    int ones = 0, twos = 0;
    for (int num : arr)
    {
        ones = (ones ^ num) & (~twos);
        twos = (twos ^ num) & (~ones);
    }
    return ones;
}

/**
 * Function: runTestCases
 * ----------------------
 * Runs multiple test cases to validate all approaches.
 */
void runTestCases()
{
    vector<vector<int>> testCases = {
        {4, 3, 2, 4, 3, 2, 1}, // Unique element: 1
        {7, 3, 5, 3, 5, 7, 9}, // Unique element: 9
        {1, 1, 2},             // Unique element: 2
        {10, 20, 10, 20, 30},  // Unique element: 30
        {42},                  // Unique element: 42 (single element case)
        {2, 2, 3, 3, 4, 4, 5}, // Unique element: 5
    };

    for (size_t i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": { ";
        for (int num : testCases[i])
            cout << num << " ";
        cout << "}" << endl;

        cout << "Brute Force Result: " << findUniqueElementBruteForce(testCases[i]) << endl;
        cout << "Using Map Result: " << findUniqueElementUsingMap(testCases[i]) << endl;
        cout << "Using XOR Result: " << findUniqueElementUsingXOR(testCases[i]) << endl;
        cout << "Optimal Result: " << findUniqueElementOptimal(testCases[i]) << endl;

        cout << "------------------------------------------------------\n";
    }
}

int main()
{
    runTestCases();
    return 0;
}
