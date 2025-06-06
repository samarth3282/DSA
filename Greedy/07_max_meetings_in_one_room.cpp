#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------
// ✅ Brute-force Approach (Backtracking)
// -----------------------------------------------------------
// Try all combinations of meetings and select the maximum valid non-overlapping set.
// Time Complexity: O(2^n) → Exponential
// Space Complexity: O(n) → Recursion stack
int maxMeetingsBrute(vector<int> &start, vector<int> &end, int index = 0, int prevEnd = 0)
{
    if (index == start.size())
        return 0;

    // Skip current meeting
    int notTake = maxMeetingsBrute(start, end, index + 1, prevEnd);

    // Take current meeting if non-overlapping
    int take = 0;
    if (start[index] > prevEnd)
    {
        take = 1 + maxMeetingsBrute(start, end, index + 1, end[index]);
    }

    return max(take, notTake);
}

// -----------------------------------------------------------
// ✅ Better Approach
// -----------------------------------------------------------
// Store meetings with start and end, sort by end time, then apply greedy selection.
// Time Complexity: O(n log n)
// Space Complexity: O(n) for meetings vector
int maxMeetingsBetter(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++)
    {
        meetings.push_back({start[i], end[i]});
    }

    // Sort by end time (greedy strategy)
    sort(meetings.begin(), meetings.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    int count = 0, prevEnd = -1;
    for (auto &meeting : meetings)
    {
        if (meeting.first > prevEnd)
        {
            count++;
            prevEnd = meeting.second;
        }
    }

    return count;
}

// -----------------------------------------------------------
// ✅ Optimal Approach (No extra space if index sorting allowed)
// -----------------------------------------------------------
// Instead of using pair vector, use index array and sort by end time.
// Time Complexity: O(n log n)
// Space Complexity: O(n) for storing indices (less than Better)
int maxMeetingsOptimal(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0); // Fill 0 to n-1

    // Sort indices based on end times
    sort(indices.begin(), indices.end(), [&](int i, int j)
         { return end[i] < end[j]; });

    int count = 0, prevEnd = -1;
    for (int idx : indices)
    {
        if (start[idx] > prevEnd)
        {
            count++;
            prevEnd = end[idx];
        }
    }

    return count;
}

// -----------------------------------------------------------
// ✅ Robust Test Cases
// -----------------------------------------------------------
void runTestCases()
{
    vector<vector<int>> testStarts = {
        {1, 3, 0, 5, 8, 5},
        {1, 2, 3},
        {7, 2, 5, 8},
        {1, 1, 1, 1},
        {1, 2, 3}};

    vector<vector<int>> testEnds = {
        {2, 4, 6, 7, 9, 9},
        {2, 3, 4},
        {10, 4, 6, 9},
        {2, 2, 2, 2},
        {4, 5, 6}};

    for (int i = 0; i < testStarts.size(); i++)
    {
        cout << "Test Case " << i + 1 << ":\n";
        vector<int> start = testStarts[i];
        vector<int> end = testEnds[i];
        cout << "Start: ";
        for (int x : start)
            cout << x << " ";
        cout << "\nEnd:   ";
        for (int x : end)
            cout << x << " ";
        cout << "\n";

        // Note: Brute works only for small inputs
        if (start.size() <= 10)
        {
            cout << "Brute Force Output: " << maxMeetingsBrute(start, end) << "\n";
        }

        cout << "Better Approach Output: " << maxMeetingsBetter(start, end) << "\n";
        cout << "Optimal Approach Output: " << maxMeetingsOptimal(start, end) << "\n";
        cout << "---------------------------\n";
    }
}

// -----------------------------------------------------------
// ✅ Main Driver
// -----------------------------------------------------------
int main()
{
    runTestCases();
    return 0;
}
