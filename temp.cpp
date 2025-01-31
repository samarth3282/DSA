#include <bits/stdc++.h>
using namespace std;
void moveZeroesToTheEnd(vector<int> &arr)
{
    int index = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        for (int i = index + 1; i < arr.size(); i++)
        {
            if (arr[i] != 0)
            {
                swap(arr[index], arr[i]);
                index++;
            }
        }
    }
}
int main()
{

    return 0;
}