#include <bits/stdc++.h>
using namespace std;

void rearrangeElementsBySignBrute(int arr[], int size)
{
    vector<int> positives;
    vector<int> negatives;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0)
        {
            positives.push_back(arr[i]);
        }
        else
        {
            negatives.push_back(arr[i]);
        }
    }
    int ptrToPositives = 0;
    int ptrToNegatives = 0;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = positives[ptrToPositives];
            ptrToPositives++;
        }
        else
        {
            arr[i] = negatives[ptrToNegatives];
            ptrToNegatives++;
        }
    }
}

vector<int> rearrangeElementsBySignOptimal(int arr[], int size)
{
    vector<int> finalArr(size);
    int pos = 0;
    int neg = 1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0)
        {
            finalArr[pos] = arr[i];
            pos += 2;
        }
        else
        {
            finalArr[neg] = arr[i];
            neg += 2;
        }
    }
    return finalArr;
}

void rearrangeElementsBySign(int arr[], int size)
{
    vector<int> pos, neg;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            neg.push_back(arr[i]);
        }
        else
        {
            pos.push_back(arr[i]);
        }
    }
    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = 2 * neg.size();
        for (int i = neg.size(); i < pos.size(); i++)
        {
            arr[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = 2 * pos.size();
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }
}
int main()
{
    int arr1[] = {3, 1, -2, -5, 2, -4};
    vector<int> arr = rearrangeElementsBySignOptimal(arr1, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}