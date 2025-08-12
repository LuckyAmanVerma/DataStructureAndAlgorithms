/*
Adjacency list representation of a graph
Input: Number of vertices (V) and a list of edges (u, v)
Output: Adjacency list (V x list of neighbors)
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>

vector<vector<int>> createAdjacencyList(int V, vector<pair<int, int>>& edges) {
    // Initialize the adjacency list
    vector<vector<int>> adjList(V);

    // Fill the adjacency list based on the edges
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    return adjList;
}

void printAdjacencyList(const vector<vector<int>>& adjList) {
    for (int i = 0; i < adjList.size(); ++i) {
        cout << "Vertex " << i << ":";
        for (int neighbor : adjList[i]) {
            cout << " " << neighbor;
        }
        cout << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 4},
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {3, 4}
    };

    vector<vector<int>> adjList = createAdjacencyList(V, edges);
    printAdjacencyList(adjList);

    return 0;
}
