#include <bits/stdc++.h>
using namespace std;

void findhcf(int n, int m)
{
    int hcf = 1;
    for (int i = min(n, m); i >= 1; i--)
    {
        if (n % i == 0 && m % i == 0)
        {
            hcf = i;
            break;
        }
    }
    cout << hcf;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        findhcf(n, m);
        cout << endl;
        cout << endl;
    }

    return 0;
}