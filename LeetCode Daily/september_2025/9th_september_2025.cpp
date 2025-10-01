// 2327. Number of People Aware of a Secret

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> t;
    int MOD = 1e9 + 7;

    int solve(int day, int delay, int forget)
    {
        if (day == 1)
            return 1;
        if (t[day] != -1)
            return t[day];

        int cnt = 0;
        for (int i = day - forget + 1; i <= day - delay; i++)
        {
            if (i > 0)
            {
                cnt = (cnt + solve(i, delay, forget)) % MOD;
            }
        }
        return t[day] = cnt;
    }

    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        t.assign(n + 1, -1);
        int ans = 0;
        for (int day = n - forget + 1; day <= n; day++)
        {
            if (day > 0)
            {
                ans = (ans + solve(day, delay, forget)) % MOD;
            }
        }
        return ans;
    }
};
