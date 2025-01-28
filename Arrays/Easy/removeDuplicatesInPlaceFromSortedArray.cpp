#include <bits/stdc++.h>
using namespace std;
set<int> st;
int removeDuplicatesInPlaceFromsortedArray(vector<int> &arrGiven)
{ // Brute Force Approach    O(nlogn + n)
    for (int i = 0; i < arrGiven.size(); i++)
    {
        st.insert(arrGiven[i]);
    }
    int index = 0;
    for (auto it : st)
    {
        arrGiven[index] = it;
        index++;
    }
    return index;
}
int removeDuplicatesInPlaceFromsortedArray2(vector<int> &arrGiven)
{
    // Optimal Solution O(n)
    int index = 1;
    for (int i = 1; i < arrGiven.size(); i++)
    {
        if (arrGiven[i] != arrGiven[i - 1])
        {
            arrGiven[index] = arrGiven[i];
            index++;
        }
    }
    return index;
}

int main()
{
    vector<int> v = {1, 1, 2, 2, 2, 3, 3};
    cout << removeDuplicatesInPlaceFromsortedArray2(v);
    return 0;
}