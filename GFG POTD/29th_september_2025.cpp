// Maximum subarray sum 2
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubarrSum(vector<int> &arr, int a, int b)
    {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];

        deque<int> dq;
        int ans = INT_MIN;

        for (int j = a; j <= n; j++)
        {
            while (!dq.empty() && prefix[dq.back()] >= prefix[j - a])
                dq.pop_back();
            dq.push_back(j - a);

            while (!dq.empty() && j - dq.front() > b)
                dq.pop_front();

            ans = max(ans, prefix[j] - prefix[dq.front()]);
        }
        return ans;
    }
};