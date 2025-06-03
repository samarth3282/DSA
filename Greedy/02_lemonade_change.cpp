#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------------
🍋 Problem: Lemonade Change
Each customer pays with a 5, 10, or 20 dollar bill. You must give correct change using only $5 and $10 bills.
-------------------------------------------------------------

Approach 1: ❌ Brute Force
- Not feasible here. Simulating all permutations of change combinations would lead to exponential complexity and is unnecessary.

Approach 2: ❌ Better Approach
- No meaningful intermediate optimization exists between brute and optimal due to the simplicity of the state.

Approach 3: ✅ Optimal Greedy Approach
- Maintain count of $5 and $10 bills.
- Always try to give change using higher denomination first (prefer 10+5 over 5+5+5 for 20).
- If you can't give correct change, return false.

Time Complexity: O(n)
Space Complexity: O(1)
*/

bool canProvideChangeOptimally(vector<int> &bills)
{
    int fiveCount = 0; // Count of $5 notes
    int tenCount = 0;  // Count of $10 notes

    for (int bill : bills)
    {
        if (bill == 5)
        {
            fiveCount++; // Accept $5, no change needed
        }
        else if (bill == 10)
        {
            if (fiveCount == 0)
                return false; // Need one $5 as change
            fiveCount--;
            tenCount++; // Keep the $10 note
        }
        else if (bill == 20)
        {
            // Prefer 10 + 5 change over 5 + 5 + 5
            if (tenCount > 0 && fiveCount > 0)
            {
                tenCount--;
                fiveCount--;
            }
            else if (fiveCount >= 3)
            {
                fiveCount -= 3;
            }
            else
                return false;
        }
    }

    return true; // All customers received correct change
}

// 🔧 Utility function to print test results
void runTest(vector<int> bills, bool expected)
{
    bool result = canProvideChangeOptimally(bills);
    cout << "Input: ";
    for (int b : bills)
        cout << b << " ";
    cout << "\nExpected: " << (expected ? "true" : "false")
         << ", Got: " << (result ? "true" : "false") << "\n\n";
}

int main()
{
    // 🧪 Robust Test Cases

    // Case 1: Standard case
    runTest({5, 5, 5, 10, 20}, true); // Can give change

    // Case 2: Not enough change
    runTest({5, 5, 10, 10, 20}, false); // Not enough $5 notes

    // Case 3: All $5 bills
    runTest({5, 5, 5, 5}, true);

    // Case 4: Starts with $10
    runTest({10}, false); // Can't give change on first bill

    // Case 5: Just enough $5s
    runTest({5, 5, 10, 5, 20}, true);

    // Case 6: Large valid sequence
    runTest({5, 5, 5, 10, 5, 10, 10, 20}, false);

    // Case 7: Edge Case - Empty Input
    runTest({}, true);

    return 0;
}
