/*
Determine if a path exists from the root of the tree to a leaf node that does not contain any zeroes.
        4
       / \
      0   1
     / \  / \
       7 2   0

*/

#include <iostream>
#include "Node.h"
using namespace std;

pair<bool, int> pathWithoutZero(Node *root){
    if (!root)
        return {false, 0};
    if (root->val == 0)
        return {false, 0};
    if (!root->left && !root->right){
        cout<<root->val<<endl;
        return {true, root->val};
    }
        

    pair<bool, int> left = pathWithoutZero(root->left);
    pair<bool, int> right = pathWithoutZero(root->right);

    if(left.first) {
        cout<<root->val<<endl;
        return {true,root->val+left.second};
    }
    if(right.first) {
        cout<<root->val<<endl;
        return {true,root->val+right.second};
    }

    return {false,root->val};
}   
    bool pathWithoutZeroExists(Node* root) {
    if (!root || root->val == 0) return false;

    if (!root->left && !root->right) return true;

    return pathWithoutZeroExists(root->left) || pathWithoutZeroExists(root->right);
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(0);
    root->right = new Node(1);
    root->left->right = new Node(7);
    root->right->left = new Node(2);
    root->right->right = new Node(0);

    pair<bool,int> result=pathWithoutZero(root);
    if (result.first) {
        cout << "Path exists : " << result.first << endl;
    } else {
        cout << "No path exists without zero." << endl;
    }

    return 0;
}

