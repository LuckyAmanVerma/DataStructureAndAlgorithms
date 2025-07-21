/*
The diameter of a binary tree is the longest path between any two nodes in the tree. It may or may not pass through the root,
 and it's measured by number of edges on that path. 
 We check , root-> right , root-> left and 
 for combination of left and right , we use height of binary tree , 
*/


#include<iostream>
#include<utility>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int val;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

int height(Node* root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameterOfBinaryTree(Node* root){
    if(!root){
        return 0;
    }
    int op1=diameterOfBinaryTree(root->left);
    int op2=diameterOfBinaryTree(root->right);
    int op3= height(root->left)+height(root->right);
    return max(op1,op2,op3);
}

pair<int,int> diameterOfBinaryTreeOptimize(Node* root){  //o(n)
    if(!root) return {0, 0}; // {diameter, height}

    pair<int,int> leftTree = diameterOfBinaryTreeOptimize(root->left);
    pair<int,int> rightTree = diameterOfBinaryTreeOptimize(root->right);

    int leftDiameter = leftTree.first;
    int rightDiameter = rightTree.first;
    int throughRoot = leftTree.second + rightTree.second;

    int currentDiameter = max(leftDiameter, rightDiameter, throughRoot);
    int currentHeight = max(leftTree.second, rightTree.second) + 1;

    return {currentDiameter, currentHeight};
}