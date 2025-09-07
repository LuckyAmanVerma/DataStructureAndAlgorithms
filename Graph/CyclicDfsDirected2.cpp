/*
    A
   / \
  B---C  IN B: b neighbors is A , C , but A is already visited , 
  But Important condition is here , A is state of B , so it will not consider in cycle

  0 -> 1
  1 -> 2
  2 -> (nothing)
  (directed cycle) . undirected condition will not working here , we need to inhance else if condition here

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool dfs(vector<int> &visited, vector<vector<int>> &adj, int node) {
    visited[node] = 1; 
    for (auto neighbor : adj[node]) {
        if (visited[neighbor] == 0) {
            if (dfs(visited, adj, neighbor)) {
                return true;
            }
        }
        else if (visited[neighbor] == 1) {
            return true;
        }
    }
    visited[node] = 2; 
    return false;
}


int main()
{
    int V = 5, E = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1} // This creates a cycle
    };

    vector<vector<int>> adj(V);
    for (auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    vector<int> visited(V,0);
    for(int i=0;i<V;i++) {
     if(dfs(visited,adj,i)) {
        cout << "Cycle detected starting from node " << i << endl;
        return 0;
     }
    }
    cout<<"No cycle detected";
    return 0;
}