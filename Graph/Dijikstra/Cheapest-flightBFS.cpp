/*
Cheapest Flights Within K Stops (LeetCode 787)
Problem: Find the cheapest price from src to dst with at most k stops.
Input:

n = 4, flights = [[0,1,100],[1,2,100],[2,3,100],[0,2,500]]
src = 0, dst = 3, k = 1

Output:

600
heapest Flights Within K Stops (LeetCode 787)

Problem: Find the cheapest price from src to dst with at most k stops.

Input:

n = 4, flights = [[0,1,100],[1,2,100],[2,3,100],[0,2,500]]
src = 0, dst = 3, k = 1

     (0)
   /     \
100      500
 /          \        
(1)---100-->(2)---100-->(3)


// Adjacency List (node -> {neighbor, weight})
0 -> (1,100), (2,500)
1 -> (2,100)
2 -> (3,100)
3 -> {}

Time Complexity:- O(V + E)
Output:

600
*/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main() {
    vector<vector<int>> edges = {
        {0,1,100},{1,2,100},{2,3,100},{0,2,500}
    }; // src,dest,weight

    int n = 4;
    vector<vector<pair<int,int>>> adj(n);
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v,w});
    }

    int src = 0;
    int dst = 3;
    int k = 1;

    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    // queue stores {node, cost, stops}
    queue<tuple<int,int,int>> q;
    q.push({src, 0, 0});

    while (!q.empty()) {
        auto [u, cost, stops] = q.front();
        q.pop();

        if (stops > k) continue;

        for (auto [v, w] : adj[u]) {
            int newCost = cost + w;
            if (newCost < distance[v]) {
                distance[v] = newCost;
                q.push({v, newCost, stops + 1});
            }
        }
    }

    cout << "Cheapest price from " << src << " to " << dst 
         << " with at most " << k << " stops is : ";
    if (distance[dst] == INT_MAX) 
        cout << "Not Possible";
    else 
        cout << distance[dst];
    cout << endl;

    return 0;
}