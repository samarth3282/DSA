#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    long long cost = 0;
    vector<long long> d(n + 1, 0);
    long long max_d_prefix = 0;

    for (int i = 1; i <= n; ++i)
    {
        long long current_d;
        if (i % 2 != 0)
        { // Odd index
            current_d = d[i - 1] - a[i - 1];
        }
        else
        { // Even index
            current_d = d[i - 1] + a[i - 1];
        }

        if (i >= 2)
        {
            if (current_d < max_d_prefix)
            {
                cost += max_d_prefix - current_d;
                d[i] = max_d_prefix;
            }
            else
            {
                d[i] = current_d;
            }
        }
        else
        {
            d[i] = current_d;
        }

        if (i >= 1)
        {
            max_d_prefix = max(max_d_prefix, d[i - 1]);
        }
    }

    cout << cost << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}