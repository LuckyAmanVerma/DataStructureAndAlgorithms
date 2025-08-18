/*
Read tree from left to right ,
https://www.youtube.com/watch?v=EoAsWbO7sqg
Another Question related to it - Reverse Level Order Traversal
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#include "Node.h"
using Node = Node;

// BFS (Level-Order) Traversal
/*
void bfs(Node *root)
{
    if (!root)
        return;

    std::queue<Node *> q;
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
*/
// Example usage

vector<vector<int>> BFS(Node *root)
{
    vector<vector<int>> ans;
    if (!root){
        return ans;
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        int qsize = q.size();
        vector<int> level;
        for (int i = 0; i < qsize; i++){
            Node* node = q.front();
            level.push_back(node->val);
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}
int main()
{
    /*Construct a sample tree:
                      1
                     / \
                    2   3
                    / \
                   4   5
                   */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> result = BFS(root);
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // Cleanup (not shown: delete all nodes)
    return 0;
}