#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int size)
{
    for (int i = 0; i <= size - 2; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j <= size - 1; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}