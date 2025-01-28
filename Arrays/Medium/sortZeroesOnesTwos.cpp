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
        while (arr[j] > pivot && j <= low - 1)
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
}
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partition = findPartition(arr, low, high);
        QuickSort(arr, low, partition - 1);
        QuickSort(arr, partition + 1, high);
    }
}

void sortZeroesOnesTwosBrute(int arr[], int size)
{
    QuickSort(arr, 0, size - 1);
}
void sortZeroesOnesTwosBetter(int arr[], int size)
{
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            cnt0++;
        }
        if (arr[i] == 1)
        {
            cnt1++;
        }
        if (arr[i] == 2)
        {
            cnt2++;
        }
    }
    int i = 0;
    for (; i < cnt0; i++)
    {
        arr[i] = 0;
    }
    for (; i < cnt0 + cnt1; i++)
    {
        arr[i] = 1;
    }
    for (; i < size; i++)
    {
        arr[i] = 2;
    }
}

void sortZeroesOnesTwosOptimal(int arr[], int size)
{
    int low = 0;
    int mid = 0;
    int high = size - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main()
{
    int arr[] = {0, 1, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    sortZeroesOnesTwosOptimal(arr, 15);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}