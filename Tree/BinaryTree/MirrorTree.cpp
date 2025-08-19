/*
Mirror Binary Tree
     1
   /   \
  2     3
 / \   / \
4   5 6   7

Output
   1
   3 2
   7 6 5 4
*/
#include<iostream>
#include<queue>
#include"../Node.h"
using namespace std;

void mirrorTree(Node* root) {
    if (!root) return;

    // Swap the left and right children
    swap(root->left, root->right);

    // Recursively mirror the subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}
//bfs technique
void mirrorUsingQueue(Node* root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();
        for(int i = 0; i < n; i++) {
            Node* front = q.front();
            q.pop();
            cout << " " << front->val << " "; // swap front left and right , if need to mirror the data also 
            if(front->right) q.push(front->right);
            if(front->left) q.push(front->left);
        }
        cout << endl;
    }
}
void printTree(Node* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    mirrorUsingQueue(root);
    return 0;
    /*
    cout << "Original Tree:" << endl;
    printTree(root);

    mirrorTree(root);

    cout << "Mirrored Tree:" << endl;
    printTree(root);

    return 0;
    */
}