/*
Bottom view of tree using BFS
        1
       / \
      2   3
     / \ / \
    4  5 6  7
*/

#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include"../Node.h" // Updated include path to look in parent directory

using namespace std;

vector<int> bottomView(Node *root) {
        if(!root) return {};
        vector<int> ans;
        queue<pair<Node*,int>> q;
        unordered_map<int,int> m;
        int start=0;
        int end=0;
        q.push({root,0});
        
        while(!q.empty()) {
            int size=q.size();
            for(int i=0;i<size;i++) {
                auto [node, hd] = q.front();
                q.pop();
                m[hd]=node->val;
                if(node->left) {
                    q.push({node->left,hd-1});
                    start=min(start,hd-1);
                }
                if(node->right) {
                    q.push({node->right,hd+1});
                    end=max(end,hd+1);
                }
            }
        }

        for(int i=start;i<=end;i++) {
            ans.push_back(m[i]);
        }
        return ans;
        
    }

    int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> bottom = bottomView(root);
    for (int val : bottom) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}