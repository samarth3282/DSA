#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------
Brute-force Approach:
---------------------------------------
Try every possible subset of non-overlapping meetings and return the maximum count.
This is essentially a variation of the activity selection problem using recursion.

T.C = O(2^n) → exploring all subsets.
S.C = O(n)  → recursion stack.
*/
int countMaxNonOverlappingRecursive(vector<pair<int, int>> &meetings, int index, int prevEndTime)
{
    if (index == meetings.size())
        return 0;

    // Option 1: Skip this meeting
    int skip = countMaxNonOverlappingRecursive(meetings, index + 1, prevEndTime);

    // Option 2: Take this meeting if it starts after previous ends
    int take = 0;
    if (meetings[index].first > prevEndTime)
    {
        take = 1 + countMaxNonOverlappingRecursive(meetings, index + 1, meetings[index].second);
    }

    return max(skip, take);
}

int maxMeetingsBrute(vector<int> &startTimes, vector<int> &endTimes)
{
    vector<pair<int, int>> meetings;
    for (int i = 0; i < startTimes.size(); i++)
    {
        meetings.push_back({startTimes[i], endTimes[i]});
    }
    // Sort by start time for consistent recursion
    sort(meetings.begin(), meetings.end());
    return countMaxNonOverlappingRecursive(meetings, 0, -1);
}

/*
---------------------------------------
Better Approach:
---------------------------------------
Use Dynamic Programming (Memoization) to avoid recomputing subproblems.

T.C = O(n^2) → DP for each index, checking all next possibilities.
S.C = O(n^2) → for dp table + recursion stack.
*/
int maxMeetingsMemo(int index, int prevEndTime, vector<pair<int, int>> &meetings, vector<vector<int>> &dp)
{
    if (index == meetings.size())
        return 0;

    if (dp[index][prevEndTime + 1] != -1)
        return dp[index][prevEndTime + 1];

    int skip = maxMeetingsMemo(index + 1, prevEndTime, meetings, dp);

    int take = 0;
    if (meetings[index].first > prevEndTime)
    {
        take = 1 + maxMeetingsMemo(index + 1, meetings[index].second, meetings, dp);
    }

    return dp[index][prevEndTime + 1] = max(skip, take);
}

int maxMeetingsBetter(vector<int> &startTimes, vector<int> &endTimes)
{
    vector<pair<int, int>> meetings;
    int n = startTimes.size();
    for (int i = 0; i < n; i++)
    {
        meetings.push_back({startTimes[i], endTimes[i]});
    }
    sort(meetings.begin(), meetings.end());

    vector<vector<int>> dp(n, vector<int>(1001, -1)); // Assuming max end time < 1000
    return maxMeetingsMemo(0, -1, meetings, dp);
}

/*
---------------------------------------
Optimal Greedy Approach:
---------------------------------------
Sort meetings by end time and always pick the earliest finishing non-overlapping meeting.

T.C = O(n log n) → for sorting.
S.C = O(n) → for storing pairs (can be optimized to O(1) if done in-place).
*/
int maxMeetingsOptimal(vector<int> &startTimes, vector<int> &endTimes)
{
    vector<pair<int, int>> meetings;
    int n = startTimes.size();
    for (int i = 0; i < n; i++)
    {
        meetings.push_back({startTimes[i], endTimes[i]});
    }

    // Sort meetings by end time. If same end time, take one with later start.
    sort(meetings.begin(), meetings.end(), [](pair<int, int> a, pair<int, int> b)
         { return (a.second == b.second) ? a.first > b.first : a.second < b.second; });

    int maxCount = 0;
    int lastEndTime = -1;

    for (auto &meeting : meetings)
    {
        if (meeting.first > lastEndTime)
        {
            maxCount++;
            lastEndTime = meeting.second;
        }
    }

    return maxCount;
}

/*
---------------------------------------
Robust Test Cases
---------------------------------------
These test cases mimic LeetCode edge cases.
*/
void runTests()
{
    vector<vector<int>> starts = {
        {1, 3, 0, 5, 8, 5},
        {1, 2, 3},
        {1, 1, 1},
        {1},
        {},
        {7, 1, 4, 8},
    };

    vector<vector<int>> ends = {
        {2, 4, 6, 7, 9, 9},
        {3, 4, 5},
        {2, 2, 2},
        {2},
        {},
        {10, 3, 5, 9},
    };

    for (int i = 0; i < starts.size(); i++)
    {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Brute: " << maxMeetingsBrute(starts[i], ends[i]) << "\n";
        cout << "Better: " << maxMeetingsBetter(starts[i], ends[i]) << "\n";
        cout << "Optimal: " << maxMeetingsOptimal(starts[i], ends[i]) << "\n\n";
    }
}

int main()
{
    runTests();
    return 0;
}
