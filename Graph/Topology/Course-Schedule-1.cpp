/*
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]. Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

Examples:

Input: N = 4, P = 3, prerequisites = {{1,0},{2,1},{3,2}}
Output: Yes
Explanation: To do task 1 you should have completed task 0, and to do task 2 you should have finished task 1, and to do task 3 you should have finished task 2. So it is possible.



Input: N = 2, P = 2, prerequisites = {{1,0},{0,1}}
Output: No
Explanation: To do task 1 you should have completed task 0, and to do task 0 you should have finished task 1. So it is impossible.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


bool bfs(int N, const vector<vector<int>>& edges) {
    vector<vector<int>> adj(N);           // adjacency list
    vector<int> indegree(N, 0);           // stores indegree per node

    // Build adjacency list and indegree array
    for (auto& edge : edges) {
        int u = edge[1], v = edge[0];     // edge: u -> v, to do v, u must be done
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    // Push all nodes with indegree 0 (no prerequisites)
    for (int i = 0; i < N; i++)
        if (indegree[i] == 0)
            q.push(i);

    int count = 0;                        // tracks number of processed nodes

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;                          // we can process this node

        // For all neighbors, reduce indegree since their prerequisite done
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)  // if indegree becomes zero, can process
                q.push(neighbor);
        }
    }

    // If count == N, ordering is possible (no cycle).
    return count == N;
}

// Example usage
int main() {
    int N = 4;
    vector<vector<int>> edges = {{1,0},{2,1},{3,2}};
    cout << (bfs(N, edges) ? "Yes" : "No") << endl; // Output: Yes

    N = 2;
    edges = {{1,0},{0,1}};
    cout << (bfs(N, edges) ? "Yes" : "No") << endl; // Output: No
    return 0;
}

