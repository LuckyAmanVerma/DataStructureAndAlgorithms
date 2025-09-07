/*

*/

#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<bool> &visited,vector<vector<int>> &adj,vector<int> &result,int node) {
    visited[node]=true;
    result.push_back(node);

    for(int neighbor:adj[node]) {
        if(!visited[neighbor]) {
            dfs(visited,adj,result,neighbor);
        }
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    vector<bool> visited(V,false);
    vector<int> result;

    for(int i=0;i<V;i++) {
        if(!visited[i]) {
            dfs(visited,adj,result,i);
        }
    }
    cout<<"DFS TRAVERSAL"<<endl;
    for(int data:result){
        cout<<data<<endl;
    }
}