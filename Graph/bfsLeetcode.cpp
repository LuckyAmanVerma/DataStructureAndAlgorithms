#include <vector>
#include <queue>
using namespace std;

void bfs(int start,
         const vector<vector<int>> &adj,
         vector<bool> &visited,
         vector<int> &ans) 
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
}

vector<int> bfsTraversal(int n, const vector<vector<int>> &adj) 
{
    vector<int> ans;
    ans.reserve(n);

    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            bfs(i, adj, visited, ans);
        }
    }

    return ans;
}