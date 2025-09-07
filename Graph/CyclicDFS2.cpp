/*
    A
   / \
  B---C  IN B: b neighbors is A , C , but A is already visited , 
  But Important condition is here , A is parent of B , so it will not consider in cycle

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool dfs(vector<bool> &visited,unordered_map<int, int> &parent,vector<vector<int>> &adj,int node) {
    visited[node]=true;

    for(auto neighbor:adj[node]){
        if(!visited[neighbor]) {
           parent[neighbor]=node;
           if(dfs(visited, parent, adj, neighbor)){
            return true;
           }
        }
        else if(neighbor != parent[node]) {
            return true;
        }
    }
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
        // adj[v].push_back(u);
    }

    vector<bool> visited(V, false);
    unordered_map<int, int> parent; // node, parent
    parent[0] = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(visited, parent, adj, i))
            {
                cout << "Cycle detected starting from node " << i << endl;
                return 0;
            }
        }
    }
    cout<<"No cycle detected";
    return 0;
}