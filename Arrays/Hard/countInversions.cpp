#include <bits/stdc++.h>
using namespace std;

/**
 * Brute-force approach to count inversions.
 * An inversion is a pair (i, j) such that i < j and arr[i] > arr[j].
 *
 * T.C: O(n^2) - Nested loop iterating over all pairs.
 * S.C: O(1) - No extra space used.
 */
int countInversionsBrute(vector<int> &arr)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
                cnt++;
        }
    }
    return cnt;
}

/**
 * Merge function to count inversions while merging two sorted halves.
 *
 * T.C: O(n) - Each element is processed once during merging.
 * S.C: O(n) - Temporary array used for merging.
 */
int merge(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    int left = low, right = mid + 1;
    vector<int> temp;

    // Merge two sorted halves and count inversions
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
            cnt += mid - left + 1; // Count inversions
        }
    }

    // Copy remaining elements
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);

    // Copy sorted elements back to original array
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];

    return cnt;
}

/**
 * Merge sort function to count inversions optimally.
 *
 * T.C: O(n log n) - Standard merge sort complexity.
 * S.C: O(n) - Extra space used for merging.
 */
int mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0; // Base case: Single element

    int mid = (low + high) / 2;
    int cnt = 0;

    cnt += mergeSort(arr, low, mid);      // Count inversions in left half
    cnt += mergeSort(arr, mid + 1, high); // Count inversions in right half
    cnt += merge(arr, low, mid, high);    // Merge and count cross inversions

    return cnt;
}

/**
 * Wrapper function to count inversions using merge sort.
 */
int countInversionsOptimal(vector<int> &arr)
{
    return mergeSort(arr, 0, arr.size() - 1);
}

int main()
{
    vector<vector<int>> test_cases = {
        {1, 3, 2, 3, 1},       // Normal case with duplicate elements
        {5, 4, 3, 2, 1},       // Reverse sorted array (max inversions)
        {1, 2, 3, 4, 5},       // Already sorted array (no inversions)
        {-1, -2, -3, -4, -5},  // Negative numbers (should work like positives)
        {1},                   // Single-element array
        {1, 3, 5, 2, 4, 6},    // Mixed order
        {2147483647, 1, 0, -1} // Large integer values
    };

    for (auto &test_case : test_cases)
    {
        vector<int> arr1 = test_case, arr2 = test_case;

        int bruteForceCount = countInversionsBrute(arr1);
        int optimizedCount = countInversionsOptimal(arr2);

        cout << "Array: ";
        for (int num : test_case)
            cout << num << " ";
        cout << "\nBrute-force Inversions: " << bruteForceCount;
        cout << "\nOptimized Inversions: " << optimizedCount << "\n\n";
    }

    return 0;
}
