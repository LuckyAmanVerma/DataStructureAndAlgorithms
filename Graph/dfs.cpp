/*
DFS for Disconnected Graphs (Template same as BFS)
           0
          / \
         1   2
        / \
       3   4

*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> DFS(const vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false); // Track visited nodes
    vector<int> dfsResult; // Store DFS traversal result
    stack<int> s; // Stack for DFS

    // For disconnected graphs, start DFS from every unvisited node
    for (int start = 0; start < V; ++start) {
        if (!visited[start]) {
            s.push(start);
           
            while (!s.empty()) {
                int node = s.top();
                s.pop();
                visited[node] = true;
                dfsResult.push_back(node);

                // Visit all the neighbors of the current node
                // (push unvisited neighbors to stack)
                for(int i=adj[node].size()-1; i>=0; --i) {
                    int neighbor = adj[node][i];
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        s.push(neighbor);
                    }
                }
            }
        }
    }
    return dfsResult;
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

    // Perform DFS
    vector<int> dfsResult = DFS(adj, V); //dfsResult=[1, 2, 0, 4, 3]
    cout << "DFS Traversal: ";
    for (int node : dfsResult) { 
        cout << node << " ";  
    }
    cout << endl;

    return 0;
}
