/*
Array to Binary Tree

*/

#include<iostream>
#include"../Node.h"
#include<vector>
using namespace std;

Node* arrayToBST(vector<int>& nums, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    Node* root = new Node(nums[mid]);
    root->left = arrayToBST(nums, start, mid - 1);
    root->right = arrayToBST(nums, mid + 1, end);
    return root;
}

Node* sortedArrayToBST(vector<int>& nums) {
    return arrayToBST(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Node* root = sortedArrayToBST(nums);
    // You can add code here to print or verify the BST
    cout << "Binary Search Tree created from sorted array." << endl;
    //print the binary tree
    return 0;
}