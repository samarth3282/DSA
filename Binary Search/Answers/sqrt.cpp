#include <bits/stdc++.h>
using namespace std;

/*
 * Function: findFloorSqrtBrute
 * ---------------------------------
 * This function finds the floor square root of a given integer `n` using a brute-force approach.
 * It iterates through all numbers from 0 to `n` and checks if the square of the number is less than or equal to `n`.
 * The last valid number is stored as the answer.
 *
 * Time Complexity: O(√N)
 *   - The loop runs until `i * i > n`, meaning in the worst case, it iterates approximately √N times.
 * Space Complexity: O(1)
 *   - Only a few integer variables are used.
 */
int findFloorSqrtBrute(int n)
{
    int ans = -1;
    for (int i = 0; i <= n; i++)
    {
        if (i * i <= n)
            ans = i;
        else
            break; // Exit early when the square exceeds n
    }
    return ans;
}

/*
 * Function: findFloorSqrtOptimal
 * ---------------------------------
 * This function finds the floor square root of `n` using Binary Search.
 * The search space is from 1 to `n`. At each step, the middle element is checked:
 * - If `mid * mid <= n`, it is a valid candidate, and we search for a larger value.
 * - Otherwise, search for a smaller value.
 *
 * Time Complexity: O(log N)
 *   - The search space reduces by half in each iteration (Binary Search).
 * Space Complexity: O(1)
 *   - Only a few integer variables are used.
 */
int findFloorSqrtOptimal(int n)
{
    int ans = -1;
    int low = 1;
    int high = n;
    while (low <= high)
    {
        int mid = ((low + high) / 2);

        if (mid * mid <= n)
            ans = mid, low = mid + 1; // Move to the right to find the largest possible valid sqrt
        else
            high = mid - 1; // Move left as mid is too large
    }
    return ans;
}

int main()
{
    int n = 25;

    // Testing Brute Force Approach
    cout << "Floor sqrt (Brute-force) of " << n << " is: " << findFloorSqrtBrute(n) << endl;

    // Testing Optimal Approach
    cout << "Floor sqrt (Binary Search) of " << n << " is: " << findFloorSqrtOptimal(n) << endl;

    return 0;
}
