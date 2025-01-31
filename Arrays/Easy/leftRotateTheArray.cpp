#include <bits/stdc++.h>
using namespace std;

// Function to reverse the array from index 'start' to 'end'
void reverse(int arr[], int start, int end)
{
    // Reverse elements by swapping until start meets end
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to left rotate the array by one place
void leftRotateTheArrayByOnePlace(int arr[], int n)
{
    // Optimal Solution for rotating by 1 place
    // T.C. = O(n) - We iterate through the entire array once
    // S.C. = O(1) - In-place rotation, no extra space used

    // Store the first element
    int temp = arr[0];

    // Shift the rest of the elements one position to the left
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }

    // Place the stored first element at the end of the array
    arr[n - 1] = temp;
}

// Function to left rotate the array by 'd' places (Brute Force Approach)
void leftRotateTheArrayByDPlaceBrute(int arr[], int d, int n)
{
    // Brute Force Approach for rotating by 'd' places
    // T.C. = O(n + d) - Copy d elements, shift n elements, and then insert d elements back
    // S.C. = O(d) - Temporary array of size d to store first d elements

    // Handle cases where d >= n by taking d % n
    d = d % n;
    if (d == 0)
        return; // No rotation needed if d is 0

    // Step 1: Store the first 'd' elements in a temporary array
    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }

    // Step 2: Shift the remaining elements to the left by 'd' positions
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    // Step 3: Copy the 'temp' elements back to the end of the array
    for (int i = 0; i < d; i++)
    {
        arr[n - d + i] = temp[i];
    }
}

// Function to left rotate the array by 'd' places (Optimal Solution using reversal)
void leftRotateTheArrayByDPlaceOptimal(int arr[], int d, int n)
{
    // Optimal Solution for rotating by 'd' places using the reversal algorithm
    // T.C. = O(2n) ~ O(n) - We reverse the array three times, each time iterating through it once
    // S.C. = O(1) - In-place, no extra space used

    // Handle cases where d >= n by taking d % n
    d = d % n;
    if (d == 0)
        return; // No rotation needed if d is 0

    // Step 1: Reverse the first 'd' elements
    reverse(arr, 0, d - 1);

    // Step 2: Reverse the remaining 'n - d' elements
    reverse(arr, d, n - 1);

    // Step 3: Reverse the entire array
    reverse(arr, 0, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};          // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array

    // Test case: Rotate the array by 1 place
    // leftRotateTheArrayByOnePlace(arr, n);

    // Test case: Optimal rotation by 'd' places using the reversal algorithm
    leftRotateTheArrayByDPlaceOptimal(arr, 2, n);

    // Test case: Brute force rotation by 'd' places
    // leftRotateTheArrayByDPlace(arr, 2, n);

    // Print the rotated array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
