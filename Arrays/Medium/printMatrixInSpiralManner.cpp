#include <bits/stdc++.h>
using namespace std;

/**
 * Function: printMatrixInSpiralBrute
 * -----------------------------------
 * Brute-force approach using a visited matrix to track traversed cells.
 * Uses an extra matrix of size MxN for marking visited elements.
 *
 * @param arr - Reference to a 2D vector (matrix).
 * @return A vector containing elements of the matrix in spiral order.
 *
 * Approach:
 * - Use a boolean visited matrix to keep track of traversed elements.
 * - Use direction arrays `dr` and `dc` to move Right, Down, Left, Up cyclically.
 * - If the next cell is valid and unvisited, move forward; otherwise, change direction.
 *
 * T.C: O(M * N) - We traverse every element once.
 * S.C: O(M * N) - Extra space used for the visited matrix.
 */
vector<int> printMatrixInSpiralBrute(vector<vector<int>> &arr)
{
    int m = arr.size(), n = arr[0].size();
    vector<int> ans;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int row = 0, col = 0, dir = 0;
    int dr[] = {0, 1, 0, -1}; // Right, Down, Left, Up
    int dc[] = {1, 0, -1, 0};

    for (int i = 0; i < m * n; i++)
    {
        ans.push_back(arr[row][col]);
        visited[row][col] = true;
        int newRow = row + dr[dir], newCol = col + dc[dir];

        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol])
        {
            row = newRow;
            col = newCol;
        }
        else
        {
            dir = (dir + 1) % 4; // Change direction
            row += dr[dir];
            col += dc[dir];
        }
    }
    return ans;
}

/**
 * Function: printMatrixInSpiralOptimal
 * -----------------------------------
 * Optimal approach without extra space.
 * Uses four boundaries (left, right, top, bottom) to control traversal.
 *
 * @param arr - Reference to a 2D vector (matrix).
 * @return A vector containing elements of the matrix in spiral order.
 *
 * Approach:
 * - Start with four boundaries: left, right, top, and bottom.
 * - Traverse in the order: left → right, top → bottom, right → left, bottom → top.
 * - Adjust boundaries after each pass.
 * - Stop when all elements are visited.
 *
 * T.C: O(M * N) - Every element is visited exactly once.
 * S.C: O(1) - No extra space used.
 */
vector<int> printMatrixInSpiralOptimal(vector<vector<int>> &arr)
{
    int m = arr.size(), n = arr[0].size();
    vector<int> ans;
    int left = 0, right = n - 1, top = 0, bottom = m - 1;

    while (left <= right && top <= bottom)
    {
        // Traverse from left to right
        for (int i = left; i <= right; i++)
            ans.push_back(arr[top][i]);
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++)
            ans.push_back(arr[i][right]);
        right--;

        // Traverse from right to left (if there's a row remaining)
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(arr[bottom][i]);
            bottom--;
        }

        // Traverse from bottom to top (if there's a column remaining)
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(arr[i][left]);
            left++;
        }
    }
    return ans;
}

/**
 * Function: runTestCases
 * ----------------------
 * Runs multiple test cases to validate both brute-force and optimal approaches.
 */
void runTestCases()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    cout << "Matrix:" << endl;
    for (auto &row : matrix)
    {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }

    vector<int> bruteResult = printMatrixInSpiralBrute(matrix);
    vector<int> optimalResult = printMatrixInSpiralOptimal(matrix);

    cout << "\nBrute Force Result: ";
    for (int num : bruteResult)
        cout << num << " ";
    cout << endl;

    cout << "Optimal Result: ";
    for (int num : optimalResult)
        cout << num << " ";
    cout << endl;
}

int main()
{
    runTestCases();
    return 0;
}