#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int left = 0;
        int right = n;
        while (left <= right)
        {
            long mid = left + (right - left) / 2;
            long curr = mid * (mid + 1) / 2;
            if (curr == n)
                return mid;
            if (curr < n)
                left = mid + 1;
            else
                right = mid - 1;
        }
        cout << right << endl;
    }
}
