/*
Using Topology DFS , we can find the shortest path in a directed weighted graph.
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

class Graph {
    public:
    unordered_map<int,list<pair<int,int>>> adj;
    void addEdge(int u , int v , int weight) {
        pair<int,int> p=make_pair(v,weight); // node,weight
        adj[u].push_back(p);
    }
    void printEdge() {
        for (auto i : adj) {
            int u = i.first;
            for (auto j : i.second) {
                int v = j.first;
                int weight = j.second;
                cout << "Edge from " << u << " to " << v << " with weight " << weight << endl;
            }
        }
    }

    void dfs(vector<bool> &visited,int node,stack<int> &s) {
        visited[node]=true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour.first]){
                dfs(visited,neighbour.first,s);
            }
        }
        s.push(node); // backtrack
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 1);
    g.printEdge();
    int n = 4; // no of nodes
    vector<bool> visited(n,false);
    stack<int> s;
    for(int i=0;i<n;i++) {
        if(!visited[i]){
            g.dfs(visited,i,s);
        }
    }
    int src=0; int destination =3;
    vector<int> direction(n,INT_MAX);
    direction[src]=0;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(direction[top]!=INT_MAX){
            for(auto neighbour:g.adj[top]){
                if(direction[top]+neighbour.second<direction[neighbour.first]){
                    direction[neighbour.first]=direction[top]+neighbour.second;
                }
            }
        }
    }
    for(int i=0;i<direction.size();i++) {
        if(direction[i]==INT_MAX) {
            cout<<"-1 ";
        } else {
            cout<<direction[i]<<" ";
        }
    }
    cout <<endl;
    //distance from source to destination
    if(direction[destination]==INT_MAX) {
        cout<<"-1 ";
    } else {
        cout<<direction[destination]<<" ";
    }

}