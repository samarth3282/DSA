#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            freq[b[i]]++;
        }

        vector<int> a(n, 0);
        bool valid = true;
        int next_value = 1;

        for (int occ_count = 1; occ_count <= n; occ_count++)
        {
            if (freq[occ_count] == 0)
                continue;

            if (freq[occ_count] % occ_count != 0)
            {
                valid = false;
                break;
            }

            int num_groups = freq[occ_count] / occ_count;

            vector<int> positions;
            for (int i = 0; i < n; i++)
            {
                if (b[i] == occ_count)
                {
                    positions.push_back(i);
                }
            }

            for (int group = 0; group < num_groups; group++)
            {
                int current_value = next_value++;
                for (int j = 0; j < occ_count; j++)
                {
                    int pos = positions[group * occ_count + j];
                    a[pos] = current_value;
                }
            }
        }

        if (!valid)
        {
            cout << -1 << "\n";
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << a[i];
                if (i < n - 1)
                    cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}