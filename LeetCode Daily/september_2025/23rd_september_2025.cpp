// 165. Compare Version Numbers
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> v1, v2;
        string token;

        stringstream ss1(version1);
        while (getline(ss1, token, '.'))
            v1.push_back(stoi(token));

        stringstream ss2(version2);
        while (getline(ss2, token, '.'))
            v2.push_back(stoi(token));

        int n = max(v1.size(), v2.size());
        v1.resize(n, 0);
        v2.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (v1[i] > v2[i])
                return 1;
            if (v1[i] < v2[i])
                return -1;
        }
        return 0;
    }
};
