class Solution
{
public:
    int makeTheIntegerZero(int num1, int num2)
    {
        for (long long t = 1; t <= 60; t++)
        {
            long long val = 1LL * num1 - 1LL * t * num2;
            if (val < 0)
                return -1;
            if (__builtin_popcountll(val) <= t && t <= val)
                return t;
        }
        return -1;
    }
};
