#include <iostream>
#include <vector>

namespace std
{
    using namespace ::std;
}

void insertionSortRecursive(std::vector<int> &arr, int n)
{
    // Base case: An array with 1 or 0 elements is already sorted
    if (n <= 1)
        return;

    // Sort the first (n-1) elements
    insertionSortRecursive(arr, n - 1);

    // Insert the nth element into the correct position in the sorted part
    int last = arr[n - 1];
    int j = n - 2;

    // Shift elements that are greater than 'last' to the right
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    // Place 'last' at its correct position
    arr[j + 1] = last;

    // Time Complexity for this step:
    // For the nth element, the while loop can take at most n iterations.
    // Total TC: O(n^2) for all elements
    // Space Complexity: O(n) due to recursion stack
}

int main()
{
    std::vector<int> arr = {5, 3, 2, 6, 4, 1};
    int n = arr.size();

    insertionSortRecursive(arr, n);

    std::cout << "Sorted array: ";
    for (int num : arr)
        std::cout << num << " ";

    return 0;
}
