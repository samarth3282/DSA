#include <bits/stdc++.h>
using namespace std;

/*
    BRUTE-FORCE APPROACH 1:
    Traverse each element in the matrix and compare with target.
    Time Complexity: O(m * n)
    Space Complexity: O(1)
*/
bool searchMatrixBrute1(const vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

/*
    BRUTE-FORCE APPROACH 2:
    Flatten the matrix into a 1D array, then perform linear search.
    Time Complexity: O(m * n)
    Space Complexity: O(m * n)
*/
bool searchMatrixBrute2(const vector<vector<int>> &matrix, int target)
{
    vector<int> flat;
    for (auto &row : matrix)
    {
        for (int val : row)
        {
            flat.push_back(val);
        }
    }
    for (int val : flat)
    {
        if (val == target)
            return true;
    }
    return false;
}

/*
    BETTER APPROACH:
    Binary search on each row (if target is within row range).
    Time Complexity: O(m * log n)
    Space Complexity: O(1)
*/
bool searchMatrixBetter(const vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (target >= matrix[i][0] && target <= matrix[i].back())
        {
            int low = 0, high = matrix[0].size() - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (matrix[i][mid] == target)
                    return true;
                else if (matrix[i][mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
    }
    return false;
}

/*
    OPTIMAL APPROACH:
    Treat the 2D matrix as a 1D sorted array and apply binary search.
    Use index conversion: mid / cols → row, mid % cols → col
    Time Complexity: O(log(m * n))
    Space Complexity: O(1)
*/
bool searchMatrixOptimal(const vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int low = 0, high = rows * cols - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int rowIndex = mid / cols;
        int colIndex = mid % cols;

        if (matrix[rowIndex][colIndex] == target)
            return true;
        else if (matrix[rowIndex][colIndex] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

// ------------------ Test Cases ------------------

void runTests()
{
    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    assert(searchMatrixBrute1(matrix1, 3) == true);
    assert(searchMatrixBrute2(matrix1, 13) == false);
    assert(searchMatrixBetter(matrix1, 11) == true);
    assert(searchMatrixOptimal(matrix1, 34) == true);
    assert(searchMatrixOptimal(matrix1, 2) == false);

    vector<vector<int>> matrix2 = {{1}};
    assert(searchMatrixOptimal(matrix2, 1) == true);
    assert(searchMatrixBetter(matrix2, 0) == false);

    vector<vector<int>> matrix3 = {
        {1, 4},
        {6, 8}};
    assert(searchMatrixOptimal(matrix3, 8) == true);
    assert(searchMatrixOptimal(matrix3, 7) == false);

    cout << "All test cases passed ✅" << endl;
}

int main()
{
    runTests();
    return 0;
}
