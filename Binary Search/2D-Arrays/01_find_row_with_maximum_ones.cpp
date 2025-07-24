#include <bits/stdc++.h>
using namespace std;

/*
========================
BRUTE FORCE APPROACH 1:
========================
- For each row, count 1s using a loop.
- Track the row with maximum number of 1s.

Time Complexity: O(n * m)
Space Complexity: O(1)
Feasible? ✅
*/
pair<int, int> rowWithMaximumOnesBrute1(vector<vector<int>> &mat)
{
    int rowIndex = -1;
    int maxCount = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 1)
                count++;
        }
        if (count > maxCount)
        {
            maxCount = count;
            rowIndex = i;
        }
    }
    return {rowIndex == -1 ? 0 : rowIndex, maxCount};
}

/*
========================
BRUTE FORCE APPROACH 2:
========================
- Sort each row (forces all 0s to the left, 1s to the right).
- Binary search for the first 1, then count 1s from that index.

Time Complexity: O(n * m*logm) due to sorting
Space Complexity: O(1)
Feasible? ❌ (Inefficient due to sort overhead)
*/
pair<int, int> rowWithMaximumOnesBrute2(vector<vector<int>> mat)
{
    int maxCount = 0, rowIndex = -1;
    for (int i = 0; i < mat.size(); i++)
    {
        sort(mat[i].begin(), mat[i].end()); // modifies original matrix
        int low = 0, high = mat[i].size() - 1;
        int firstOneIndex = mat[i].size();
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mat[i][mid] == 1)
            {
                firstOneIndex = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        int ones = mat[i].size() - firstOneIndex;
        if (ones > maxCount)
        {
            maxCount = ones;
            rowIndex = i;
        }
    }
    return {rowIndex == -1 ? 0 : rowIndex, maxCount};
}

/*
========================
BETTER APPROACH:
========================
- Use binary search directly (assuming row is sorted).
- Don't sort the matrix. Just apply BS to find the first 1.

Time Complexity: O(n * log m)
Space Complexity: O(1)
Feasible? ✅
*/
pair<int, int> rowWithMaximumOnesBetter(vector<vector<int>> &mat)
{
    int maxCount = 0, rowIndex = -1;
    for (int i = 0; i < mat.size(); i++)
    {
        int low = 0, high = mat[i].size() - 1;
        int firstOneIndex = mat[i].size();
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mat[i][mid] == 1)
            {
                firstOneIndex = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        int ones = mat[i].size() - firstOneIndex;
        if (ones > maxCount)
        {
            maxCount = ones;
            rowIndex = i;
        }
    }
    return {rowIndex == -1 ? 0 : rowIndex, maxCount};
}

/*
========================
OPTIMAL APPROACH:
========================
- Start from top-right.
- If you see a 1, move left (we found 1 earlier).
- If you see a 0, move down (next row).
- Count how far we move left = number of 1s.

Time Complexity: O(n + m)
Space Complexity: O(1)
Feasible? ✅ Best choice
*/
pair<int, int> rowWithMaximumOnesOptimal(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int maxRowIndex = 0;
    int col = m - 1; // Start from top-right corner

    for (int row = 0; row < n; row++)
    {
        while (col >= 0 && mat[row][col] == 1)
        {
            maxRowIndex = row;
            col--;
        }
    }

    int onesCount = m - col - 1;
    return {maxRowIndex, onesCount};
}

/*
========================
DRIVER + TEST CASES
========================
*/
int main()
{
    vector<vector<int>> testCase1 = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}};
    vector<vector<int>> testCase2 = {
        {0, 0},
        {0, 0}};
    vector<vector<int>> testCase3 = {
        {0, 1, 1},
        {1, 1, 1},
        {0, 0, 1}};
    vector<vector<int>> testCase4 = {
        {1, 1},
        {1, 1}};
    vector<vector<int>> testCase5 = {
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 1, 1, 1}};

    cout << "Testing Optimal Approach:" << endl;
    vector<vector<vector<int>>> testCases = {
        testCase1, testCase2, testCase3, testCase4, testCase5};

    for (auto &tc : testCases)
    {
        pair<int, int> result = rowWithMaximumOnesOptimal(tc);
        cout << "Row: " << result.first << ", Ones: " << result.second << endl;
    }

    return 0;
}
