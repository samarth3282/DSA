#include <bits/stdc++.h>
using namespace std;

int majorityElementBrute(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int cnt = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                cnt++;
            }
        }
        if (cnt > size / 2)
        {
            return arr[i];
        }
    }
    return INT_MIN;
}

int majorityElementBetter(int arr[], int size)
{
    map<int, int> mpp;
    for (int i = 0; i < size; i++)
    {
        mpp[arr[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > size / 2)
        {
            return it.first;
        }
    }
    return INT_MIN;
}

int majorityElementOptimal(int arr[], int size)
{
    int cnt = 0;
    int el;
    for (int i = 0; i < size; i++)
    {
        if (cnt == 0)
        {
            el = arr[i];
            cnt = 1;
        }
        else if (arr[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == el)
        {
            counter++;
        }
    }
    if (counter > size / 2)
    {
        return el;
    }
    return INT_MIN;
}
int main()
{
    int arr[] = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << majorityElementOptimal(arr, size);
    return 0;
}