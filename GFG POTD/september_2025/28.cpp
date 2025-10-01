// Longest Bounded-Difference Subarray
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> longestSubarray(vector<int> &arr, int x)
    {
        // code here
        int l = 0;
        int r = 0;
        int ansL = 0;
        int ansR = 0;
        int maxLen = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        while (r < arr.size())
        {
            minHeap.push({arr[r], r});
            maxHeap.push({arr[r], r});
            while (!maxHeap.empty() && !minHeap.empty() &&
                   maxHeap.top().first - minHeap.top().first > x)
            {
                l++;
                while (!minHeap.empty() && minHeap.top().second < l)
                    minHeap.pop();
                while (!maxHeap.empty() && maxHeap.top().second < l)
                    maxHeap.pop();
            }
            if (r - l + 1 > maxLen)
            {
                ansL = l;
                ansR = r;
                maxLen = r - l + 1;
            }
            r++;
        }
        return vector<int>(arr.begin() + ansL, arr.begin() + ansR + 1);
    }
};