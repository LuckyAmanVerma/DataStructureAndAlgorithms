/*
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
        5
       / \
      4   8
     /   / \
   11  13  4
   / \     / \
  7   2   5   1


*/


#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#include "Node.h"
using Node = Node;

// Forward declarations
void dfs(Node *root, int targetSum, vector<int> &path, vector<vector<int>> &result);
int getHeight(Node *node);

vector<vector<int>> pathSum(Node *root, int targetSum)
{
    vector<vector<int>> result;
    vector<int> path;
    path.reserve(getHeight(root)); // reserve max depth
    dfs(root, targetSum, path, result);
    return result;
}

void dfs(Node *root,
         int targetSum,
         vector<int> &path,
         vector<vector<int>> &result)
{
    if (!root) return;

    path.push_back(root->val);

    // If leaf, check the sum
    if (!root->left && !root->right) {
        if (targetSum == root->val) {
            result.push_back(path); // valid path
        }
    } else {
        // Otherwise, go left and right
        targetSum -=root->val;
        dfs(root->left, targetSum, path, result);
        dfs(root->right, targetSum, path, result);
    }

    // Backtrack: remove current node before returning
    path.pop_back();
}

// Helper to compute tree height for reserve()
int getHeight(Node *node)
{
    if (!node)
        return 0;
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->right = new Node(1);
    root->right->right->left = new Node(5);

    int targetSum = 22;
    vector<vector<int>> paths = pathSum(root, targetSum);

    for (const auto &path : paths)
    {
        cout << "[";
        for (int i = 0; i < path.size(); ++i)
        {
            cout << path[i];
            if (i < path.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}