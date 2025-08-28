/*
Using DFS to find unreachable nodes
Main Formula:- size*(remainingNodes-size);
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void dfs(int node,vector<bool> &visited,unordered_map<int, vector<int>> &adj,int &Size) {
    visited[node]=true;
    Size++;
    for(auto neighbour:adj[node]) {
        if(!visited[neighbour]){
            dfs(neighbour,visited,adj,Size);
        }
       
    }
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
    int n = 5;
    unordered_map<int, vector<int>> adj;
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n, false);
    int remainingNodes =n;
    int result =0;
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            int Size =0;
            dfs(i,visited,adj,Size);
            result+=Size*(remainingNodes-Size);
            remainingNodes-=Size;
        }
    }
    cout<<"Total unreachable nodes are :-" <<result;
   
    return 0;
}