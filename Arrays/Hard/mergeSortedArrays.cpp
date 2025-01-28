#include <bits/stdc++.h>
using namespace std;
void mergeSortedArraysWithExtraSpaceGivenInAnArray(vector<int> &a, int m, vector<int> &b, int n)
{
    int arrPointer = m + n - 1;
    int aPointer = m - 1;
    int bPointer = n - 1;
    while (aPointer >= 0 && bPointer >= 0)
    {

        if (a[aPointer] >= b[bPointer])
        {
            a[arrPointer] = a[aPointer];
            aPointer--;
        }
        else
        {
            a[arrPointer] = b[bPointer];
            bPointer--;
        }
        arrPointer--;
    }
    while (aPointer >= 0)
    {
        a[arrPointer] = a[aPointer];
        aPointer--;
        arrPointer--;
    }
    while (bPointer >= 0)
    {
        a[arrPointer] = a[bPointer];
        bPointer--;
        arrPointer--;
    }
}

void mergeSortedArraysWithoutAnyExtraSpaceOptimal1(vector<int> &a, vector<int> &b)
{
    int left = a.size() - 1;
    int right = 0;
    while (left >= 0 && right < b.size())
    {
        if (a[left] > b[right])
        {
            swap(a[left], b[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}
void mergeSortedArraysWithoutAnyExtraSpaceOptimal2(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    int gap = ((n + m) / 2) + ((n + m) % 2);
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < (n + m))
        {
            if (left < n && right >= n)
            {
                if (arr1[left] > arr2[right - n])
                {
                    swap(arr1[left], arr2[right - n]);
                }
            }
            else if (left >= n)
            {
                if (arr2[left - n] > arr2[right - n])
                {
                    swap(arr1[left - n], arr2[right - n]);
                }
            }
            else
            {
                if (arr1[left] > arr1[right])
                {
                    swap(arr1[left], arr2[right]);
                }
            }
            left++, right++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
}
void printArr(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> a = {1, 2, 3, 0, 0, 0};
    vector<int> b = {2, 5, 6};
    mergeSortedArraysWithExtraSpaceGivenInAnArray(a, 3, b, 3);
    printArr(a);
    return 0;
}