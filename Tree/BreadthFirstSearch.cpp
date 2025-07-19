/*
Read tree from left to right ,
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BFS (Level-Order) Traversal
void bfs(TreeNode *root)
{
    if (!root)
        return;

    std::queue<TreeNode *> q;
    q.push(root);

    int level = 0;
    while (!q.empty())
    {
        int levelSize = q.size();
        std::cout << "level: " << level << std::endl;

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *curr = q.front();
            q.pop();
            std::cout << curr->val << std::endl;

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        level++;
    }
}

// Example usage

vector<vector<int>> BFS(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root){
        return ans;
    }
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()){
        int qsize = q.size();
        vector<int> level;
        for (int i = 0; i < qsize; i++){
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}
int main()
{
    /*Construct a sample tree:
                      3
                     / \
                    2   5
                    / \
                   1   4
                   */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    bfs(root);

    // Cleanup (not shown: delete all nodes)
    return 0;
}