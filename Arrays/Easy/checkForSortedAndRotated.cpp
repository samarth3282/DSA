#include <bits/stdc++.h>
using namespace std;

bool checkForSortedAndRotated(vector<int> &arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > arr[(i + 1) % arr.size()])
        {
            count++;
        }
    }
    if (count > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{

    return 0;
}