#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        int minEl = INT_MAX, secondMin = INT_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < minEl)
            {
                secondMin = minEl;
                minEl = arr[i];
            }
            else if (arr[i] < secondMin)
            {
                secondMin = arr[i];
            }
        }

        while (k--)
        {
            int newEl = (minEl + secondMin);
            if (newEl % 2 == 0)
            {
                newEl = newEl / 2;
            }
            else
            {
                newEl = (newEl + 1) / 2;
            }
            sum += newEl;
            if (newEl < secondMin)
            {
                secondMin = newEl;
            }
            if (minEl == secondMin || minEl + 1 == secondMin)
                break;
        }
        int var = ((((minEl + secondMin) % 2) == 0) ? ((minEl + secondMin) / 2) : ((minEl + secondMin + 1) / 2));
        sum += (k * (var));
        cout << sum << endl;
    }
    return 0;
}
