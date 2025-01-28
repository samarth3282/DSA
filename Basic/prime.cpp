#include <bits/stdc++.h>
using namespace std;

void prime1(int n) // Brute Force Approach T.C. = O(n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
        }
    }
    if (cnt == 2)
    {
        cout << "Number is prime!";
    }
    else
    {
        cout << "Number is not prime!";
    }
}

void prime2(int n) // T.C. = O(sqrt(n))
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if ((n / i) != i)
            {
                cnt++;
            }
        }
    }
    if (cnt == 2)
    {
        cout << "Number is prime!";
    }
    else
    {
        cout << "Number is not prime!";
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
        prime2(n);
        cout << endl;
        cout << endl;
    }

    return 0;
}