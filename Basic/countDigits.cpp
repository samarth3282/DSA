#include <bits/stdc++.h>
using namespace std;
int count1(int n) // T.C. = O(log10(n)) Because here the division happens by 10.
{                 // if there is division happening by 'N' then T.C. = O(logN(n)).
    int digits = 0;
    while (n > 0)
    {
        n /= 10;
        digits++;
    }
    return digits;
}

int count2(int n)
{
    int cnt = (log10(n) + 1);
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << count2(n);
        cout << endl;
        cout << endl;
    }
    return 0;
}