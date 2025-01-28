#include <bits/stdc++.h>
using namespace std;
bool palindrome(int n)
{
    int rev = 0, temp = n;
    while (temp != 0)
    {
        int rem = temp % 10;
        rev = rev * 10 + rem;
        temp /= 10;
    }
    if (n == rev)
    {
        return true;
    }
    else
    {
        return false;
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
        cout << palindrome(n);
        cout << endl;
        cout << endl;
    }

    return 0;
}