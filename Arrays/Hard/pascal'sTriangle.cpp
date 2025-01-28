#include <bits/stdc++.h>
using namespace std;

int findTheElementExtremeBrute(int r, int c)
{
    int r_fact = 1;
    int c_fact = 1;
    int r_minus_c_fact = 1;

    for (int i = 1; i <= r; i++)
    {
        r_fact *= i;
    }
    for (int i = 1; i <= c; i++)
    {
        c_fact *= i;
    }
    for (int i = 1; i <= r - c; i++)
    {
        r_minus_c_fact *= i;
    }

    return (r_fact / (c_fact * r_minus_c_fact));
}
long long findTheElementOptimal(int r, int c)
{
    long long num = 1;

    for (int i = 0; i < c; i++)
    {
        num = num * (r - i);
        num = num / (i + 1);
    }
    return num;
}

void printTheSequenceOfNthRowInPascalsTriangleBrute(int row)
{
    for (int i = 1; i <= row; i++)
    {
        cout << (findTheElementOptimal(row - 1, i - 1)) << " ";
    }
}

void printTheSequenceOfNthRowInPascalsTriangleOptimal(int row)
{
    long long ans = 1;
    cout << ans << " ";

    for (int i = 1; i < row; i++)
    {
        ans = (ans * (row - i));
        ans = ans / i;
        if (i != row - 1)
        {
            cout << ans << " ";
        }
        else
        {
            cout << ans;
        }
    }
}

vector<vector<long long>> printEntirePascalsTriangleBrute(int row)
{
    vector<vector<long long>> ans;
    for (int rowNumber = 1; rowNumber <= row; rowNumber++)
    {
        vector<long long> temp;
        for (int colNumber = 1; colNumber <= row; colNumber++)
        {
            long long num = findTheElementOptimal(rowNumber - 1, colNumber - 1);
            temp.push_back(num);
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<long long>> generatePascalsTriangle(int numRows)
{
    vector<vector<long long>> triangle;

    for (int row = 1; row <= numRows; row++)
    {
        vector<long long> currentRow;
        long long element = 1;
        currentRow.push_back(element);

        for (int col = 1; col < row; col++)
        {
            element = (element * (row - col)) / col;
            currentRow.push_back(element);
        }

        triangle.push_back(currentRow);
    }

    return triangle;
}

int main()
{
    vector<vector<long long>> triangle = generatePascalsTriangle(100);
    for (int i = 0; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}