#include <bits/stdc++.h>
using namespace std;

void reversearr(int *arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    swap(arr[l], arr[r]);
    reversearr(arr, l + 1, r - 1);
}

void reversearr2(int *arr, int i, int n)
{
    if (i >= (n / 2))
    {
        return;
    }
    swap(arr[i], arr[n - i - 1]);
    reversearr2(arr, i + 1, n);
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << "th element: ";
        cin >> arr[i];
    }

    reversearr2(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}