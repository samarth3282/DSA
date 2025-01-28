#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> rotateMatrixBrute(vector<vector<int>> &arr)
{
    vector<vector<int>> ans;
    int rows = arr.size();
    int columns = arr[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            ans[j][columns - 1 - i] = arr[i][j];
        }
    }
    return ans;
}

void rotateMatrixBetter(vector<vector<int>> &arr)
{
    // vector<vector<int>> ans;

    int rows = arr.size();
    int cols = arr[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = i + 1; j < cols; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    rotateMatrixBetter(arr);
    for (auto it : arr)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
    return 0;
}