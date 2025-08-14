#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bfsWithCycleCheckDirected(int start,
                               const vector<vector<int>> &adj,
                               vector<bool> &visited) 
{
    vector<bool> inQueue(adj.size(), false); // track nodes in current BFS path
    queue<int> q;
    q.push(start);
    visited[start] = true;
    inQueue[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        inQueue[node] = false; // node fully processed (out of path)

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
                inQueue[neighbour] = true;
            }
            else if (inQueue[neighbour]) {
                // Found a node in current path → cycle
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Example directed cycle:
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[3].push_back(4);

    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (bfsWithCycleCheckDirected(i, adj, visited)) {
                cout << "Cycle detected" << endl;
                return 0;
            }
        }
    }

    cout << "No cycle detected" << endl;
    return 0;
}
