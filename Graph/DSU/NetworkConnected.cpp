/*
Minimum number of operations to make network connected.
Using DSU , we can find the number of connected components in the graph.
Input: n=4
connections: [[0,1],[0,2],[1,2]]
Answer - 1

Make sure connection.size() == n-1 , if it is less than that return -1;
Before:- 
   0
  / \
 1---2      3

 After:- 
    0
  / \
 1   2---3

*/

#include<iostream>
#include<vector>
using namespace std;

int findParent(int x , vector<int> &parent) {
    if(x==parent[x]) {
        return x;
    }
    return parent[x]=findParent(parent[x],parent);
}

void Union(int x,int y , vector<int> &parent,vector<int> & rank) {
    int x_parent = findParent(x,parent);
    int y_parent = findParent(y,parent);
    if(rank[x_parent] ==rank[y_parent]) {
        parent[x_parent]=y_parent;
        rank[y_parent]++;
    }
    else if(rank[x_parent] >rank[y_parent]) {
        parent[y_parent] =x_parent;
    }
    else {
        parent[x_parent] =y_parent;
    }
}

int min_connections(int n,vector<vector<int>> &connections,vector<int> &parent,vector<int> & rank) {
    if(connections.size()<n-1) return -1;
    int ans =n;

    for(auto connection:connections) {
        if(findParent(connection[0],parent)!= findParent(connection[1],parent)) {
            Union(connection[0],connection[1],parent,rank);
            ans--;
        }
    }
    return ans-1;
}


int main() {
    int n=4;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int ans = min_connections(n, connections,parent,rank);
    if (ans == -1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}