/*
Print the right view of tree using BFS

        1
       / \
      2   3
     / \ / \
    4  5 6  7

*/

#include<iostream>
#include<queue>
#include"../Node.h"
using namespace std;

vector<int> rightView(Node* root) {
    if(!root) return {};
    vector<int> ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int totalElements =q.size();
        for(int i=0;i<totalElements;i++) {
            Node* front = q.front();
            q.pop();
            if(i==totalElements-1){
                ans.push_back(front->val);
            }
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
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

    vector<int> paths=rightView(root);
    cout<<"Right view of tree is: ";
    for(int i=0;i<paths.size();i++){
        cout<<paths[i]<<" ";
    }
    return 0;
}