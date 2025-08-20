/*
Zig zag traversal of a binary tree using BFS or level order traversal

        1
      /   \
     2     3
    / \   / \
   4   5 6   7

*/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include"../Node.h"
using namespace std;

vector<int> zigzag(Node* root) {
    if(!root) return {};
    queue<Node*> q;
    vector<int> ans;
    bool leftToRight=true;
    q.push(root);

    while(!q.empty()) {
        int n=q.size();
        vector<int> level(n);
        //level traversal using bfs
        for(int i=0;i<n;i++) {
            Node* front=q.front();
            q.pop();
            int index=leftToRight?i:n-i-1;
            level[index]=front->val;
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        leftToRight=!leftToRight;
        for(auto data:level){
            ans.push_back(data);
        }

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

    vector<int> result = zigzag(root);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}