/*
Shortest Path undirected graph using BFS
Need visited , queue and parent map , 
in last we use parent map to find the path
*/

/*
Cyclic BFS Implementation
Return true if cycle else false

Parent map 
0 → 1
1 → 2
2 → 0
3 → 4
4 → 3
Graph
   2
  / \
 0 - 1       3 - 4
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
void shortestPathUndirected(int start,
                       const vector<vector<int>> &adj,
                       vector<bool> &visited,
                       unordered_map<int, int> &parent)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto neighbour:adj[node]) {
            if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push(neighbour);
                parent[neighbour] = node;
            }
            
        }
    }
    
}

vector<int> getShortestPath(int start, int destination, const unordered_map<int, int> &parent) {
    vector<int> path;
    int current = destination; // Start from destination

    // Go backwards from destination to start
    while (current != -1) {
        path.push_back(current);
        current = parent.at(current); // Get parent of current node
    }
    reverse(path.begin(), path.end()); // Reverse for correct direction (start to destination)

    // Optional: Check if path REALLY starts from the given source!
    if (path.front() != start) path.clear(); // No path found

    return path;
}



int main() {
    int V=5;
    vector<vector<int>> adj(V);
    //example shortest path undirect path
    adj[0].push_back(1); adj[1].push_back(0);
adj[1].push_back(2); adj[2].push_back(1);
adj[2].push_back(0); adj[0].push_back(2);
adj[3].push_back(4); adj[4].push_back(3);
    adj[0].push_back(3); adj[3].push_back(0);


    vector<bool> visited(V, false);
    unordered_map<int, int> parent; /// child->parent like 0->-1, 1->0, 2->1, 3->0, 4->3
    int source = 0;
    int destination = 4;

    
    shortestPathUndirected(source, adj, visited, parent);
    

    // Print shortest paths
    
    vector<int> path = getShortestPath(source, destination, parent);
    if (!path.empty()) {
        cout << "Shortest path from " << source << " to " << destination << ": ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found from " << source << " to " << destination << endl;
    }
}



