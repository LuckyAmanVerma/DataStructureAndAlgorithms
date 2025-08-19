/*
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Using DFS
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
        5
       / \
      4   8
     /   / \
   11  13  4
   / \       \
  7   2       1

*/

#include<iostream>
using namespace std;


#include "Node.h"

bool pathSum(Node* root,int targetSum) {
    if(!root){
        return false;
    }
    if(!root->left && !root->right){  // leaf node
        return (targetSum == root->val);
    }
    targetSum-=root->val;
    return pathSum(root->left,targetSum) || pathSum(root->right,targetSum);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->right = new Node(1);

    int targetSum = 10;
    if(pathSum(root, targetSum)) {
        cout << "Path with sum " << targetSum << " exists." << endl;
    } else {
        cout << "No path with sum " << targetSum << " exists." << endl;
    }

    return 0;
}

/*

                                   [5,10]
                                   /    \
                              ↓false     ↓false
                            [4,5]        [8,5]
                            /               /    \
                      ↓false              [13,-3]  [4,-3]
                    [11,1]                 ↑false     /      \
                   /      \                       ↓false    [1,-7]
          ↓false          ↓false                         ↑false
       [7,-10]         [2,-10]                    [null,-7]   [1,-7]
        ↑false          ↑false                   ↑false       ↑false
            \            /                            \       /
                 [11,1]                            [4,-3]
                       ↑false                         ↑false
                        |                              |
                      [4,5]                        [8,5]
                         ↑false                      ↑false
                             \                        /
                                 [5,10]
                                    ↑false



*/