#include <bits/stdc++.h>
using namespace std;

/**
 * Function: minNumberOfDaysBrute
 * ------------------------------
 * Finds the minimum number of days required to make `m` bouquets using brute-force.
 * - Iterates over all possible days from min(arr) to max(arr).
 * - Counts valid bouquets at each day.
 * - Returns the first valid day where enough bouquets are formed.
 *
 * @param arr - Vector containing bloom days.
 * @param m - Number of bouquets needed.
 * @param k - Number of adjacent flowers required per bouquet.
 * @return Minimum number of days required, or -1 if not possible.
 *
 * Time Complexity: O((max-min) * N) → Scans the array for each day.
 * Space Complexity: O(1) → No extra space used.
 */
int minNumberOfDaysBrute(vector<int> &arr, int m, int k)
{
    int minDay = *min_element(arr.begin(), arr.end());
    int maxDay = *max_element(arr.begin(), arr.end());

    for (int day = minDay; day <= maxDay; day++)
    {
        int numberOfBouquets = 0, cnt = 0;

        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] <= day)
                cnt++;
            else
            {
                numberOfBouquets += (cnt / k);
                cnt = 0;
            }
        }
        numberOfBouquets += (cnt / k); // Final check for the last segment

        if (numberOfBouquets >= m)
            return day;
    }
    return -1; // Not enough flowers
}

/**
 * Function: canMakeBouquets
 * -------------------------
 * Helper function for binary search. Checks if we can make `m` bouquets in `days`.
 * - Iterates through array, counting consecutive flowers that can bloom.
 * - If we reach `k` flowers in a row, we form a bouquet.
 *
 * @param arr - Vector containing bloom days.
 * @param days - Current day being tested.
 * @param m - Number of bouquets needed.
 * @param k - Number of adjacent flowers per bouquet.
 * @return True if bouquets can be formed, False otherwise.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
bool canMakeBouquets(vector<int> &arr, int days, int m, int k)
{
    int cnt = 0, numberOfBouquets = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= days)
        {
            cnt++;
            if (cnt == k)
            {
                numberOfBouquets++;
                cnt = 0;
            }
        }
        else
            cnt = 0;
    }
    return numberOfBouquets >= m;
}

/**
 * Function: minDaysOptimal
 * ------------------------
 * Finds the minimum number of days required to make `m` bouquets using binary search.
 * - Binary search is performed between 1 and max(arr).
 * - Uses `canMakeBouquets` to check feasibility.
 * - Returns the smallest valid day where bouquets can be made.
 *
 * @param arr - Vector containing bloom days.
 * @param m - Number of bouquets needed.
 * @param k - Number of adjacent flowers required per bouquet.
 * @return Minimum days needed, or -1 if not possible.
 *
 * Time Complexity: O(N log maxDay) → Logarithmic search reduces range.
 * Space Complexity: O(1)
 */
int minDaysOptimal(vector<int> &arr, int m, int k)
{
    long long totalFlowersNeeded = (long long)m * k;
    if (totalFlowersNeeded > arr.size()) // Impossible case
        return -1;

    int low = 1, high = *max_element(arr.begin(), arr.end()), ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canMakeBouquets(arr, mid, m, k))
        {
            ans = mid;
            high = mid - 1; // Try to minimize days
        }
        else
        {
            low = mid + 1; // Increase days
        }
    }
    return ans;
}

// Driver Code with Robust Test Cases
int main()
{
    vector<vector<int>> testCases = {
        {1, 10, 3, 10, 2},                    // Normal case
        {7, 7, 7, 7, 12, 7, 7},               // Exact bouquet fit
        {3, 2, 4},                            // Single bouquet possible
        {1, 2, 3},                            // Impossible case
        {5, 5, 5, 5, 5},                      // All same values
        {1000000000, 1000000000, 1000000000}, // Extreme large values
        {10, 9, 8, 7, 6, 1, 2, 3}             // Late blooming case
    };

    vector<int> mVals = {3, 2, 1, 2, 2, 1, 2};
    vector<int> kVals = {1, 3, 2, 2, 2, 3, 2};

    cout << "Running Test Cases...\n";
    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Brute Force Result: " << minNumberOfDaysBrute(testCases[i], mVals[i], kVals[i]) << endl;
        cout << "Optimal Result: " << minDaysOptimal(testCases[i], mVals[i], kVals[i]) << endl;
        cout << "--------------------------\n";
    }

    return 0;
}
