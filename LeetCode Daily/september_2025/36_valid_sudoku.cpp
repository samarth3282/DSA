#include <bits/stdc++.h>
using namespace std;
bool isValidSudoku(vector<vector<char>> &board)
{
    // Check rows
    for (int i = 0; i < 9; i++)
    {
        set<char> st;
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                continue;
            if (st.find(board[i][j]) != st.end())
                return false;
            st.insert(board[i][j]);
        }
    }

    for (int j = 0; j < 9; j++)
    {
        set<char> st;
        for (int i = 0; i < 9; i++)
        {
            if (board[i][j] == '.')
                continue;
            if (st.find(board[i][j]) != st.end())
                return false;
            st.insert(board[i][j]);
        }
    }

    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            set<char> st;
            for (int k = i; k < i + 3; k++)
            {
                for (int l = j; l < j + 3; l++)
                {
                    if (board[k][l] == '.')
                        continue;
                    if (st.find(board[k][l]) != st.end())
                        return false;
                    st.insert(board[k][l]);
                }
            }
        }
    }

    return true;
}
int main()
{

    return 0;
}