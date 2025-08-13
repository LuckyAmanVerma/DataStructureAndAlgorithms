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

bool bfsWithCycleCheck(int start,
                       const vector<vector<int>> &adj,
                       vector<bool> &visited,
                       unordered_map<int, int> &parent)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1; // Root node has no parent

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                parent[neigh] = node;
                q.push(neigh);
            } else if (parent[node] != neigh) {
                // Found a visited node that's not parent; cycle detected
                return true;
            }
        }
    }
    return false;
}