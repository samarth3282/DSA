#include <bits/stdc++.h>
using namespace std;
int countTheWays(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }

    return countTheWays(n - 1) + countTheWays(n - 2);
}
int countTheWays2(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int countTheWays3(int n)
{
    int prev1 = 1;
    int prev2 = 1;
    int next;
    for (int i = 2; i <= n; i++)
    {
        next = prev1+prev2;
        prev2 = prev1;
        prev1 = next;
    }
    return next;
}
int main()
{
    cout << countTheWays3(10);
    return 0;
}