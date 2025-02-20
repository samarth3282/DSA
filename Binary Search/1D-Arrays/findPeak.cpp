#include <bits/stdc++.h>
using namespace std;

// Brute-force Approach: Linear Scan
// Time Complexity: O(N), Space Complexity: O(1)
int findPeakElementBrute(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (((i == 0) || (arr[i - 1] < arr[i])) && ((i == arr.size() - 1) || (arr[i] > arr[i + 1])))
            return i; // Returning index instead of value
    }
    return -1;
}

// Better Approach: Using Iterative Binary Search (Without Extra Conditions)
// Time Complexity: O(log N), Space Complexity: O(1)
int findPeakElementBetter(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1])
            high = mid; // Move left
        else
            low = mid + 1; // Move right
    }
    return low; // 'low' will always point to a peak element
}

// Optimal Approach: Using Binary Search with Edge Cases Handled Separately
// Time Complexity: O(log N), Space Complexity: O(1)
int findPeakElementOptimal(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            return mid;
        else if (arr[mid] > arr[mid + 1])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// Driver Code with Test Cases
int main()
{
    vector<int> arr1 = {1, 2, 3, 1};
    vector<int> arr2 = {1, 2, 1, 3, 5, 6, 4};
    vector<int> arr3 = {10, 20, 30, 40, 50};
    vector<int> arr4 = {50, 40, 30, 20, 10};
    vector<int> arr5 = {1, 2, 3, 4, 5, 3, 1};

    cout << "Brute Force: " << findPeakElementBrute(arr1) << endl;
    cout << "Better Approach: " << findPeakElementBetter(arr1) << endl;
    cout << "Optimal Approach: " << findPeakElementOptimal(arr1) << endl;

    cout << "Brute Force: " << findPeakElementBrute(arr2) << endl;
    cout << "Better Approach: " << findPeakElementBetter(arr2) << endl;
    cout << "Optimal Approach: " << findPeakElementOptimal(arr2) << endl;

    return 0;
}
