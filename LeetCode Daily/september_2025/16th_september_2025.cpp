// 2197. Replace Non-Coprime Numbers in Array

#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int current = nums[i];
            while (!ans.empty())
            {
                int lastNum = ans.back();
                int g = gcd(lastNum, current);
                if (g == 1)
                    break;

                ans.pop_back();
                current = lastNum / g * current;
            }
            ans.push_back(current);
        }
        return ans;
    }
};