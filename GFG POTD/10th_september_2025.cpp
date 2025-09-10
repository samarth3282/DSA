// Largest number in one swap

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestSwap(string &s)
    {
        int n = s.length();
        vector<int> lastIndexOfNumber(10, -1);

        for (int i = 0; i < n; i++)
        {
            lastIndexOfNumber[s[i] - '0'] = i;
        }

        for (int i = 0; i < n; i++)
        {
            for (int d = 9; d > s[i] - '0'; d--)
            {
                if (lastIndexOfNumber[d] > i)
                {
                    swap(s[i], s[lastIndexOfNumber[d]]);
                    return s;
                }
            }
        }

        return s;
    }
};
