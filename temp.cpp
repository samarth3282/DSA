#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateNonEmptySubsets(const vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> result;

    for (int mask = 1; mask < (1 << n); ++mask)
    {
        vector<int> subset;
        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                subset.push_back(nums[i]);
            }
        }
        result.push_back(subset);
    }

    return result;
}
bool checkEqualPartitions(vector<int> &arr, long long target)
{
    set<int> elements;
    for (int i = 0; i < arr.size(); i++)
    {
        elements.insert(arr[i]);
    }
    vector<vector<int>> allSubsets = generateNonEmptySubsets(arr);
    for(auto it : allSubsets){
        vector<int> temp = it;
        int prod = 1;
        for (int i = 0; i < temp.size(); i++)
        {
            prod*=temp[i];
        }
        if(prod == target){
            set<int> copyElements = elements;
            for (int i = 0; i < temp.size(); i++)
            {
                copyElements.erase(temp[i]);
            }
            int prod = 1;
            for(auto it : copyElements){
                prod*=it;
            }
            if(prod == target) return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}