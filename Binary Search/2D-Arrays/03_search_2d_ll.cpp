#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

// 💥 Brute-force Approach 1: Traverse the entire matrix
// Time Complexity: O(n * m)
// Space Complexity: O(1)
bool searchMatrixBruteForce(vector<vector<int>> &matrix, int target)
{
    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[0].size(); col++)
        {
            if (matrix[row][col] == target)
                return true;
        }
    }
    return false;
}

// 💥 Brute-force Approach 2 (not feasible): Flatten and sort the matrix, then binary search
// Time: O(n*m + n*m*log(n*m)) = O(n*m*log(n*m))
// Space: O(n*m) extra space
bool searchMatrixBruteSortBinary(vector<vector<int>> &matrix, int target)
{
    vector<int> flattened;
    for (const auto &row : matrix)
    {
        for (int num : row)
            flattened.push_back(num);
    }
    sort(flattened.begin(), flattened.end());
    return binary_search(flattened.begin(), flattened.end(), target);
}

// 🔸 Better Approach 1: Binary search on each row (only works if every row is sorted independently)
// Time: O(n * log(m)), where n = rows, m = cols
// Space: O(1)
bool searchMatrixBetterRowBinary(vector<vector<int>> &matrix, int target)
{
    for (const auto &row : matrix)
    {
        if (binary_search(row.begin(), row.end(), target))
            return true;
    }
    return false;
}

// 🔸 Better Approach 2 (non-standard): Convert to set (loses duplicate & position info)
// Time: O(n*m), Space: O(n*m)
bool searchMatrixBetterSet(vector<vector<int>> &matrix, int target)
{
    unordered_set<int> elements;
    for (const auto &row : matrix)
        for (int val : row)
            elements.insert(val);
    return elements.count(target) > 0;
}

// ✅ Optimal Approach: Start from top-right and move accordingly
// Time Complexity: O(n + m) [at most n + m steps]
// Space Complexity: O(1)
// Works due to the sorted property: → increasing in rows and ↓ increasing in columns
bool searchMatrixOptimal(vector<vector<int>> &matrix, int target)
{
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    int row = 0, col = numCols - 1;

    while (row < numRows && col >= 0)
    {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] > target)
            col--; // move left
        else
            row++; // move down
    }
    return false;
}

// ✅ Test cases like LeetCode
void runTestCases()
{
    vector<vector<int>> matrix1 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    vector<pair<int, bool>> testTargets = {
        {5, true},    // present in middle
        {30, true},   // last element
        {1, true},    // first element
        {20, false},  // not present
        {0, false},   // smaller than smallest
        {100, false}, // larger than largest
        {17, true}    // edge row/col
    };

    for (auto &[target, expected] : testTargets)
    {
        bool result = searchMatrixOptimal(matrix1, target);
        cout << "Target = " << target << ", Found = " << (result ? "true" : "false")
             << ", Expected = " << (expected ? "true" : "false") << "\n";
        assert(result == expected);
    }

    cout << "✅ All test cases passed.\n";
}

int main()
{
    runTestCases();
    return 0;
}

int main()
{

    return 0;
}