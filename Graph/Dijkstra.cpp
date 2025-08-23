/*
Using Min Heap , we can optimize Dijkstra's algorithm to achieve better performance.

   Graph representation:

        (0)
       /   \
    4 /     \ 8
     /       \
   (1)       (2)
     \         \
      \ 6       \ 2
       \    10   \
       (4)--------(3)
           

Edges:
0 -> 1 (4)
0 -> 2 (8)
1 -> 4 (6)
2 -> 3 (2)
3 -> 4 (10)
*/


#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Function to construct adjacency 
vector<vector<vector<int>>> constructAdj(vector<vector<int>> 
                             &edges, int V) {
                                 
    // adj[u] = list of {v, wt}
    vector<vector<vector<int>>> adj(V); 

    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); 
    }
    
    return adj;
}

// Returns shortest distances from src to all other vertices
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src){
    
    // Create adjacency list
    vector<vector<vector<int>>> adj = constructAdj(edges, V);

    
    priority_queue<vector<int>, vector<vector<int>>, 
                   greater<vector<int>>> pq;
    vector<int> distance(V,INT_MAX);
    //initialize
    distance[src]=0;
    pq.push({0,src});

    while(!pq.empty()) {
        int u = pq.top()[1];
        pq.pop();
        //neighbour
        for(auto neighbour:adj[u]){
            int v=neighbour[0];
            int weight = neighbour[1];
            if(distance[v]>distance[u]+weight) {
                distance[v]=distance[u]+weight;
                pq.push({distance[v],v});
            }
        }
    }
    return distance;

}

int main(){
    int V = 5;
    int src = 0;

    vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, 
                                 {2, 3, 2}, {3, 4, 10}};

    vector<int> result = dijkstra(V, edges, src);

    for (int dist : result)
        cout << dist << " ";
 
    return 0;
}
