#include <bits/stdc++.h>
using namespace std;
int func(vector<int> &arr)
{
    int n = nums.size();

    int maxNum = *max_element(nums.begin(), nums.end());

    vector<int> freq(maxNum + 1, 0);

    for (int i = 0; i <= n - k; i++)
    {
        set<int> uniqueElements;
        for (int j = i; j < i + k; j++)
        {
            uniqueElements.insert(nums[j]);
        }
        for (int num : uniqueElements)
        {
            freq[num]++;
        }
    }

    int result = -1;

    for (int i = maxNum; i >= 0; i--)
    {
        if (freq[i] == 1)
        {
            result = i;
            break;
        }
    }

    return result;
}
int main()
{

    return 0;
}