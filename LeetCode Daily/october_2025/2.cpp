// 3100. Water Bottles II
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int drink = 0;
        while (numBottles >= numExchange)
        {
            drink += numExchange;
            numBottles -= numExchange;
            numBottles++;
            numExchange++;
        }
        return drink + numBottles;
    }
};