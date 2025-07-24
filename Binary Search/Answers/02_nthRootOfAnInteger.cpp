#include <bits/stdc++.h>
using namespace std;

// Brute-force Approach: Iterative Multiplication
// Time Complexity: O(M * N), Space Complexity: O(1)
int nthRootOfMBrute(int n, int m)
{
    for (int i = 1; i <= m; i++)
    {
        long long temp = 1;
        for (int j = 0; j < n; j++)
        {
            temp *= i;
            if (temp > m)
                break;
        }
        if (temp == m)
            return i;
    }
    return -1;
}

// Better Approach: Using Power Function (O(log M) Complexity)
// Time Complexity: O(log M), Space Complexity: O(1)
int nthRootOfMBetter(int n, int m)
{
    int root = round(pow(m, 1.0 / n));
    return (pow(root, n) == m) ? root : -1;
}

// Helper Function to Check if Mid is nth Root of M
int isNthRootOfM(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= mid;
        if (ans > m)
            return 1;
    }
    return (ans == m) ? 0 : -1;
}

// Optimal Approach: Binary Search
// Time Complexity: O(log M * N), Space Complexity: O(1)
int nthRootOfMOptimal(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int result = isNthRootOfM(mid, n, m);
        if (result == 0)
            return mid;
        else if (result == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// Driver Code with Test Cases
int main()
{
    vector<tuple<int, int>> testCases = {{3, 27}, {4, 16}, {2, 10}, {5, 243}, {6, 729}};

    for (auto &[n, m] : testCases)
    {
        cout << "Brute Force: " << nthRootOfMBrute(n, m) << endl;
        cout << "Better Approach: " << nthRootOfMBetter(n, m) << endl;
        cout << "Optimal Approach: " << nthRootOfMOptimal(n, m) << endl;
        cout << "----------------------------" << endl;
    }
    return 0;
}
