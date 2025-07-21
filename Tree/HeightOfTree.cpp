/*
Height of tree is longest path from root to leaf node
*/

#include <iostream>
using namespace std;


#include "Node.h"

int height(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int main(){
    Node* root = new Node(3);          // Root node
    root->left = new Node(2);          // Left child of 3
    root->right = new Node(5);         // Right child of 3

    root->left->left = new Node(1);    // Left child of 2
    root->left->right = new Node(4);   // Right child of 2
    cout<<"Height of Tree is "<<height(root);

}