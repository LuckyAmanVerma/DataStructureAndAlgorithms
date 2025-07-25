/*
// Construct a sample tree:
         3
      / \
     2   5
    / \
   1   4
    Time Complexity: O(n)
*/
#include<iostream>
 
using namespace std;


#include "Node.h"
using TreeNode = Node;

bool validate(Node* node, long min, long max) {
    if (!node) return true;

    if (node->val <= min || node->val >= max)
        return false;

    return validate(node->left, min, node->val) &&
           validate(node->right, node->val, max);
}

bool validateBST(TreeNode* root) {
    return validate(root, LONG_MIN, LONG_MAX);
}