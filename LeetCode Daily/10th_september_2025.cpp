// 1733. Minimum Number of People to Teach

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        unordered_set<int> unhappy;
        for (int i = 0; i < friendships.size(); i++)
        {
            int u = friendships[i][0] - 1;
            int v = friendships[i][1] - 1;

            unordered_set<int> uKnownLangs(begin(languages[u]), end(languages[u]));
            bool intersect = false;
            for (int j = 0; j < languages[v].size(); j++)
            {
                if (uKnownLangs.find(languages[v][j]) != uKnownLangs.end())
                {
                    intersect = true;
                    break;
                }
            }
            if (!intersect)
            {
                unhappy.insert(u);
                unhappy.insert(v);
            }
        }

        map<int, int> langFreq;
        int maxKnown = 0;
        for (auto sadUser : unhappy)
        {
            for (auto lang : languages[sadUser])
            {
                langFreq[lang]++;
                maxKnown = max(maxKnown, langFreq[lang]);
            }
        }
        return unhappy.size() - maxKnown;
    }
};