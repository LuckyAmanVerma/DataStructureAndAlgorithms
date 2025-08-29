/*
Time Complexity:- O(E log V)f
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

    // min-heap: {cost, node, stops}
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({0, src, 0});

    while (!pq.empty()) {
        auto [cost, node, stops] = pq.top();
        pq.pop();

        if (node == dst) {
            cout << "Cheapest price from " << src << " to " << dst 
                 << " with at most " << k << " stops is : " << cost << endl;
            return 0;
        }

        if (stops <= k) {
            for (auto [v, w] : adj[node]) {
                pq.push({cost + w, v, stops + 1});
            }
        }
    }

    cout << "Cheapest price from " << src << " to " << dst 
         << " with at most " << k << " stops is : Not Possible" << endl;

    return 0;
}
