/*
Clone Graph
Input: n = 4, adjList[][] = [[1, 2], [0, 2], [0, 1, 3], [2]]
Output: Cloned graph's adjacency list

In Clone Map, we add the neighbors , only while visiting the neighbor of next node and if that neighbor is not already visited, 
we create a clone for it.
*/

#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node(int _val) : val(_val) {}
};

Node* cloneGraph(Node* node) {
    if(!node) return nullptr;

    map<Node*,Node*> m;
    queue<Node*> q;
    Node* clone = new Node(node->val);
    m[node]=clone;
    q.push(node);

    while(!q.empty()) {
        Node* front =q.front();
        q.pop();

        for(Node* neighbor:front->neighbors) {
            if(m.find(neighbor)==m.end()) {
                Node* neighborClone = new Node(neighbor->val);
                m[neighbor]=neighborClone;
                q.push(neighbor);
            }
            m[front]->neighbors.push_back(m[neighbor]);
        }
    }
    return m[node];
}

Node* buildGraph() {
    Node* node1 = new Node(0);
    Node* node2 = new Node(1);
    Node* node3 = new Node(2);
    Node* node4 = new Node(3);

    node1->neighbors = {node2, node3};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node1, node2, node4};
    node4->neighbors = {node3};

    return node1;
}

void printGraph(Node* node) {
    if (!node) return;

    map<Node*, bool> visited;
    queue<Node*> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << "Node " << curr->val << ": ";
        for (Node* neighbor : curr->neighbors) {
            cout << neighbor->val << " ";
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        cout << endl;
    }
}

int main() {
    Node* original = buildGraph();
    Node* cloned = cloneGraph(original);
    //print both side by side
    printGraph(original);
    cout<<"-------------------------------------------------"<<endl;
    cout << "Cloned Graph:" << endl;
    cout<<"-------------------------------------------------"<<endl;
    printGraph(cloned);
    return 0;
}
   