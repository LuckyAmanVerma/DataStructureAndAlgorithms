void dfs(int start,
         vector<bool> &visited,
         const vector<vector<int>> &adjList,
         vector<int> &component)
{
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        component.push_back(node);

        // iterate neighbors in reverse if you want the same order as recursive DFS
        for (int idx = int(adjList[node].size()) - 1; idx >= 0; --idx)
        {
            int neigh = adjList[node][idx];
            if (!visited[neigh])
            {
                visited[neigh] = true;
                s.push(neigh);
                // dfs(neigh, visited, adjList, component);
            }
        }
    }
}

vector<vector<int>> depthFirstSearch(int V,
                                     int E,
                                     vector<vector<int>> &edges)
{
    // build adjacency list
    vector<vector<int>> adjList(V);
    for (int i = 0; i < E; ++i)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    vector<bool> visited(V, false);

    // run DFS on each component
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }

    return ans;
}