// 1518. Water Bottles

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int n = numBottles;
        long long ans = n;
        while (n >= numExchange)
        {
            int temp = n / numExchange;
            int rem = n % numExchange;
            ans += temp;
            n = (temp + rem);
        }
        return ans;
    }
};