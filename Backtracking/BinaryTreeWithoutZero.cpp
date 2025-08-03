/*
Determine if any path exists from root to leaf node without zeroes in a binary tree.
This code checks if there is a path from the root to any leaf node in a binary tree
Input:[1, 2, 3, 4, 5, 6, 7], Output: true
Input: [1, 0, 3, 4, 5, 6, 7], Output: false
        1
      /   \
     0     3
    / \   / \
   4   5 6   7

*/
#include"Node.h"
#include <iostream>
using namespace std;

bool withoutZero(Node* root) {
    if(!root ||root->val==0) {
        return false;
    }

    if(!root->left && !root->right) {
        return true;
    }

    return withoutZero(root->left) || withoutZero(root->right);

}

int main() {
    Node* root = new Node(1);
    root->left = new Node(0);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    if(withoutZero(root)) {
        cout << "There is a path from root to leaf node without zeroes." << endl;
    } else {
        cout << "No such path exists." << endl;
    }

    return 0;
}
