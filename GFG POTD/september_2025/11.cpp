// minimum jumps

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        // code here
        int n = arr.size() - 1;
        int l = 0;
        int r = 0;
        int jumps = 0;
        while (r < n)
        {
            int farthest = INT_MIN;
            for (int i = l; i <= r; i++)
            {
                farthest = max(farthest, arr[i] + i);
            }
            if (farthest <= r)
                return -1;
            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};
