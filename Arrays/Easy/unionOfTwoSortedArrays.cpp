#include <bits/stdc++.h>
using namespace std;
vector<int> unionOfSortedArrays(int arr1[], int size1, int arr2[], int size2)
{
    vector<int> ans;
    set<int> st;
    for (int i = 0; i < size1; i++)
    {
        st.insert(arr1[i]);
    }
    for (int i = 0; i < size2; i++)
    {
        st.insert(arr2[i]);
    }
    for (auto it : st)
    {
        ans.push_back(it);
    }
    return ans;
}
vector<int> unionOfSortedArraysOptimal(int arr1[], int size1, int arr2[], int size2)
{
    vector<int> Union;
    int i = 0;
    int j = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (Union.size() == 0 || Union.back() != arr1[i])
            {
                Union.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (Union.size() == 0 || Union.back() != arr2[j])
            {
                Union.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i < size1)
    {
        if (Union.back() != arr1[i])
        {
            Union.push_back(arr1[i]);
        }
        i++;
    }
    while (j < size2)
    {
        if (Union.back() != arr2[j])
        {
            Union.push_back(arr2[j]);
        }
        j++;
    }
    return Union;
}

int main()
{
    int arr1[] = {1, 1, 2, 3, 4, 5, 5};
    int arr2[] = {2, 3, 4, 5, 6, 6};
    vector<int> ans = unionOfSortedArraysOptimal(arr1, 7, arr2, 6);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}