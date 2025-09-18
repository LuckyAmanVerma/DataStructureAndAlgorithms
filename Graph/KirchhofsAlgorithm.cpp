/*
This algorithm is used to find the number of spanning trees in a connected undirected graph.
Graph will be incomplete or complete applicable to both cases.
Input: { {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3} } V=4
Output: Number of spanning trees is: 8

Step1: Adjacency Matrix 
Step2: laplacian Matrix - Diagonal Element - Indegree , Non Diagonal -1 if 1 , Laplacian matrix = Degree matrix - Adjacency matrix.
    Indegree: - Kisi node i ke liye adjacency matrix me uske row me jitne 1's hain, wo uska degree hota hai.
Step3:Cofactor
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> getMinor(vector<vector<int>> &mat,int row,int col) {
    int n=mat.size();
    vector<vector<int>> minor;

    for(int i=0;i<n;i++) {
        vector<int> temp;
        if(i==row) continue;
        for(int j=0;j<n;j++) {
            if(j==col) continue;
            temp.push_back(mat[i][j]);
        }
        minor.push_back(temp);
    }
    return minor;
}

int main() {
    int V = 4; // Number of vertices
    vector<pair<int,int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {2, 3}
    };

    // step 1: Create adjacency matrix
    vector<vector<int>> adj(V,vector<int>(V,0) );
    for(auto [u,v]:edges) {
        adj[u][v]=1;
        adj[v][u]=1;
    }

    //step 2: laplacian matrix 
    vector<int> degree(V,0);
    //2.1 - Diagonal k degree of node 
    for(int i=0;i<V;i++) {
        int deg=0;
        for(int j=0;j<V;j++) {
            deg+=adj[i][j];
        }
        degree[i]=deg;
    }

    //2.2 - Assign degree to diagonal elements

    for(int i=0;i<V;i++) {
        adj[i][i]=degree[i];
    }

    //2.3 Non Diagonal elements to -1
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            if(i!=j && adj[i][j]==1) {
                adj[i][j]=-1;
            }
        }
    }
    // Step 3:- Find the cofactor

    vector<vector<int>> minor =getMinor(adj,0,0);


    
}
