#include <bits/stdc++.h>
using namespace std;
int countSubarraysWithGivenSumBrute(vector<int> &arr, int givenSum)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == givenSum)
            {
                count++;
            }
        }
    }
    return count;
}

int countSubarrayWithGivenSumBetter(vector<int> &arr, int givenSum)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {

            sum += arr[j];
            if (sum == givenSum)
            {
                count++;
            }
        }
    }
    return count;
}

int countSubarrayWithGivenSum(vector<int> &arr, int sum){
    int count = 0;
    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    for(int i = 0; i < arr.size(); i++){
        preSum+=arr[i];
        
    }
}
int main()
{

    return 0;
}