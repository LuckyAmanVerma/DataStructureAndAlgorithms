/*
Definition: A Sum Tree is a binary tree where the value of each node is equal to the sum of the values of its left and right children. 
An empty tree is considered a Sum Tree.

Example:
Input: 10
       /  \
      4    6
     / \  / \
    1  3 5  7
Output: 28
Explanation: The sum of all left children is 1 + 3 = 4 and the sum of all right children is 5 + 7 = 12 which is not equal to 6. 
So, the tree is not a Sum Tree.
Time Complexity: O(n), where n is the number of nodes in the tree.
Space Complexity: O(h), where h is the height of the tree due to recursion stack.
*/

#include<iostream>
#include<utility>
using namespace std;

#include "Node.h"

pair<bool,int> isSumTree(Node* root) {
    if(!root){
        return {true,0};
    }
    if(!root->left &&!root->right){
        return {true,root->val};
    }
    pair<bool,int> left=isSumTree(root->left);
    pair<bool,int> right=isSumTree(root->right);
    bool op1 =left.first && right.first && (left.second +right.second)==root->val;
    int op2 =left.second+right.second;

    return {op1,op2};
}

int main(){
    Node* root =new Node(3);
    root->left =new Node(1);
    root->right =new Node(2);
    pair<bool,int> ans =isSumTree(root);
    cout<<"Is this tree is sum tree? "<<ans.first;
}