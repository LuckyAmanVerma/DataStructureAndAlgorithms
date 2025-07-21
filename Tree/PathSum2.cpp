/*
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
*/

#include <vector>
#include <algorithm>
using namespace std;


#include "Node.h"
using TreeNode = Node;

class Solution {
public:
    vector<vector<int>> pathSum(Node* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        path.reserve(getHeight(root));     // reserve max depth
        dfs(root, targetSum, path, result);
        return result;
    }

private:
    void dfs(TreeNode* node,
             int targetSum,
             vector<int>& path,
             vector<vector<int>>& result) {
        if (!node) return;

        path.push_back(node->val);
        targetSum -= node->val;

        // Leaf & sum matches
        if (!node->left && !node->right && targetSum == 0) {
            result.emplace_back(path);
        } else {
            dfs(node->left, targetSum, path, result);
            dfs(node->right, targetSum, path, result);
        }

        path.pop_back();  // backtrack
    }

    // Helper to compute tree height for reserve()
    int getHeight(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};