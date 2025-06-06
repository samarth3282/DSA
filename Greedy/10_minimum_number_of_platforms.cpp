#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------
💡 Problem: Minimum Number of Platforms Required
---------------------------------------------------
🧠 Goal:
Given two arrays: arrival[] and departure[] of trains,
return the minimum number of platforms required so that
no train has to wait.

Input Format:
- arrival[i] = arrival time of ith train
- departure[i] = departure time of ith train
- Time is in 24-hour format

---------------------------------------------------
🧪 Sample:
Input: arrival = {900, 940, 950, 1100, 1500, 1800}
       departure = {910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: Between 9:50 and 11:00 there are 3 trains.
---------------------------------------------------
*/

// 🧪 Brute Force Approach 1 (O(N^2))
// 📝 Check overlapping intervals for each train
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int minimumNumberOfPlatformsBrute(vector<int> &arrival, vector<int> &departure)
{
    int n = arrival.size();
    int maxPlatforms = 1;

    for (int i = 0; i < n; i++)
    {
        int platformsNeeded = 1; // At least one platform for this train

        for (int j = i + 1; j < n; j++)
        {
            // Check if trains overlap
            if ((arrival[i] >= arrival[j] && arrival[i] <= departure[j]) ||
                (arrival[j] >= arrival[i] && arrival[j] <= departure[i]))
            {
                platformsNeeded++;
            }
        }

        maxPlatforms = max(maxPlatforms, platformsNeeded);
    }

    return maxPlatforms;
}

// ✅ Optimal Approach: Using Sorting + 2 Pointers
// Time Complexity: O(n log n) [for sorting]
// Space Complexity: O(1)
int minimumNumberOfPlatformsOptimal(vector<int> &arrival, vector<int> &departure)
{
    int n = arrival.size();
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int i = 0; // Pointer for arrival
    int j = 0; // Pointer for departure
    int currentPlatforms = 0;
    int maxPlatforms = 0;

    // Two pointer traversal
    while (i < n && j < n)
    {
        if (arrival[i] <= departure[j])
        {
            currentPlatforms++; // New train arrives
            i++;
        }
        else
        {
            currentPlatforms--; // Train departs
            j++;
        }
        maxPlatforms = max(maxPlatforms, currentPlatforms);
    }

    return maxPlatforms;
}

// 🧪 Robust Test Cases
void testMinimumPlatforms()
{
    vector<pair<vector<int>, vector<int>>> testCases = {
        {{900, 940, 950, 1100, 1500, 1800}, {910, 1200, 1120, 1130, 1900, 2000}}, // expected = 3
        {{900, 905, 915, 920}, {910, 920, 925, 930}},                             // expected = 4
        {{1000, 1010, 1020}, {1005, 1020, 1030}},                                 // expected = 2
        {{900}, {1000}},                                                          // expected = 1
        {{900, 905, 910}, {901, 906, 911}},                                       // expected = 3
        {{900, 940}, {910, 1200}},                                                // expected = 2
        {{900, 1100, 1235}, {1000, 1200, 1240}},                                  // expected = 1
    };

    for (int i = 0; i < testCases.size(); ++i)
    {
        auto &[arr, dep] = testCases[i];
        int brute = minimumNumberOfPlatformsBrute(arr, dep);
        int optimal = minimumNumberOfPlatformsOptimal(arr, dep);
        cout << "Test Case " << i + 1 << ": "
             << "Brute = " << brute << ", Optimal = " << optimal << "\n";
    }
}

int main()
{
    testMinimumPlatforms();
    return 0;
}
