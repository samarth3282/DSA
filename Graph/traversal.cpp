#include <bits/stdc++.h>
using namespace std;

// Function to perform Breadth-First Search (BFS)
// TC: O(n + m) where n is the number of nodes, m is the number of edges
// SC: O(n) for the visited array and the BFS result
vector<int> BFS(int n, vector<int> adjc[], int start)
{
    int visited[n] = {0}; // visited array to track nodes we've visited
    visited[start] = 1;   // mark the starting node as visited
    queue<int> q;
    q.push(start); // start BFS from the starting node
    vector<int> bfs;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node); // add current node to BFS result

        // Traverse all adjacent nodes
        for (auto it : adjc[node])
        {
            if (!visited[it])
            {
                visited[it] = 1; // mark adjacent node as visited
                q.push(it);      // push adjacent node into queue
            }
        }
    }
    return bfs; // return BFS traversal result
}

// Helper function for Depth-First Search (DFS)
// TC: O(n + m), SC: O(n) for visited array and DFS result
void dfsHelper(int node, vector<int> adjc[], int visited[], vector<int> &dfs)
{
    visited[node] = 1;   // mark current node as visited
    dfs.push_back(node); // add current node to DFS result

    // Traverse all adjacent nodes
    for (auto it : adjc[node])
    {
        if (!visited[it])
        {
            dfsHelper(it, adjc, visited, dfs); // recursively visit adjacent nodes
        }
    }
}

// Function to initialize and call DFS
// TC: O(n + m), SC: O(n)
vector<int> DFS(int n, vector<int> adjc[], int start)
{
    int visited[n + 1] = {0}; // visited array initialized to 0
    vector<int> dfs;
    dfsHelper(start, adjc, visited, dfs); // call the helper function
    return dfs;                           // return DFS traversal result
}

int main()
{
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    vector<int> adjc[n + 1]; // adjacency list for the graph
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjc[x].push_back(y); // add edge x to y
        adjc[y].push_back(x); // add edge y to x
    }

    int start;
    cin >> start; // starting node for traversal
    vector<int> dfsResult = DFS(n, adjc, start);

    // Print DFS result
    for (int node : dfsResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}