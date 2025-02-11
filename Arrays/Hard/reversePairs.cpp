#include <bits/stdc++.h>
using namespace std;

/**
 * Brute-force approach to count reverse pairs.
 * A reverse pair is defined as (i, j) such that i < j and arr[i] > 2 * arr[j].
 *
 * T.C: O(n^2) - Two nested loops iterating over all pairs.
 * S.C: O(1) - No extra space used.
 */
int reversePairsBrute(vector<int> &arr)
{
    int cnt = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > 2LL * arr[j])
                cnt++;
        }
    }
    return cnt;
}

/**
 * Function to merge two sorted halves of the array.
 * It also ensures that the final merged array remains sorted.
 *
 * T.C: O(n) - Each element is inserted into the temp array once and copied back.
 * S.C: O(n) - Additional temporary array `temp` of size equal to the merged range.
 */
void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low, right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }

    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

/**
 * Function to count reverse pairs in the given range of the array.
 * A reverse pair is defined as (i, j) such that i < j and arr[i] > 2 * arr[j].
 *
 * T.C: O(n) - Each element is checked at most once in the worst case.
 * S.C: O(1) - No extra space is used apart from a few integer variables.
 */
int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    int right = mid + 1;

    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2LL * arr[right])
            right++;

        cnt += (right - mid - 1);
    }

    return cnt;
}

/**
 * Merge sort function that recursively sorts the array and counts reverse pairs.
 *
 * T.C: O(n log n) - Standard merge sort complexity, with additional O(n) per merge step.
 * S.C: O(n) - Temporary array used in merge function.
 */
int mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0; // Base case: Single element or invalid range

    int mid = (low + high) / 2;
    int cnt = 0;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);

    return cnt;
}

/**
 * Driver function to test both brute-force and optimized approaches.
 */
int main()
{
    vector<vector<int>> test_cases = {
        {1, 3, 2, 3, 1},        // Normal case with duplicates
        {5, 4, 3, 2, 1},        // Reverse sorted array
        {1, 2, 3, 4, 5},        // Already sorted array
        {-1, -2, -3, -4, -5},   // Negative numbers
        {1},                    // Single-element array
        {2147483647, 1, 0, -1}, // Large integer edge case
        {10, 100, 1, 200, 2}    // Mix of large and small numbers
    };

    for (auto &test_case : test_cases)
    {
        vector<int> arr1 = test_case;
        vector<int> arr2 = test_case;

        int bruteForcePairs = reversePairsBrute(arr1);
        int optimizedPairs = mergeSort(arr2, 0, arr2.size() - 1);

        cout << "Test case: ";
        for (int num : test_case)
            cout << num << " ";
        cout << "\n";

        cout << "Brute-force Reverse Pairs: " << bruteForcePairs << endl;
        cout << "Optimized Reverse Pairs: " << optimizedPairs << endl;
        cout << "-------------------------------\n";
    }

    return 0;
}
