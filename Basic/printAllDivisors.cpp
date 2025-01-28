#include <bits/stdc++.h>
using namespace std;

void divisors1(int n) // T.C. = O(n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}
void divisors2(int n) // T.C. = O(sqrt(n) + NlogN + N) : N = number of factors
{
    vector<int> lst;
    // O(sqrt(n))
    for (int i = 1; i * i <= n; i++) // instead of using sqrt(n), use i*i because calling sqrt() takes much more time.
    {
        if (n % i == 0)
        {
            lst.push_back(i);
            if ((n / i) != i)
            {
                lst.push_back((n / i));
            }
        }
    }
    sort(lst.begin(), lst.end()); // O(nlog(n)) : n is number of factors
    for (auto it : lst)           // O(number of factors)
    {
        cout << it << " ";
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        divisors2(n);
        cout << endl;
        cout << endl;
    }

    return 0;
}