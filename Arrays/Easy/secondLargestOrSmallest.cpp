#include <bits/stdc++.h>
using namespace std;

// Function to partition the array for QuickSort
int findPartition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Pivot element is the first element
    int i = low;
    int j = high;

    while (i < j)
    {
        // Move i to the right until element greater than pivot is found
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        // Move j to the left until element smaller than or equal to pivot is found
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        // Swap elements to maintain partition order
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    // Place pivot in its correct position
    swap(arr[low], arr[j]);
    return j;

    // TC: O(n)
    // SC: O(1)
}

// QuickSort algorithm
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partition = findPartition(arr, low, high); // Partition point
        QuickSort(arr, low, partition - 1);            // Sort left half
        QuickSort(arr, partition + 1, high);           // Sort right half
    }

    // TC: O(n log n) average, O(n^2) worst case
    // SC: O(log n) recursion stack
}

// Brute-force approach using sorting to find the second largest element
int findSecondLargestBrute(int arr[], int n)
{
    QuickSort(arr, 0, n - 1); // Sort the array

    int largest = arr[n - 1];
    int sLargest = INT_MIN;

    // Traverse from end to find the second largest element
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != largest)
        {
            sLargest = arr[i];
            break;
        }
    }
    return sLargest;

    // TC: O(n log n) + O(n) = O(n log n)
    // SC: O(log n) due to recursion stack
}

// Better approach using two passes
int findSecondLargestBetter(vector<int> &v)
{
    int largest = v[0];
    int sLargest = INT_MIN;

    // First pass: Find the largest element
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > largest)
        {
            largest = v[i];
        }
    }

    // Second pass: Find the second largest element
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > sLargest && v[i] != largest)
        {
            sLargest = v[i];
        }
    }

    return (sLargest == INT_MIN) ? -1 : sLargest;

    // TC: O(2n) = O(n)
    // SC: O(1)
}

// Optimal approach using a single pass
int findSecondLargestOptimal(vector<int> &v)
{
    int largest = v[0];
    int sLargest = INT_MIN;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > largest)
        {
            sLargest = largest; // Update second largest before changing largest
            largest = v[i];
        }
        else if (v[i] < largest && v[i] > sLargest)
        {
            sLargest = v[i];
        }
    }
    return sLargest;

    // TC: O(n)
    // SC: O(1)
}

// Optimal approach to find the second smallest element in one pass
int findSecondSmallestOptimal(vector<int> &v)
{
    int smallest = v[0];
    int sSmallest = INT_MAX;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < smallest)
        {
            sSmallest = smallest; // Update second smallest before changing smallest
            smallest = v[i];
        }
        else if (v[i] > smallest && v[i] < sSmallest)
        {
            sSmallest = v[i];
        }
    }
    return sSmallest;

    // TC: O(n)
    // SC: O(1)
}

// Main function for testing
int main()
{
    vector<int> v = {1, 2, 4, 7, 7, 5};

    // Testing optimal approaches
    cout << "Second Largest: " << findSecondLargestOptimal(v) << endl;
    cout << "Second Smallest: " << findSecondSmallestOptimal(v) << endl;

    return 0;
}
