/*
Find the sum of minimum spanning tree using Prim's algorithm.
Output: Sum of Minimum Spanning Tree is: 19
Time Complexity: O(E log V) where E is the number of edges and V is the number of vertices.
*/

#include <iostream>
#include <vector>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int,int> P; //weight,node

int primsAlgorithm(int V,vector<vector<pair<int,int>>>  &adj) {
    int sum =0;
    priority_queue<P,vector<P>,greater<P>> pq;
    vector<bool> visited(V,false);
    pq.push({0,0});

    while(!pq.empty()) {
        auto top=pq.top();
        pq.pop();
        int node = top.second;
        int weight = top.first;
        if(visited[node]) continue;
        visited[node]=true;
        sum+=weight;

        for(auto [v,wt]:adj[node]) {
            if(!visited[v]) {
                pq.push({wt,v});
            }
        }

    }
    return sum;

}

int main() {
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int V = 4; // Number of vertices
    vector<vector<pair<int,int>>> adj(V);
    for(auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    int sum = primsAlgorithm(V,adj);
   
    cout<<"Sum of Minimum Spanning Tree is: "<<sum<<endl;
    return 0;
}