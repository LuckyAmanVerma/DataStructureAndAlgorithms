/*
Cheapest Flights Within K Stops (LeetCode 787)
Problem: Find the cheapest price from src to dst with at most k stops.
Input:

n = 4, flights = [[0,1,100],[1,2,100],[2,3,100],[0,2,500]]
src = 0, dst = 3, k = 1

Output:

600
heapest Flights Within K Stops (LeetCode 787)

Problem: Find the cheapest price from src to dst with at most k stops.

Input:

n = 4, flights = [[0,1,100],[1,2,100],[2,3,100],[0,2,500]]
src = 0, dst = 3, k = 1


Output:

600
*/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main(){
    vector<vector<int>> edges= {{0,1,100},{1,2,100},{2,3,100},{0,2,500}}; //src,dest,weight
    int n=4;
    vector<vector<pair<int,int>>> adj(n);
    for(auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v,w});
    }
    int src = 0;
    int dst = 3;
    int k = 1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // weight,node
    vector<int> distance(n,INT_MAX);
   
}