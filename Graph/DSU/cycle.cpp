/*
Parent same cycle , otherwise Union
*/

#include <iostream>
#include <vector>
using namespace std;

int find(int i, vector<int> &parent)
{
    if (i == parent[i])
    {
        return i;
    }
    return parent[i] = find(parent[i], parent);
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);
    if (x_parent != y_parent)
    {
        if (rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else if (rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else
        {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
}

bool cycleWithEdges(int n, vector<pair<int, int>> &edges, vector<int> &parent, vector<int> &rank)
{
    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;

        int u_parent = find(u, parent);
        int v_parent = find(v, parent);

        if (u_parent == v_parent)
        {
            return true; // Cycle detected
        }
        else
        {
            Union(u_parent, v_parent, parent, rank);
        }
    }
    return false; // No cycle found
}

bool cycleWithAdjList(int n, vector<vector<int>> &adj, vector<int> &parent, vector<int> &rank)
{
    for (int u = 0; u < n; u++)
    {
        for (auto v : adj[u])
        {
            if(u > v) // To avoid processing the same edge twice
            {
                continue;
            }
            int u_parent = find(u, parent);
            int v_parent = find(v, parent);

            if (u_parent == v_parent)
            {
                return true; // Cycle detected
            }
            else
            {
                Union(u_parent, v_parent, parent, rank);
            }
        }
    }
    return false; // No cycle found
}

int main()
{
    vector<pair<int, int>> edges;
    for (int i = 0; i < 100; i++)
    {
        for (int j = i + 1; j < 100; j++)
        {
            edges.push_back({i, j});
        }
    }
    vector<vector<int>> adj(100);
    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> parent(100);
    vector<int> rank(100, 0);
    for (int i = 0; i < 100; i++)
    {
        parent[i] = i;
    }
    cout << find(10, parent) << endl;
    cout << cycleWithEdges(100, edges, parent, rank) << endl;
}