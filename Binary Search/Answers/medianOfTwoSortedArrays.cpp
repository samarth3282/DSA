#include <bits/stdc++.h>
using namespace std;
int medianOfTwoSortedArraysBrute(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> temp;
    int left = 0;
    int right = 0;
    while (left <= arr1.size() && right <= arr2.size())
    {
        if (arr1[left] <= arr2[right])
            temp.push_back(arr1[left++]);
        else
            temp.push_back(arr2[right++]);
    }
    int n = temp.size();
    if (n % 2 == 0)
    {
        return temp[n / 2] + temp[n / 2 - 1] / 2;
    }
    else
        return temp[n / 2];
}

int medianOfTwoSortedArraysOptimal(vector<int> arr1, vector<int> arr2)
{
    int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2;
    int i, j = 0;
    int cnt = 0;
    int ind2 = n / 2;
    int ind1 = n / 2 - 1;
    int el1, el2;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            if (cnt == ind1)
                el1 = arr1[i];
            if (cnt == ind2)
                el2 = arr1[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                el1 = arr1[j];
            if (cnt == ind2)
                el2 = arr2[j];
            cnt++;
            j++;
        }
    }
    while (i < n1)
    {
        if (cnt == ind1)
            el1 = arr1[i];
        if (cnt == ind2)
            el2 = arr1[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            el1 = arr1[j];
        if (cnt == ind2)
            el2 = arr2[j];
        cnt++;
        j++;
    }

    if(n % 2 == 0){
        return ((el1 + el2) / 2);
    }else{
        return el2;
    }
}
int main()
{

    return 0;
}