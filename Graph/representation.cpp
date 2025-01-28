#include <bits/stdc++.h>
using namespace std;

int main()
{
    // MATRIX REPRESENTATION FOR AN UNDIRECTED GRAPH
    // TC: O(n^2), SC: O(n^2)
    int n, m;
    cin >> n >> m;
    int adjMatrix[n + 1][n + 1] = {0}; // Initializing with zeros
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1; // For undirected graph
    }

    // ADJACENCY LIST FOR AN UNDIRECTED GRAPH
    // TC: O(m), SC: O(n+m)
    vector<int> adjList[n + 1]; // Vector to store adjacency list
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x); // For undirected graph
    }

    // ADJACENCY LIST FOR A DIRECTED GRAPH
    // TC: O(m), SC: O(n+m)
    vector<int> adjListDirected[n + 1]; // Vector to store adjacency list for directed graph
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjListDirected[x].push_back(y); // Only x -> y for directed graph
    }

    // WEIGHTED MATRIX REPRESENTATION FOR AN UNDIRECTED GRAPH
    // TC: O(n^2), SC: O(n^2)
    int adjWeightedMatrix[n + 1][n + 1] = {0}; // Initializing with zeros
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        adjWeightedMatrix[x][y] = wt;
        adjWeightedMatrix[y][x] = wt; // For undirected graph
    }

    // ADJACENCY LIST WITH WEIGHTS FOR AN UNDIRECTED GRAPH
    // TC: O(m), SC: O(n+m)
    vector<pair<int, int>> adjWeightedList[n + 1]; // Vector of pairs for adjacency list with weights
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        adjWeightedList[x].push_back({y, wt});
        adjWeightedList[y].push_back({x, wt}); // For undirected graph
    }

    return 0;
}
