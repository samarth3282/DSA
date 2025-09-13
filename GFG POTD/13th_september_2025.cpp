// Minimum Cost to cut a board into squares

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(int n, int m, vector<int> &x, vector<int> &y)
    {
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());

        int i = 0, j = 0;
        int hor = 1, vert = 1;
        int cost = 0;

        while (i < m - 1 && j < n - 1)
        {
            if (x[i] > y[j])
            {
                cost += x[i] * hor;
                vert++;
                i++;
            }
            else
            {
                cost += y[j] * vert;
                hor++;
                j++;
            }
        }

        while (i < m - 1)
        {
            cost += x[i] * hor;
            vert++;
            i++;
        }

        while (j < n - 1)
        {
            cost += y[j] * vert;
            hor++;
            j++;
        }

        return cost;
    }
};
