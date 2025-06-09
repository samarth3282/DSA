#include <bits/stdc++.h>
using namespace std;
vector<int> minimumNumberOfCoinsOptimal(int N)
{
    vector<int> coins = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    vector<int> ans;
    while (N > 0)
    {
        int i;
        for (i = 0; i < coins.size(); i++)
        {
            if (N >= coins[i])
                break;
        }
        int times = N / coins[i];
        for (int j = 0; j < times; j++)
        {
            ans.push_back(coins[i]);
        }
        N -= times * coins[i];
    }
    return ans;
}
int main()
{

    return 0;
}