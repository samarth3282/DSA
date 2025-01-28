#include <bits/stdc++.h>
using namespace std;

int findPartition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;

    // TC: O(n), where n is the size of the subarray
    // SC: O(1)
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partition = findPartition(arr, low, high);
        QuickSort(arr, low, partition - 1);
        QuickSort(arr, partition + 1, high);
    }

    // TC: O(n log n) on average, O(n^2) in the worst case
    // SC: O(log n) due to recursion stack
}

int findSecondLargestBrute(int arr[], int n)
{
    QuickSort(arr, 0, n - 1);

    int largest = arr[n - 1];
    int sLargest = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != largest)
        {
            sLargest = arr[i];
            break;
        }
    }
    return sLargest;

    // TC: O(n log n) due to QuickSort + O(n) traversal = O(n log n)
    // SC: O(log n) due to QuickSort recursion
}

int findSecondLargestBetter(vector<int> &v)
{
    int largest = v[0];
    int sLargest = INT_MIN;

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > largest)
        {
            largest = v[i];
        }
    }

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

int findSecondLargestOptimal(vector<int> &v)
{
    int largest = v[0];
    int sLargest = INT_MIN;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > largest)
        {
            sLargest = largest;
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

int findSecondSmallestOptimal(vector<int> &v)
{
    int smallest = v[0];
    int sSmallest = INT_MAX;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < smallest)
        {
            sSmallest = smallest;
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

int main()
{
    vector<int> v = {1, 2, 4, 7, 7, 5};
    cout << "Second Largest: " << findSecondLargestOptimal(v) << endl;
    cout << "Second Smallest: " << findSecondSmallestOptimal(v) << endl;
    return 0;
}
