#include <bits/stdc++.h>
using namespace std;

// ✅ Brute-force Approach
// Insert the new interval, sort all intervals, then merge overlapping ones
// Time Complexity: O(n log n) — due to sorting
// Space Complexity: O(n) — for result vector
vector<vector<int>> insertIntervalBruteForce(vector<vector<int>> intervals, vector<int> newInterval)
{
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end()); // sort based on start times

    vector<vector<int>> mergedIntervals;
    mergedIntervals.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> &last = mergedIntervals.back();
        if (intervals[i][0] <= last[1])
        {
            // Overlapping intervals, merge them
            last[1] = max(last[1], intervals[i][1]);
        }
        else
        {
            // No overlap, just add the interval
            mergedIntervals.push_back(intervals[i]);
        }
    }

    return mergedIntervals;
}

// ✅ Optimal Approach
// Directly insert the new interval in the correct position and merge on-the-go
// Time Complexity: O(n) — single pass through intervals
// Space Complexity: O(n) — result vector
vector<vector<int>> insertIntervalOptimal(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();

    // Step 1: Add all intervals that end before the new interval starts (no overlap)
    while (i < n && intervals[i][1] < newInterval[0])
    {
        result.push_back(intervals[i]);
        i++;
    }

    // Step 2: Merge all overlapping intervals with the new interval
    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    result.push_back(newInterval); // push merged interval

    // Step 3: Add all remaining intervals (no overlap)
    while (i < n)
    {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

// 🧪 Utility function to print intervals for testing
void printIntervals(const vector<vector<int>> &intervals)
{
    for (const auto &interval : intervals)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
}

// 🧪 Robust LeetCode-style Test Cases
void runTestCases()
{
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    cout << "Test Case 1: Insert [2, 5] into {{1,3}, {6,9}}" << endl;
    printIntervals(insertIntervalOptimal(intervals1, newInterval1)); // Expected: [1,5] [6,9]

    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    cout << "Test Case 2: Insert [4, 8] into multiple overlapping intervals" << endl;
    printIntervals(insertIntervalOptimal(intervals2, newInterval2)); // Expected: [1,2] [3,10] [12,16]

    vector<vector<int>> intervals3 = {};
    vector<int> newInterval3 = {5, 7};
    cout << "Test Case 3: Empty intervals" << endl;
    printIntervals(insertIntervalOptimal(intervals3, newInterval3)); // Expected: [5,7]

    vector<vector<int>> intervals4 = {{1, 5}};
    vector<int> newInterval4 = {0, 0};
    cout << "Test Case 4: New interval before all" << endl;
    printIntervals(insertIntervalOptimal(intervals4, newInterval4)); // Expected: [0,0] [1,5]

    vector<vector<int>> intervals5 = {{1, 5}};
    vector<int> newInterval5 = {6, 8};
    cout << "Test Case 5: New interval after all" << endl;
    printIntervals(insertIntervalOptimal(intervals5, newInterval5)); // Expected: [1,5] [6,8]
}

// 🔰 Main Driver
int main()
{
    runTestCases();
    return 0;
}
