#include <bits/stdc++.h>
using namespace std;

// Function to partition the array
int funct(int arr[], int low, int high)
{
    int pivot = arr[low]; // Choose the first element as the pivot
    int i = low;          // Initialize i to the low index
    int j = high;         // Initialize j to the high index

    // Partitioning the array
    while (i < j)
    {
        // Move i to the right while the current element is less than or equal to the pivot
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        // Move j to the left while the current element is greater than the pivot
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        // If i is less than j, swap the elements
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    // Place the pivot in its correct position
    swap(arr[low], arr[j]);
    return j; // Return the index of the pivot
}

// QuickSort function
void QuickSort(int arr[], int low, int high)
{
    // Continue sorting while the low index is less than the high index
    if (low < high)
    {
        // Get the partition index
        int partition = funct(arr, low, high);

        // Recursively sort the left subarray
        QuickSort(arr, low, partition - 1);
        // Recursively sort the right subarray
        QuickSort(arr, partition + 1, high);
    }
}

int main()
{
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3}; // Input array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Call QuickSort on the entire array
    QuickSort(arr, 0, n - 1);

    // Output the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Print each element followed by a space
    }
    return 0; // Indicate successful execution
}