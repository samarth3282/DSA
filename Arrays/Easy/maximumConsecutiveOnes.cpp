#include <bits/stdc++.h>
using namespace std;

/**
 * Function: maximumConsecutiveOnesBrute
 * -------------------------------------
 * Brute force approach that checks all subarrays and counts consecutive 1s.
 * For each starting point, iterates through the array to count maximum consecutive 1s.
 *
 * @param arr - Reference to the binary array.
 * @return The maximum number of consecutive 1s.
 *
 * Time Complexity: O(n^2) - Each starting point iterates through remaining elements.
 * Space Complexity: O(1) - No extra space used.
 */
int maximumConsecutiveOnesBrute(vector<int> &arr)
{
    int maxLength = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int cnt = 0;

        for (int j = i; j < arr.size(); j++)
        {
            if (arr[j] == 1)
                cnt++;
            else
                break;

            maxLength = max(maxLength, cnt);
        }
    }

    return maxLength;
}

/**
 * Function: maximumConsecutiveOnesBetter
 * --------------------------------------
 * Better approach using a counter variable to track consecutive 1s directly.
 * Efficiently identifies maximum consecutive 1s with a single traversal.
 *
 * @param arr - Reference to the binary array.
 * @return The maximum number of consecutive 1s.
 *
 * Time Complexity: O(n) - Single pass through the array.
 * Space Complexity: O(1) - In-place calculation without extra space.
 */
int maximumConsecutiveOnesBetter(vector<int> &arr)
{
    int maxLength = 0;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            cnt++;
            maxLength = max(maxLength, cnt);
        }
        else
        {
            cnt = 0; // Reset counter when encountering a 0
        }
    }

    return maxLength;
}

/**
 * Function: maximumConsecutiveOnesOptimal
 * ---------------------------------------
 * Optimal approach is identical to the "Better" approach since it achieves O(n) complexity.
 * No further improvement is possible for this problem in terms of time complexity.
 *
 * @param arr - Reference to the binary array.
 * @return The maximum number of consecutive 1s.
 *
 * Time Complexity: O(n) - Single traversal with constant space usage.
 * Space Complexity: O(1) - In-place calculation without extra space.
 */
int maximumConsecutiveOnesOptimal(vector<int> &arr)
{
    return maximumConsecutiveOnesBetter(arr); // Optimal is identical to the better approach
}

// Driver Code with Robust Test Cases
int main()
{
    vector<vector<int>> testCases = {
        {1, 1, 0, 1, 1, 1},       // Standard case with mixed 1s and 0s
        {1, 1, 1, 1, 1},          // All 1s (maximum consecutive ones equals array size)
        {0, 0, 0, 0},             // All 0s (maximum consecutive ones = 0)
        {1, 0, 1, 0, 1, 1, 0, 1}, // Alternating pattern
        {1},                      // Single element: 1
        {0},                      // Single element: 0
        {}                        // Empty array
    };

    cout << "Running Test Cases...\n";
    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Brute Force Result: " << maximumConsecutiveOnesBrute(testCases[i]) << endl;
        cout << "Better Approach Result: " << maximumConsecutiveOnesBetter(testCases[i]) << endl;
        cout << "Optimal Approach Result: " << maximumConsecutiveOnesOptimal(testCases[i]) << endl;
        cout << "--------------------------\n";
    }

    return 0;
}
