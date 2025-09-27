/*
Print all elements in sorted order from row and column wise sorted matrix,
Input:
    10 20 30 40
    15 25 35 45
    27 29 37 48
    32 33 39 50
Output:
    10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50
Approach: Use Min Heap and graph theory

Time Complexity: O(r*c log(r*c)) where r is number of rows and c is number of columns
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int getIndex(int i,int j,int c) {  // convert 2D matrix to 1D flatten array
    return i*c+j;
}

void matrixToGraph(vector<vector<int>> &matrix,vector<vector<int>> &adj) {
    int r =matrix.size();
    int c =matrix[0].size();
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            int node = getIndex(i,j,c);
           // right node
           if(j+1<c) {
            adj[node].push_back(getIndex(i,j+1,c));
           }
           // bottom node
           if(i+1<r) {
            adj[node].push_back(getIndex(i+1,j,c));
           }
            
        }
    }
}

vector<int> sortedOrder(vector<vector<int>> &matrix) {
     int r =matrix.size();
    int c =matrix[0].size();
    vector<int> sortedOrder;
    vector<vector<int>> adj(r*c);  // 1 D adjacency list
    matrixToGraph(matrix,adj);
    vector<bool> visited(r*c,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;

    minHeap.push({matrix[0][0],0}); // {value,index}
    visited[0]=true;

    while(!minHeap.empty()) {
        auto [value,index] =minHeap.top();
        minHeap.pop();
        sortedOrder.push_back(value);

        for(auto neighbor:adj[index]) {
            if(!visited[neighbor]) {
                visited[neighbor]=true;
                minHeap.push({matrix[neighbor/c][neighbor%c],neighbor});
            }
        }
    }

    return sortedOrder;
}

int main () {
    vector<vector<int>> matrix={
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };

    vector<int> result = sortedOrder(matrix);
    for(auto val:result) {
        cout<<val<<" ";
    }
    return 0;
}
