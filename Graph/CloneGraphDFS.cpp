/*
Clone Graph using dfs
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node(int _val):val(_val) {
        cout<<"Node->"<_val;
    }
}


Node* dfs(unordered_map<Node*,Node*> &cloned,Node* node){
    if(cloned.count(node)) return cloned[node];
    Node* clone = new Node(node->val);
    cloned[node]=clone;
    for(auto neighbor: node->neighbors){
        clone->neighbors.push_back(dfs(cloned,neighbor));
    }
    return clone;
}

Node* cloneGraph(Node* node) {
    if(!node) nullptr;
    unordered_map<Node*,Node*> cloned;
    Node* clone = new Node(node->val);
    cloned[node]=clone;
    return dfs(cloned,node);
}
