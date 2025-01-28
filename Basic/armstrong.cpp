#include <bits/stdc++.h>
using namespace std;

void armstrong(int n)
{
    int sum = 0, temp = n, digit, power = 0, numofdgts = 0;
    while (temp > 0)
    {
        digit = temp % 10;
        sum += pow(digit, 3);
        temp /= 10;
    }
    if (sum == n)
    {
        cout << "Number is Armstrong!";
    }
    else
    {
        cout << "Number is not Armstrong!";
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
        armstrong(n);
        cout << endl;
        cout << endl;
    }

    return 0;
}