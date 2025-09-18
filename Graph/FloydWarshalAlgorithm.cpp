/*
To find shortest distance from each vertex to every other vertex in a given edge weighted directed Graph.
Time Complexity: O(V^3)
Space Complexity: O(V^2)
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshalAlgorithm(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist = graph;

    for (int via = 0; via < V; via++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }

    return dist;
}

int main() {
vector<vector<int>> graph = {
    {0, 5, INT_MAX, 10},
    {INT_MAX, 0, 3, INT_MAX},
    {INT_MAX, INT_MAX, 0,   1},
    {INT_MAX, INT_MAX, INT_MAX, 0}
};

vector<vector<int>> dist = floydWarshalAlgorithm(graph);

for (const auto& row : dist) {
    for (int d : row) {
        if (d == INT_MAX) {
            cout << "INF ";
        } else {
            cout << d << " ";
        }
    }
    cout << endl;
}

return dist;
}
