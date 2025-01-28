#include <bits/stdc++.h>
using namespace std;

int reverse(int n)
{
    int reverseNumber = 0;
    while (n > 0)
    {
        int dgt = n % 10;
        reverseNumber = reverseNumber * 10 + dgt;
        n = n / 10;
    }
    return reverseNumber;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << reverse(n);
        cout << endl;
        cout << endl;
    }

    return 0;
}