#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int x, int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return true;
        }
    }
    return false;
}
int longestConsecutiveSequenceBrute(int arr[], int size)
{
    int maxLen = 0;
    for (int i = 0; i < size; i++)
    {
        int x = arr[i];
        int cnt = 1;
        while (linearSearch(x + 1, arr, size) == true)
        {
            x++;
            cnt++;
        }
        maxLen = max(cnt, maxLen);
    }
    return maxLen;
}


int longestConsecutiveSequenceBetter(vector<int> &arr)
{
    int lastSmaller = arr[0];

    sort(arr.begin(), arr.end());
    int currCnt = 1;
    int longest = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == lastSmaller + 1)
        {
            currCnt++;
            lastSmaller = arr[i];
        }
        else if (lastSmaller != arr[i])
        {
            currCnt = 1;
            lastSmaller = arr[i];
        }

        longest = max(currCnt, longest);
    }
    return longest;
}

int longestConsecutiveSequenceOptimal(int arr[], int size)
{
    unordered_set<int> st;
    int longest = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        st.insert(arr[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
int main()
{
    int arr[] = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    vector<int> v = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    cout << longestConsecutiveSequenceBrute(arr, 9) << endl;
    cout << longestConsecutiveSequenceBetter(v) << endl;
    cout << longestConsecutiveSequenceOptimal(arr, 9);
    return 0;
}