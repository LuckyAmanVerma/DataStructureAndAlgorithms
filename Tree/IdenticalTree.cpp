#include<iostream>
using namespace std;

#include "Node.h"

bool identicalTree(Node* root1, Node* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    if (root1->val != root2->val) return false;

    return identicalTree(root1->left, root2->left) &&
           identicalTree(root1->right, root2->right);
}

int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if (identicalTree(root1, root2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    // Clean up memory
    delete root1->left;
    delete root1->right;
    delete root1;
    
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
