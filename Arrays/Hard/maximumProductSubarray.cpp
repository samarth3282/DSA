#include <bits/stdc++.h>
using namespace std;
int maximumProdSubarray(vector<int> &arr)
{
    int preProd = 1;
    int sufProd = 1;
    int maxProd = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (preProd == 0)
            preProd = 1;
        if (sufProd == 0)
            sufProd = 1;
        preProd *= arr[i];
        sufProd *= arr[arr.size() - i - 1];
        maxProd = max(maxProd, max(preProd, sufProd));
    }
    return maxProd;
}
int main()
{

    return 0;
}