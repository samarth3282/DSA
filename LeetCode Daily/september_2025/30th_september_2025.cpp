// 2221. Find Triangular Sum of an Array
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        vector<int> arr = nums;

        while (arr.size() != 1)
        {
            vector<int> temp;
            for (int i = 0; i <= arr.size() - 2; i++)
            {
                temp.push_back((arr[i] + arr[i + 1]) % 10);
            }
            arr = temp;
        }
        return arr[0];
    }
};