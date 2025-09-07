/*
https://www.youtube.com/watch?v=Nq_Ke4SS6GY
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> minimumTime(int N, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1, 0);
    vector<int> time(N + 1, 0);

    // Build graph and indegree array
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    // Push all nodes with indegree 0 into the queue and set time = 1
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            time[i] = 1;
        }
    }

    // BFS traversal
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr]) {
            indegree[neighbor]--;
            // Update minimum time for neighbor job
            if (time[neighbor] < time[curr] + 1) {
                time[neighbor] = time[curr] + 1;
            }
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Return time array ignoring index 0 as nodes start from 1
    return vector<int>(time.begin() + 1, time.end());
}

 //jobCompletedMinTime using bfs

int main() {
    int N = 10;
    vector<pair<int,int>> edges = {{1,3},{1,4},{1,5},{2,3},{2,8},{2,9},{3,6},{4,6},{4,8},{5,8},{6,7},{7,8},{8,10}};

    vector<int> result = minimumTime(N, edges);

    cout << "Minimum time for each job to complete:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Job " << (i + 1) << ": " << result[i] << "\n";
    }

    return 0;
}
