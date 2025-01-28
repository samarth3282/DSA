#include <bits/stdc++.h>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Custom function to generate all permutations
void generatePermutations(int arr[], int start, int size, vector<vector<int>> &permutations)
{
    if (start == size)
    {
        vector<int> temp(arr, arr + size);
        permutations.push_back(temp);
        return;
    }

    for (int i = start; i < size; i++)
    {
        swap(arr[start], arr[i]);
        generatePermutations(arr, start + 1, size, permutations);
        swap(arr[start], arr[i]); // Backtrack
    }
}

// Function to find the next permutation using the brute force approach
vector<int> nextPermutationBrute(int arr[], int size)
{
    vector<vector<int>> permutations;
    generatePermutations(arr, 0, size, permutations);

    // Sort all the permutations lexicographically
    sort(permutations.begin(), permutations.end());

    // Find the current permutation in the sorted list
    for (int i = 0; i < permutations.size(); i++)
    {
        if (permutations[i] == vector<int>(arr, arr + size))
        {
            // Return the next permutation if it exists
            if (i + 1 < permutations.size())
            {
                return permutations[i + 1];
            }
            else
            {
                // If it's the last permutation, return the first one
                return permutations[0];
            }
        }
    }
    return {}; // Shouldn't reach here
}

// Optimal approach to find the next permutation
void nextPermutationOptimal(int arr[], int size)
{
    int index = -1;
    for (int i = size - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(arr, arr + size);
    }
    else
    {
        for (int i = size - 1; i > index; i--)
        {
            if (arr[i] > arr[index])
            {
                swap(arr[index], arr[i]);
                break;
            }
        }
        reverse(arr + index + 1, arr + size);
    }
}

int main()
{
    int arr[] = {2, 1, 5, 4, 3, 0, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create copies of the original array
    int arrBrute[size], arrOptimal[size];
    copy(arr, arr + size, arrBrute);
    copy(arr, arr + size, arrOptimal);

    // Brute force approach
    vector<int> result = nextPermutationBrute(arrBrute, size);
    cout << "Next permutation (Brute Force): ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    // Optimal approach
    nextPermutationOptimal(arrOptimal, size);
    cout << "Next permutation (Optimal): ";
    for (int i = 0; i < size; i++)
        cout << arrOptimal[i] << " ";
    cout << endl;

    return 0;
}
