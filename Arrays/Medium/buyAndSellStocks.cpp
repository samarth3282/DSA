#include <bits/stdc++.h>
using namespace std;

int buyAndSellStocks(int arr[], int size)
{
    int mini = arr[0];
    int maxProfit = INT_MIN;
    for (int i = 1; i < size; i++)
    {
        maxProfit = max(maxProfit, arr[i] - mini);
        mini = min(arr[i], mini);
    }
    return maxProfit;
}
int main()
{
    int arr[] = {7, 1, 5, 3, 6, 4};
    cout << buyAndSellStocks(arr, 6);
    return 0;
}