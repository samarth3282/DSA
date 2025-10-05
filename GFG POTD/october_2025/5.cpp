// Rat in a Maze
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rec(int i, int j, string &temp, vector<string> &ans,
             vector<vector<bool>> &visited, vector<vector<int>> &maze)
    {

        int n = maze.size();

        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(temp);
            return;
        }

        if (i + 1 < n && !visited[i + 1][j] && maze[i + 1][j] == 1)
        {
            temp.push_back('D');
            visited[i + 1][j] = true;
            rec(i + 1, j, temp, ans, visited, maze);
            visited[i + 1][j] = false;
            temp.pop_back();
        }

        if (i - 1 >= 0 && !visited[i - 1][j] && maze[i - 1][j] == 1)
        {
            temp.push_back('U');
            visited[i - 1][j] = true;
            rec(i - 1, j, temp, ans, visited, maze);
            visited[i - 1][j] = false;
            temp.pop_back();
        }

        if (j + 1 < n && !visited[i][j + 1] && maze[i][j + 1] == 1)
        {
            temp.push_back('R');
            visited[i][j + 1] = true;
            rec(i, j + 1, temp, ans, visited, maze);
            visited[i][j + 1] = false;
            temp.pop_back();
        }

        if (j - 1 >= 0 && !visited[i][j - 1] && maze[i][j - 1] == 1)
        {
            temp.push_back('L');
            visited[i][j - 1] = true;
            rec(i, j - 1, temp, ans, visited, maze);
            visited[i][j - 1] = false;
            temp.pop_back();
        }
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size();
        vector<string> ans;

        if (maze[0][0] == 0)
            return ans;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        string temp = "";
        rec(0, 0, temp, ans, visited, maze);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
