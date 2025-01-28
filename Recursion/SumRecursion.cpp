#include <bits/stdc++.h>
using namespace std;

void findsum(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    findsum(i - 1, sum + i);
}

int findsum2(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (n + findsum2(n - 1));
    }
}
int findfactorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * findfactorial(n - 1);
}
void findfactorial2(int i, int prod)
{
    if (i < 1)
    {
        cout << prod;
        return;
    }
    findfactorial2(i - 1, prod * i);
}
int main()
{
    int n;
    cin >> n;
    findfactorial2(3, 1);
    return 0;
}