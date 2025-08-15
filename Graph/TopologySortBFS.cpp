
/*
Create indegree
push indegree 0 ites to queue , 
Then start performing bfs , and update the indegree of neighbours
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int V=5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {3, 4};
    adj[3] = {};
    adj[4] = {};

    vector<int> indegree(V);
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<adj.size();i++) {
        for(int j=0;j<adj[i].size();j++) {
            indegree[adj[i][j]]++;
        }
    }

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
