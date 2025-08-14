#include <bits/stdc++.h>
using namespace std;

bool dfs(int start,
         vector<bool> &visited,
         const vector<vector<int>> &adjList)
{
    stack<pair<int, int>> s; // pair<node, parent>
    s.push({start, -1});
    visited[start] = true;

    while (!s.empty())
    {
        auto [node, parent] = s.top();
        s.pop();

        for (int idx = int(adjList[node].size()) - 1; idx >= 0; --idx)
        {
            int neigh = adjList[node][idx];
            if (!visited[neigh])
            {
                visited[neigh] = true;
                s.push({neigh, node});
                // dfs(neigh, visited, adjList);
            }
            else if (neigh != parent)
            {
                // Found a visited neighbor that is not the parent ⇒ cycle
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adjList(V);
    for (int i = 0; i < E; ++i)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            if (dfs(i, visited, adjList))
                return true;
        }
    }
    return false;
}

int main()
{
    // Example test case
    int V = 5, E = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1} // This creates a cycle
    };

    if (hasCycle(V, E, edges))
        cout << "Graph is cyclic\n";
    else
        cout << "Graph is acyclic\n";

    return 0;
}
