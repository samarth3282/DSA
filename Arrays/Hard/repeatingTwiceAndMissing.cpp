#include <bits/stdc++.h>
using namespace std;
vector<int> repeatingTwiceAndMissingBrute(vector<int> &arr)
{
    int repeating = -1, missing = -1;
    for (int i = 1; i <= arr.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] == i)
                count++;
        }
        if (count == 2)
            repeating = i;
        if (count == 0)
            missing = i;
        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}

vector<int> repeatingTwiceAndMissingBetter(vector<int> &arr)
{
    int hashh[arr.size() + 1] = {0};
    for (int i = 0; i < arr.size(); i++)
    {
        hashh[arr[i]]++;
    }
    int repeating, missing = INT_MIN;
    for (int i = 1; i < arr.size(); i++)
    {
        if (hashh[i] == 2)
            repeating = i;
        else if (hashh[i] == 0)
            missing = i;
        if (repeating != INT_MIN && missing != INT_MIN)
            break;
    }
    return {repeating, missing};
}
int main()
{

    return 0;
}