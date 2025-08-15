/*
Problem: Given a directed acyclic graph (DAG), perform a topological sort using depth-first search (DFS).
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int,bool> &visited,stack<int> &s,vector<vector<int>> &adj) {
    visited[node]=true;
 
    for(auto neighbour:adj[node]) {
        if(!visited[neighbour]) {
            dfs(neighbour,visited,s,adj);
        }
    }
    s.push(node);
}

int main() {
    int V=5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {3, 4};
    adj[3] = {};
    adj[4] = {};

    unordered_map<int,bool> visited(V);
    stack<int> s;
    for(int i=0;i<V;i++) {
        if(!visited[i]) {
            dfs(i,visited,s,adj);
        }
    }
    while(!s.empty()) {
        int top =s.top();
        cout<<top<<" "; 
        s.pop();
    }

}
