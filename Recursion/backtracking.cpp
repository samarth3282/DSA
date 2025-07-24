#include <bits/stdc++.h>
using namespace std;

void print(int i, int n)
{
    if (i > n)
    {
        return;
    }
    print(i + 1, n);
    cout << i << endl;
}

void printOnBack(int currnum, int n)
{
    if (currnum == n + 1)
        return;
    printOnBack(currnum + 1, n);
    cout << currnum << endl;
}
int main()
{
    int n;
    cin >> n;
    printOnBack(1, n);
    return 0;
}