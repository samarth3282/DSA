#include <bits/stdc++.h>
using namespace std;
int findMissingNumberBrute(int arr[], int N, int size)
{
    for (int i = 1; i <= N; i++)
    {
        int flag = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            return i;
        }
    }
}
int findMissingNumberBetter(int arr[], int N, int size)
{
    int hashh[N + 1] = {0};
    for (int i = 0; i < size; i++)
    {
        hashh[arr[i]]++;
    }
    for (int i = 1; i < N + 1; i++)
    {
        if (hashh[i] == 0)
        {
            return i;
        }
    }
}
int main()
{
    int arr[] = {2, 19, 10, 1, 5, 3, 13, 18, 24, 23, 9, 22, 28, 25, 6, 27, 4, 20, 21, 26, 11, 8, 17, 15, 16, 12, 7, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << findMissingNumberBetter(arr, 29, size);
    return 0;
}