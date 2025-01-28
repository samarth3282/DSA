#include <bits/stdc++.h>
using namespace std;
int hashh[101];
int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a[" << i + 1 << "]: ";
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        hashh[arr[i]]++;
    }
    int max_freq = INT_MIN;
    int max_element;
    int min_freq = INT_MAX;
    int min_element;
    for (int i = 0; i < 101; i++)
    {
        if (hashh[i] > max_freq)
        {
            max_freq = hashh[i];
            max_element = i;
        }
        if (hashh[i] > 0 && hashh[i] < max_freq)
        {
            min_freq = hashh[i];
            min_element = i;
        }
    }
    cout << "Max time occurring element is: " << max_element << endl;
    cout << "Min time occurring element is: " << min_element;
    return 0;
}