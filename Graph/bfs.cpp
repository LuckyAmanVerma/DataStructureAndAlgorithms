// Recursive BFS helper
void BFSRecursiveUtil(const vector<vector<int>>& adj, queue<int>& q, vector<bool>& visited, vector<int>& bfsResult) {
    if (q.empty()) return;
    int node = q.front();
    q.pop();
    bfsResult.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
    BFSRecursiveUtil(adj, q, visited, bfsResult);
}

// Recursive BFS for disconnected graphs, same template as BFS
vector<int> BFSRecursive(const vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    vector<int> bfsResult;
    queue<int> q;
    for (int start = 0; start < V; ++start) {
        if (!visited[start]) {
            q.push(start);
            visited[start] = true;
            BFSRecursiveUtil(adj, q, visited, bfsResult);
        }
    }
    return bfsResult;
}
/*
We will use an adjacency list and queue to implement bfs approach , visited pair with int, bool
Graph may be multiple also , 
        0
       / \
      1   2
     / \
    3   4

*/

#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

vector<int> BFS(const vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false); // Track visited nodes
    vector<int> bfsResult; // Store BFS traversal result
    queue<int> q; // Queue for BFS

    // For disconnected graphs, start BFS from every unvisited node
    for (int start = 0; start < V; ++start) {
        if (!visited[start]) {
            q.push(start);
            visited[start] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                bfsResult.push_back(node);

                // Visit all the neighbors of the current node
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    return bfsResult;
}


int main(){
    // Create a graph
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    // Perform BFS
    vector<int> bfsResult = BFS(adj, V);
    cout << "BFS Traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}