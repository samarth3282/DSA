#include <bits/stdc++.h>
using namespace std;

/**
 * Function: removeDuplicatesInPlaceFromSortedArrayBrute
 * -----------------------------------------------------
 * Brute force solution that leverages a `set` to store unique elements.
 * Since `set` maintains sorted order and removes duplicates, this simplifies the process.
 *
 * @param arrGiven - Reference to the sorted array with possible duplicates.
 * @return New size of the array after removing duplicates.
 *
 * Time Complexity: O(n log n) - Inserting each element in the set
 * Space Complexity: O(n) - Set stores unique elements
 */
int removeDuplicatesInPlaceFromSortedArrayBrute(vector<int> &arrGiven)
{
    set<int> st; // Set to store unique elements (automatically sorted)

    // Insert all elements into the set (O(n log n))
    for (int i = 0; i < arrGiven.size(); i++)
    {
        st.insert(arrGiven[i]);
    }

    // Copy unique elements back to the array (O(n))
    int index = 0;
    for (auto it : st)
    {
        arrGiven[index] = it;
        index++;
    }

    // Return the new size of the array (number of unique elements)
    return index;
}

/**
 * Function: removeDuplicatesInPlaceFromSortedArrayOptimal
 * -------------------------------------------------------
 * Optimal solution using the two-pointer technique to modify the array in place.
 * Since the array is sorted, duplicates are always consecutive, simplifying logic.
 *
 * @param arrGiven - Reference to the sorted array with possible duplicates.
 * @return New size of the array after removing duplicates.
 *
 * Time Complexity: O(n) - Single pass through the array
 * Space Complexity: O(1) - In-place modification, no extra space
 */
int removeDuplicatesInPlaceFromSortedArrayOptimal(vector<int> &arrGiven)
{
    // Edge Case: Empty array
    if (arrGiven.size() == 0)
        return 0;

    int index = 1; // Points to the position for the next unique element

    // Iterate through the array (O(n))
    for (int i = 1; i < arrGiven.size(); i++)
    {
        // If the current element is different from the previous one,
        // place it at the `index` position (maintaining order)
        if (arrGiven[i] != arrGiven[i - 1])
        {
            arrGiven[index] = arrGiven[i];
            index++;
        }
    }

    // Return the count of unique elements
    return index;
}

// Driver Code with Robust Test Cases
int main()
{
    vector<vector<int>> testCases = {
        {1, 1, 2, 2, 2, 3, 3},   // Standard case
        {1, 1, 1, 1},            // All identical elements
        {1, 2, 3, 4, 5},         // No duplicates
        {},                      // Empty array
        {1, 2, 2, 3, 4, 4, 5, 5} // Multiple duplicates
    };

    cout << "Testing Optimal Solution:\n";
    for (int i = 0; i < testCases.size(); i++)
    {
        vector<int> v = testCases[i];

        int newSize = removeDuplicatesInPlaceFromSortedArrayOptimal(v);

        cout << "Test Case " << i + 1 << ": ";
        cout << "New Size = " << newSize << ", Modified Array = ";
        for (int j = 0; j < newSize; j++)
        {
            cout << v[j] << " ";
        }
        cout << endl;
    }

    cout << "\nTesting Brute Force Solution:\n";
    for (int i = 0; i < testCases.size(); i++)
    {
        vector<int> v = testCases[i];

        int newSize = removeDuplicatesInPlaceFromSortedArrayBrute(v);

        cout << "Test Case " << i + 1 << ": ";
        cout << "New Size = " << newSize << ", Modified Array = ";
        for (int j = 0; j < newSize; j++)
        {
            cout << v[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
