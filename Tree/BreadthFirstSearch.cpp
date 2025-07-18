/*
Read tree from left to right , 
*/


#include <iostream>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BFS (Level-Order) Traversal
void bfs(TreeNode* root) {
    if (!root) return;

    std::queue<TreeNode*> q;
    q.push(root);

    int level = 0;
    while (!q.empty()) {
        int levelSize = q.size();
        std::cout << "level: " << level << std::endl;

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* curr = q.front();
            q.pop();
            std::cout << curr->val << std::endl;

            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }
        }
        level++;
    }
}

// Example usage
int main() {
    // Construct a sample tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    bfs(root);

    // Cleanup (not shown: delete all nodes)
    return 0;
}