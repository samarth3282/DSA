#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}
int main()
{
    int arr[] = {5, 3, 1, 4, 2};
    insertionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}