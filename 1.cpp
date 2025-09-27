#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long score = 0;
        vector<long long> odd, even;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 1)
            {
                odd.push_back(a[i]);
            }
            else
            {
                even.push_back(a[i]);
            }
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());
        int o = 0;
        if (odd.empty())
        {
            cout << 0 << endl;
            continue;
        }
        score += odd[0];
        for (int i = 0; i < even.size(); i++)
        {
            score += even[i];
        }
        o++;
        if (!odd.empty())
        {
            for (int i = o; i < ((odd.size() - 1) / 2) + 1; i++)
            {
                score += odd[i];
            }
        }

        cout << score << endl;
    }

    return 0;
}

//