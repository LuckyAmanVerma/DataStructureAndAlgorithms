/*
Problem Statement:
Given a connected, undirected graph with weights on the edges, find the minimum spanning tree (MST) using Kruskal's algorithm.
Input: { {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4} }
Output: Weight of Minimum Spanning Tree is: 19
Time Complexity: O(E log E) where E is the number of edges.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findParent(int node ,vector<int>& parent) {
    if(node == parent[node]) return node;
    return parent[node]=findParent(parent[node],parent);
}

void Union(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[v] < rank[u]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

 bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    };

int main() {
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int V = 4; // Number of vertices
   
    sort(edges.begin(),edges.end(),cmp);
    int weight =0;
    vector<int> parent(V);
    vector<int> rank(V,0);
    for(int i=0;i<V;i++) parent[i] = i;
    for(auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if(findParent(u,parent) != findParent(v,parent)) {
            weight += wt;
            Union(u,v,parent,rank);
        }
    }
    cout<<"Weight of Minimum Spanning Tree is: "<<weight<<endl;
    return 0;

}