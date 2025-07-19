/*
Using In Order Traversal Technique
to find the kth smallest element in a Binary Search Tree (BST). 
       3
      / \
     2   5
    / \
   1   4
*/

#include<iostream>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int val;
    Node(int val):val(val),left(nullptr),right(nullptr) {}
};

int solve(Node* root,int& i,int target){
    if(!root){
        return -1;
    }
    int left = solve(root->left,i,target);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==target){
        return root->val;
    }
    // left doesn't contain the data then we parse the right tree
    return solve(root->right,i,target);
}

int kthSmallestElement(Node* root,int target) {
    int i=0;
    int ans = solve(root,i,target);
    return ans;
}

int main(){
    Node* root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    int target=2;
    cout<<"2nd smallest element is "<<kthSmallestElement(root,target);
}