
/*
Create indegree
push indegree 0 ites to queue , 
Then start performing bfs , and update the indegree of neighbours
Definition of Topology:- Topological sorting is a linear ordering of vertices in a directed acyclic graph (DAG) 
such that for every directed edge (u, v), vertex u comes before vertex v in the ordering.

Course Schedule 2 Problem:
Given a list of courses and their prerequisites, determine if it's possible to finish all courses.
Input:
n=6
prereqs=[[2,0],[2,1],[3,2],[4,2],[5,3]]
# one valid output: [0,1,2,4,3,5]
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int V=6;
    vector<pair<int, int>> edges = {
        {2,0},
        {2,1},
        {3,2},
        {4,2},
        {5,3}
    };
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    vector<int> ans;
    

    for(int i=0;i<indegree.size();i++) {
        if(indegree[i]==0) {
            q.push(i);
        }
    }
    // now bfs logic

    while(!q.empty()) {
        int front =q.front();
        ans.push_back(front);
        q.pop();

        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0) {
                q.push(neighbour);
            }
        }
    }
    //print topology

    for(auto i:ans) {
        cout<<i<<" ";
    }
    cout<<endl;

    if (ans.size() == V) {
        cout << "Graph is acyclic (DAG)" << endl;
    } else {
        cout << "Graph contains a cycle" << endl;
    }


    return 0;
}
