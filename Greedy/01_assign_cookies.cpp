#include <bits/stdc++.h>
using namespace std;

// -------------------------------
// Brute Force Approach
// -------------------------------
// Try to assign each child the smallest cookie that satisfies them.
// Time Complexity: O(n * m) — for each child, scan all cookies.
// Space Complexity: O(m) — to track used cookies.
int maxContentChildrenBrute(vector<int> greed, vector<int> cookies)
{
    int n = greed.size(), m = cookies.size();
    vector<bool> used(m, false);
    int contentChildren = 0;

    for (int i = 0; i < n; i++)
    {
        int minCookieIndex = -1;
        for (int j = 0; j < m; j++)
        {
            if (!used[j] && cookies[j] >= greed[i])
            {
                if (minCookieIndex == -1 || cookies[j] < cookies[minCookieIndex])
                {
                    minCookieIndex = j;
                }
            }
        }
        if (minCookieIndex != -1)
        {
            used[minCookieIndex] = true;
            contentChildren++;
        }
    }

    return contentChildren;
}

// -------------------------------
// Optimal Greedy Approach
// -------------------------------
// Sort both arrays. Use two pointers:
// - If the current cookie satisfies the current child, assign it.
// - Else, move to a larger cookie.
// Time Complexity: O(n log n + m log m) — sorting both arrays.
// Space Complexity: O(1) — constant space (no extra storage).
int maxContentChildrenOptimal(vector<int> &greed, vector<int> &cookies)
{
    sort(greed.begin(), greed.end());
    sort(cookies.begin(), cookies.end());

    int i = 0; // Pointer for greed array (children)
    int j = 0; // Pointer for cookies array
    int contentChildren = 0;

    while (i < greed.size() && j < cookies.size())
    {
        if (cookies[j] >= greed[i])
        {
            contentChildren++;
            i++; // Move to next child
        }
        j++; // Move to next cookie
    }

    return contentChildren;
}

// -------------------------------
// Utility to Print Test Result
// -------------------------------
void runTestCase(vector<int> greed, vector<int> cookies, int expected)
{
    cout << "Greed: ";
    for (int g : greed)
        cout << g << " ";
    cout << "\nCookies: ";
    for (int c : cookies)
        cout << c << " ";
    cout << "\n";

    int result = maxContentChildrenOptimal(greed, cookies);
    cout << "Max Content Children (Optimal): " << result
         << " | Expected: " << expected << "\n";
    cout << (result == expected ? "✅ Passed" : "❌ Failed") << "\n\n";
}

// -------------------------------
// Main Function with Test Cases
// -------------------------------
int main()
{
    // Test Case 1: Basic Test
    runTestCase({1, 2, 3}, {1, 1}, 1);

    // Test Case 2: All can be satisfied
    runTestCase({1, 2}, {2, 3}, 2);

    // Test Case 3: No child can be satisfied
    runTestCase({5, 6, 7}, {1, 2, 3}, 0);

    // Test Case 4: Empty input
    runTestCase({}, {}, 0);

    // Test Case 5: More cookies than children
    runTestCase({1, 2}, {1, 2, 3, 4}, 2);

    // Test Case 6: Large input edge test (simplified version)
    vector<int> largeGreed(1000, 1);
    vector<int> largeCookies(1000, 1);
    runTestCase(largeGreed, largeCookies, 1000);

    return 0;
}
