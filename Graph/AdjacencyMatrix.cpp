/*
Create the adjacency matrix for a graph
Input: Number of vertices (V) and a list of edges (u, v)
Output: Adjacency matrix (V x V)

Time Complexity: O(V^2)
Space Complexity: O(V^2)
*/

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> createAdjacencyMatrix(int V, vector<pair<int, int>>& edges) {
    // Initialize the adjacency matrix with 0s
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    // Fill the adjacency matrix based on the edges
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph
    }

    return adjMatrix;
}

void printAdjacencyMatrix(const vector<vector<int>>& adjMatrix) {
    for (const auto& row : adjMatrix) {
        for (int val : row) {
            cout << val << " ";
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

    vector<vector<int>> adjMatrix = createAdjacencyMatrix(V, edges);
    printAdjacencyMatrix(adjMatrix);

    return 0;
}
