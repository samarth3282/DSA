#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVal(int num)
    {
        string str = to_string(num);
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] - '0' == 0)
                return false;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n)
    {
        int num1 = 1;
        int num2 = n - 1;
        while (true)
        {
            if (isVal(num1) && isVal(num2))
            {
                return {num1, num2};
            }
            num1++;
            num2--;
        }
        return {num1, num2};
    }
};