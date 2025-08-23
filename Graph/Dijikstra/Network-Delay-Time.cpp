/*
Problem: Given a list of travel times times[u, v, w] (directed edges, weight = w), and a starting node k, 
find the time it takes for all nodes to receive the signal. If not all can be reached, return -1.
Input:
times = [[2,1,1],[2,3,1],[3,4,1]]
n = 4, k = 2
Output: 2
Explanation:
Node 1 takes 1, Node 3 takes 1, Node 4 takes 2. Maximum = 2.
Time Complexity: O((E + V) log V), where E is the number of edges and V is the number of vertices.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include<algorithm>
using namespace std;

void createAdjacencyList(vector<vector<pair<int,int>>> &adj, vector<vector<int>> &edges, int n) {
    for(auto &edge : edges) {
        int u = edge[0]-1;
        int v = edge[1]-1;
        int w = edge[2];
        adj[u].push_back({v,w});
    }
}

int main() {
    vector<vector<int>> edges= {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, src = 2;
    vector<vector<pair<int,int>>> adj(n);
    createAdjacencyList(adj,edges,n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distance(n,INT_MAX);
    //initialzation
    distance[src-1]=0;
    pq.push({0,src-1});

    while(!pq.empty()) {
        int u=pq.top().second;
        pq.pop();
        for(auto neighbour:adj[u]) {
            auto [v,w] =neighbour;
            if(distance[v]>distance[u]+w) {
                distance[v]=distance[u]+w;
                pq.push({distance[v],v});
            }
        }
        
    }

    int maxTime = *max_element(distance.begin(), distance.end());
    cout << (maxTime == INT_MAX ? -1 : maxTime) << endl;

}