// 1039. Minimum Score Triangulation of Polygon
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rec(int i, int j, vector<int> &values, vector<vector<int>> &dp)
    {
        if (j - i + 1 < 3)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            int temp = values[i] * values[j] * values[k] + rec(i, k, values, dp) + rec(k, j, values, dp);
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int> &values)
    {
        vector<vector<int>> dp(51, vector<int>(51, -1));
        return rec(0, values.size() - 1, values, dp);
    }
};