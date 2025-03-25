#include <bits/stdc++.h>
using namespace std;

/**
 * Function: twoSumBrute
 * ---------------------
 * Brute Force Approach - O(n²)
 * Compares each pair of elements to find the required target sum.
 *
 * @param arr[] - Input array of integers.
 * @param size - Size of the array.
 * @param k - Target sum to find.
 * @return Indices of two elements that add up to the target sum.
 *
 * Time Complexity: O(n²) - Double nested loop.
 * Space Complexity: O(1) - No extra data structure used.
 */
vector<int> twoSumBrute(int arr[], int size, int k)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++) // Avoid duplicate pairs
        {
            if (arr[i] + arr[j] == k)
            {
                return {i, j};
            }
        }
    }
    return {};
}

/**
 * Function: twoSumBetter
 * ----------------------
 * Better Approach using Hash Map - O(n)
 * Efficiently tracks the required pair by storing seen elements.
 *
 * @param arr - Input vector of integers.
 * @param target - Target sum to find.
 * @return Indices of two elements that add up to the target sum.
 *
 * Time Complexity: O(n) - Single traversal with hash map lookups.
 * Space Complexity: O(n) - Hash map stores seen elements.
 */
vector<int> twoSumBetter(vector<int> &arr, int target)
{
    map<int, int> mpp; // Stores element -> index
    for (int i = 0; i < arr.size(); i++)
    {
        int complement = target - arr[i];
        if (mpp.find(complement) != mpp.end())
        {
            return {mpp[complement], i};
        }
        mpp[arr[i]] = i; // Store element with its index
    }
    return {};
}

/**
 * Function: twoSumOptimal
 * -----------------------
 * Optimal Approach using Two Pointers - O(n log n)
 * Efficiently finds the required pair in sorted order.
 *
 * @param arr - Input vector of integers (must be sorted).
 * @param target - Target sum to find.
 * @return Indices of two elements that add up to the target sum.
 *
 * Time Complexity: O(n log n) - Sorting + O(n) Two-pointer technique.
 * Space Complexity: O(1) - No extra space required.
 */
vector<int> twoSumOptimal(vector<int> &arr, int target)
{
    vector<pair<int, int>> nums; // Store {element, original index}
    for (int i = 0; i < arr.size(); i++)
    {
        nums.push_back({arr[i], i});
    }

    sort(nums.begin(), nums.end()); // Sorting for two-pointer approach

    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int sum = nums[left].first + nums[right].first;

        if (sum == target)
        {
            return {nums[left].second, nums[right].second}; // Return original indices
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return {};
}

// Driver Code with Robust Test Cases
int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};

    cout << "Brute Force Approach: ";
    vector<int> brute = twoSumBrute(arr.data(), arr.size(), 14);
    for (auto it : brute)
        cout << it << " ";
    cout << endl;

    cout << "Better Approach: ";
    vector<int> better = twoSumBetter(arr, 14);
    for (auto it : better)
        cout << it << " ";
    cout << endl;

    cout << "Optimal Approach: ";
    vector<int> optimal = twoSumOptimal(arr, 14);
    for (auto it : optimal)
        cout << it << " ";
    cout << endl;

    return 0;
}
