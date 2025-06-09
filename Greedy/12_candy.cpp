#include <bits/stdc++.h>
using namespace std;

/*
❖ Problem Statement:
Given an array 'ratings' of size n, each index represents a child and its rating.
Distribute candies to each child such that:
    1. Each child gets at least one candy.
    2. A child with a higher rating gets more candies than their neighbors.
Minimize the total number of candies distributed.
*/

/*
🧠 Brute-force Approach:
- Use two arrays (left and right) to check increasing/decreasing sequences from both sides.
- Final candy at each child = max(left[i], right[i]).
- Time: O(n)
- Space: O(n)
*/
int candyBruteForce(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> left(n, 1), right(n, 1);

    // Traverse from left to right
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
    }

    // Traverse from right to left
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
    }

    // Total candies is the max of left[i] and right[i]
    int totalCandies = 0;
    for (int i = 0; i < n; i++)
    {
        totalCandies += max(left[i], right[i]);
    }

    return totalCandies;
}

/*
🧠 Better Approach:
- Avoid using an extra right array by using a single right pass and directly adding to result.
- Time: O(n)
- Space: O(n) for the left array
*/
int candyBetter(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> left(n, 1);

    // Traverse from left to right to fill left array
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
    }

    int totalCandies = left[n - 1];
    int right = 1;

    // Traverse from right to left, calculate final result on the fly
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            right += 1;
        }
        else
        {
            right = 1;
        }
        totalCandies += max(left[i], right);
    }

    return totalCandies;
}

/*
🧠 Optimal Approach (Greedy):
- Traverse the array once, tracking up/down slopes.
- Use peak-tracking to handle up-down transitions.
- Time: O(n)
- Space: O(1)
*/
int candyOptimal(vector<int> &ratings)
{
    int n = ratings.size();
    if (n == 0)
        return 0;

    int i = 1;
    int totalCandies = 1; // First child always gets 1 candy

    while (i < n)
    {
        // If ratings are equal
        if (ratings[i] == ratings[i - 1])
        {
            totalCandies += 1;
            i++;
            continue;
        }

        // Increasing slope
        int up = 0;
        while (i < n && ratings[i] > ratings[i - 1])
        {
            up++;
            totalCandies += up + 1; // +1 because previous was already counted
            i++;
        }

        // Decreasing slope
        int down = 0;
        while (i < n && ratings[i] < ratings[i - 1])
        {
            down++;
            i++;
        }

        // Add candies for decreasing slope using arithmetic series
        totalCandies += (down * (down + 1)) / 2;

        // Adjustment: If peak was counted in both up and down, subtract 1
        if (up >= down)
            totalCandies -= down;
        else
            totalCandies -= up;
    }

    return totalCandies;
}

/*
🧪 Test Runner
*/
void runTests()
{
    vector<vector<int>> testCases = {
        {1, 0, 2},                // Expected: 5
        {1, 2, 2},                // Expected: 4
        {1, 3, 4, 5, 2},          // Expected: 11
        {1, 2, 3, 4, 5},          // Expected: 15
        {5, 4, 3, 2, 1},          // Expected: 15
        {1, 2, 87, 87, 87, 2, 1}, // Expected: 13
        {1},                      // Expected: 1
        {}                        // Expected: 0
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Input: ";
        for (int num : testCases[i])
            cout << num << " ";
        cout << "\n";

        vector<int> temp1 = testCases[i], temp2 = testCases[i], temp3 = testCases[i];

        cout << "Brute Force Result: " << candyBruteForce(temp1) << "\n";
        cout << "Better Result:      " << candyBetter(temp2) << "\n";
        cout << "Optimal Result:     " << candyOptimal(temp3) << "\n";
        cout << "---------------------------\n";
    }
}

int main()
{
    runTests();
    return 0;
}
