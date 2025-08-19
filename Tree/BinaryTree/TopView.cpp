/*
Top view using BFS and unordered_map , or map
but map gives issue in coding portal , as it takes extra time to execute , 
*/

#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

vector<int> topView(Node *root) {
    if (!root) return {};

    unordered_map<int, int> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});
    int minHd = 0, maxHd = 0;

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        if (mp.find(hd) == mp.end()) {
            mp[hd] = node->data; // store only first node for that hd
        }

        if (node->left) {
            q.push({node->left, hd - 1});
            minHd = min(minHd, hd - 1);
        }
        if (node->right) {
            q.push({node->right, hd + 1});
            maxHd = max(maxHd, hd + 1);
        }
    }

    vector<int> ans;
    for (int hd = minHd; hd <= maxHd; hd++) {
        ans.push_back(mp[hd]);
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

    vector<int> top = topView(root);
    for (int val : top) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}