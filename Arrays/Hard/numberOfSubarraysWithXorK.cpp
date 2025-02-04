#include <bits/stdc++.h>
using namespace std;
int numberOfSubarraysWithXorKBrute(vector<int> &arr, int target)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            int xor_ = 0;
            for (int k = i; k <= j; k++)
            {
                xor_ = xor_ ^ arr[i];
            }
            if (xor_ == target)
            {
                count++;
            }
        }
    }
    return count;
}

int numberOfSubarraysWithXorKBetter(vector<int> &arr, int target)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int xor_ = 0;
        for (int j = i; j < arr.size(); j++)
        {
            xor_ = xor_ ^ arr[j];
            if (xor_ == target)
                count++;
        }
    }
    return count;
}

int numberOfSubarraysWithXorKOptimal(vector<int> &arr, int target)
{
    map<int, int> preXor;
    preXor[0] = 1;
    int xor_ = 0;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xor_ = xor_ ^ arr[i];
        count += preXor[xor_ ^ target];
        preXor[xor_]++;
    }
    return count;
}
int main()
{

    return 0;
}