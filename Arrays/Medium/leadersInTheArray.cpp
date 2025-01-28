#include <bits/stdc++.h>
using namespace std;

vector<int> leadersInTheArray(int arr[], int size)
{
    vector<int> finalAns;
    for (int i = 0; i < size; i++)
    {
        int flag = true;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[i])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            finalAns.push_back(arr[i]);
        }
    }
    return finalAns;
}

vector<int> leadersInTheArrayOptimal(int arr[], int size)
{
    vector<int> finalAns;
    int max = INT_MIN;
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            finalAns.push_back(arr[i]);
            max = arr[i];
        }
    }
    return finalAns;
}
int main()
{

    return 0;
}