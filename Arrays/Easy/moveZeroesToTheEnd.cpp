#include <bits/stdc++.h>
using namespace std;

void moveZeroesToTheEnd(int arr[], int n)
{
    // Brute Force Approach
    // T.C. = O(2n) - We traverse the array twice:
    // First pass to collect non-zero elements,
    // Second pass to fill the original array with non-zero elements followed by zeroes.
    // S.C. = O(n) - Extra space used to store non-zero elements in a temporary vector.

    vector<int> temp; // Temporary vector to store non-zero elements.

    // Step 1: Store all non-zero elements in the temp vector
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }

    // Step 2: Overwrite the original array with elements from temp
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }

    // Step 3: Fill the remaining positions in the array with zeroes
    for (int i = temp.size(); i < n; i++)
    {
        arr[i] = 0;
    }
}

void moveZeroesToTheEnd2(int arr[], int n)
{
    // Optimal Approach
    // T.C. = O(n) - We traverse the array only once to move zeroes to the end.
    // S.C. = O(1) - No extra space is used, operations are done in-place.

    int j = -1; // j is used to keep track of the first zero's position.

    // Step 1: Find the first zero in the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i; // Position of the first zero
            break;
        }
    }

    // Step 2: Swap zeroes with non-zero elements found after j
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[j], arr[i]); // Move non-zero element to the position of zero
            j++;                  // Move to the next zero position
        }
    }
}

int main()
{
    int arr[] = {1, 0, 2, 2, 3, 0, 0, 4, 0, 0, 0}; // Example input array
    int n = sizeof(arr) / sizeof(arr[0]);          // Calculate the size of the array

    moveZeroesToTheEnd2(arr, n); // Call the optimal function
    // moveZeroesToTheEnd(arr, n); // You can also call the brute force function

    // Output the modified array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
