/*
A Binary Tree is balanced if the height of the two subtrees of any node never differs by more than one.
*/

#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    Node *left;
    Node *right;
    int val;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};
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

pair<bool, int> checkBalanced(Node* root) {
    if (!root) return {true, 0};

    auto left = checkBalanced(root->left);
    auto right = checkBalanced(root->right);

    bool balanced = left.first && right.first && 
                    abs(left.second - right.second) <= 1;

    int height = max(left.second, right.second) + 1;

    return {balanced, height};
}
