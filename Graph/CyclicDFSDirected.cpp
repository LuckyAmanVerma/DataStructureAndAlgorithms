#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
#include<vector>
using namespace std;


bool checkCycleDFS(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,unordered_map<int,list<int>> &adj){
    visited[node]=true;
    dfsvisited[node]=true;
    
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycledetected =checkCycleDFS(neighbour,visited,dfsvisited,adj);
            if(cycledetected)
                return true;
        }
        else if(dfsvisited[neighbour]){
            return true;
        }
    }
    dfsvisited[node]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // create adjacency list
   unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
         int v=edges[i].second;
        
        adj[u].push_back(v);
    }
    //call dfs for all components
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool cyclefound =checkCycleDFS(i,visited,dfsvisited,adj);
            if(cyclefound)
                return true;
        }
    }
    return false;
}

int main()
{
    // Example test case
    int V = 5, E = 5;
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0}, // Cycle here
        {3, 4}
    };

    if (detectCycleInDirectedGraph(V, edges))
        cout << "Graph is cyclic\n";
    else
        cout << "Graph is acyclic\n";

    return 0;
}
