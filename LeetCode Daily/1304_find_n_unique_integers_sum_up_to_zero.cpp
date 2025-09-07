#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> arr1;
        if (n % 2 == 1)
        {
            int num = n / 2;
            vector<int> arr(n);
            for (int i = -num, j = 0; i <= num && j < n; i++, j++)
            {
                arr[j] = i;
            }
            return arr;
        }
        else
        {
            int num = n / 2;
            vector<int> arr(n);
            for (int i = 0; i < n - 1; i += 2)
            {
                arr[i] = num;
                arr[i + 1] = -num;
                num--;
            }
            return arr;
        }
        return arr1;
    }
};