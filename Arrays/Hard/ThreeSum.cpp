#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ThreeSum(vector<int> &arr)
{
    set<vector<int>> st;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            for (int k = 0; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSum(vector<int> &arr)
{
    set<vector<int>> stOfAns;
    for (int i = 0; i < arr.size(); i++)
    {
        set<int> st;
        for (int j = i + 1; j < arr.size(); j++)
        {
            int num = -(arr[i] + arr[j]);
            if (st.find(num) != st.end())
            {
                vector<int> temp = {arr[i], arr[j], num};
                sort(temp.begin(), temp.end());
                stOfAns.insert(temp);
            }
            st.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(stOfAns.begin(), stOfAns.end());
    return ans;
}

vector<vector<int>> threeSymOptimal(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1;
        int k = arr.size() - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                k--;
            }
            if (sum > 0)
            {
                j++;
            }
            if (sum == 0)
            {
                vector<int> temp = {arr[i], arr[j], arr[j]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                {
                    j++;
                }
                while (j < k && arr[k] == arr[k + 1])
                {
                    k--;
                }
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}