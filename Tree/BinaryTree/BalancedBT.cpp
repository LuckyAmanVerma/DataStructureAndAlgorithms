/*
A Binary Tree is balanced if the height of the two subtrees of any node never differs by more than one.
        1
       / \
      2   3
     / \   \
    4   5   6

*/

#include <iostream>
#include <algorithm>
using namespace std;

#include "Node.h"
int height(Node *root) {
    if (!root) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(Node *root) {
    if (!root) {
        return true;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    
    return isBalanced(root->left) && isBalanced(root->right);
}

pair<bool, int> checkBalancedOptimal(Node* root) {
    if (!root) return {true, 0};

    auto left = checkBalancedOptimal(root->left);
    auto right = checkBalancedOptimal(root->right);

    // cout << "At node " << root->val << ": left height = " << left.second << ", right height = " << right.second << endl<<left.first<<" :"<<right.first;
    // cout<<endl;

    bool balanced = left.first && right.first && 
                    abs(left.second - right.second) <= 1;

    int height = max(left.second, right.second) + 1;

    return {balanced, height};
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    auto result = checkBalancedOptimal(root);
    if (result.first) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
    return 0;
}
