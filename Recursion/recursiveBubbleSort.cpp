#include <iostream>
using namespace std;

// Helper function for one pass of bubble sort
void bubbleSortPass(int arr[], int n)
{
    // Base case for this pass: no more pairs to compare
    if (n == 1)
        return;

    // Compare adjacent elements and swap if necessary
    if (arr[n - 1] < arr[n - 2])
    {
        int temp = arr[n - 1];
        arr[n - 1] = arr[n - 2];
        arr[n - 2] = temp;
    }

    // Recursive call for the next pair in the current pass
    bubbleSortPass(arr, n - 1);
}

// Pure recursive bubble sort function
void bubbleSortRecursive(int arr[], int n)
{
    // Base case: array is sorted if size is 1
    if (n == 1)
        return;

    // Perform one pass of bubble sort
    bubbleSortPass(arr, n);

    // Recursive call to bubble sort the rest of the array
    bubbleSortRecursive(arr, n - 1);
}

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bubbleSortRecursive(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
