#include <bits/stdc++.h>
using namespace std;
string smallestEquivalentString(string s1, string s2, string baseStr)
{
    map<char, priority_queue<char>> mpp;

    for (int i = 0; i < s1.size(); i++)
    {
        mpp[s1[i]].push(s1[i]);
        mpp[s1[i]].push(s2[i]);
        mpp[s2[i]].push(s1[i]);
    }

    vector<set<char>> v;

    for (auto it : mpp)
    {
        set<char> st;
        auto pq = it.second; // copy the priority queue so we can pop safely
        while (!pq.empty())
        {
            st.insert(pq.top());
            pq.pop();
        }
        v.push_back(st);
    }
    for (auto &st : v)
    {
        cout << "{ ";
        for (char c : st)
            cout << c << " ";
        cout << "}" << endl;
    }
    return "";
}
int main()
{

    return 0;
}