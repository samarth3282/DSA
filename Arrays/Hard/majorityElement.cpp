#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> &arr)
{
    vector<int> ans;
    int numberOfMajorityElements = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (ans.size() == 0 || ans[0] != arr[i])
        {

            int count = 0;
            for (int j = 0; j < arr.size(); j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
            if (count > (arr.size() / 3))
            {
                ans.push_back(arr[i]);
            }
        }

        if (ans.size() == 2)
        {
            break;
        }
    }
    return ans;
}

vector<int> majorityElementBetter(vector<int> &arr)
{
    vector<int> ans;
    map<int, int> mpp;
    int mini = int(arr.size() / 3) + 1;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;

        if (mpp[arr[i]] == mini && ans.size() <= 1)
        {
            ans.push_back(arr[i]);
        }
        if (ans.size() == 2)
            break;
    }
    return ans;
}
vector<int> majorityElementOptimal(vector<int> &arr)
{
    int cnt1 = 0;
    int el1;
    int cnt2 = 0;
    int el2;
    for (int i = 0; i < arr.size(); i++)
    {
        if (cnt1 == 0 && el2 != arr[i])
        {
            cnt1++;
            el1 = arr[i];
        }
        else if (cnt2 == 0 && el1 != arr[i])
        {
            cnt2++;
            el2 = arr[i];
        }
        else if (el1 == arr[i])
            cnt1++;
        else if (el2 == arr[i])
            cnt2++;
        else
            cnt1--, cnt2--;
    }

    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == el1)
        {
            cnt1++;
        }
        if (arr[i] == el2)
        {
            cnt2++;
        }
    }
    vector<int> temp;
    int mini = int(arr.size() / 3) + 1;
    if (cnt1 >= mini)
        temp.push_back(el1);
    if (cnt2 >= mini)
        temp.push_back(el2);
    return temp;
}
int main()
{

    return 0;
}