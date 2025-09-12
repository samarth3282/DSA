// minimize the heights II

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        // code here
        sort(arr.begin(), arr.end());
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            minNum = min(minNum, arr[i]);
            maxNum = max(maxNum, arr[i]);
        }
        if (minNum < k)
            minNum += k;
        else
            minNum -= k;
        if (maxNum < k)
            maxNum += k;
        else
            maxNum -= k;
        return abs(minNum - maxNum);
    }
};