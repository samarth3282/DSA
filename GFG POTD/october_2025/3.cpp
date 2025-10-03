// Possible Words From Phone Digits
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rec(int index, vector<int> &arr, vector<string> &ans, string &str, map<int, string> &mpp)
    {
        if (index == arr.size())
        {
            ans.push_back(str);
            return;
        }
        if (arr[index] == 0 || arr[index] == 1)
            rec(index + 1, arr, ans, str, mpp);
        for (int i = 0; i < mpp[arr[index]].length(); i++)
        {
            str.push_back(mpp[arr[index]][i]);
            rec(index + 1, arr, ans, str, mpp);
            str.pop_back();
        }
    }
    vector<string> possibleWords(vector<int> &arr)
    {
        // code here
        string str;
        vector<string> ans;
        map<int, string> mpp = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}};
        rec(0, arr, ans, str, mpp);
        return ans;
    }
};