/*
Find shortest path in a directed weighted graph using Dijkstra's algorithm
Input : Edges []
Output : Shortest path from source to all other vertices
Time Complexity : O((V + E) log V)
*/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main() {
    vector<vector<int>> edges= {{0,1,4},{0,2,1},{2,1,2},{1,3,1},{2,3,5}}; //src,dest,weight
    int n=4;
    vector<vector<pair<int,int>>> adj(n);
    for(auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v,w});
    }
    int src = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // weight,node
    vector<int> distance(n,INT_MAX);
    pq.push({0,src});
    distance[src]=0;
    
    while(!pq.empty()) {
        int u=pq.top().second;
        pq.pop();
        for(auto neighbor:adj[u]) {
           auto [v,w] =neighbor;
            if(distance[v]>distance[u]+w) {
                distance[v]=distance[u]+w;
                pq.push({distance[v],v});
            }
        }
    }
    cout<<"Shortest path from "<<src<<" to all other vertices:"<<endl;
    for(int i=0;i<n;i++) {
        if(distance[i]==INT_MAX) {
            cout<<"Vertex "<<i<<" is not reachable from "<<src<<endl;
        } else {
            cout<<"Vertex "<<i<<" : "<<distance[i]<<endl;
        }
    }
    return 0;
}