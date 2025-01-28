#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(int n, int start, vector<int> adjc[])
{
    int vis[n + 1] = {0};
    vector<int> finalAns;
    dfsHelper(start, vis, adjc, finalAns);
    return finalAns;
}

void dfsHelper(int node, int vis[], vector<int> adjc[], vector<int> &finalAns)
{
    vis[node] = 1;
    finalAns.push_back(node);
    for (auto it : adjc[node])
    {
        if (!vis[it])
        {
            dfsHelper(it, vis, adjc, finalAns);
        }
    }
}

vector<int> bfs(int n, int start, vector<int> adjc[])
{
    int vis[n + 1] = {0};
    vis[start] = 1;
    vector<int> finalAns;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        finalAns.push_back(node);
        for (auto it : adjc[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return finalAns;
}

int main()
{

    return 0;
}