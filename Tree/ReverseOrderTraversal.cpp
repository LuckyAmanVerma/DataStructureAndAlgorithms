/*
        1
       / \
      2   3
     / \   \
    4   5   6
    Normal Order Traversal: 1 2 3 4 5 6
        Reverse Order Traversal: 4 5 6 2 3 1
        Root Left Right
*/
#include <iostream>
#include "Node.h"
#include <stack>
#include<queue>
using namespace std;




void reverseOrder(Node* root){
    if(!root){
        cout<<"Nothing to check"<<endl;
        return;
    }
    stack<Node*> s;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        s.push(curr);
        q.pop();
        if(curr->right){
            q.push(curr->right);
        }
        if(curr->left){
            q.push(curr->left);
        }
    }

    while(!s.empty()){
        cout<<s.top()->val<<" ";
        s.pop();
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Reverse Order Traversal: ";
    reverseOrder(root);
    cout << endl;

    return 0;
}