// String stack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool stringStack(string &pat, string &tar)
    {
        int i = pat.size() - 1;
        int j = tar.size() - 1;

        while (i >= 0)
        {
            if (pat[i] == tar[j])
            {
                i--;
                j--;
            }
            else
            {
                i -= 2;
            }
            if (j < 0)
            {
                return true;
            }
        }

        return false;
    }
};
