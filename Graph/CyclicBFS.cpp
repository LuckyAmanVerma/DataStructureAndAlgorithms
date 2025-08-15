/*
Cyclic BFS Implementation
Return true if cycle else false

Parent map 
0 → 1
1 → 2
2 → 0
3 → 4
4 → 3
Graph
   2
  / \
 0 - 1       3 - 4
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
bool bfsWithCycleCheck(int start,
                       const vector<vector<int>> &adj,
                       vector<bool> &visited,
                       )
{
    queue<pair<int,int>> q;  //node,parent
    q.push({start,-1});
    visited[start] = true;

    while(!q.empty()) {
        auto [node,parent]=q.front();
        q.pop();
        for(auto neighbour:adj[node]) {
            if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push({neighbour,node});
            }
            else if(neighbour!=parent) {
                // Found a visited node that's not parent; cycle detected
                return true;
            }
        }
    }
    return false;
}


int main() {
    int V=5;
    vector<vector<int>> adj(V);
    //example cyclic return true
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[3].push_back(4);
    adj[4].push_back(3);

    vector<bool> visited(V, false);
    unordered_map<int, int> parent;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (bfsWithCycleCheck(i, adj, visited, parent)) {
                cout << "Cycle detected" << endl;
                return 0;
            }
        }
    }

    cout << "No cycle detected" << endl;
    return 0;
}



