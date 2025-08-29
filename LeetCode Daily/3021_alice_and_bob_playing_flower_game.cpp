#include <bits/stdc++.h>
using namespace std;
long long flowerGame(int n, int m)
{
    long long neven = n / 2;
    long long meven = m / 2;
    long long nodd = (n + 1) / 2;
    long long modd = (m + 1) / 2;
    return neven * modd + nodd * meven;
}
int main()
{

    return 0;
}