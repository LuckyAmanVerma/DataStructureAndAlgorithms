/*
Binary Tree Implementation in C++
This code implements a basic Binary Tree with insert, search, and delete operations.
Time Complexity for unbalanced binary trees:
- Insert: O(n) for a complete binary tree, O(n) for an unbalanced tree.
- Search: O(n) for a complete binary tree, O(n) for an unbalanced tree.
- Delete: O(n) for a complete binary tree, O(n) for an unbalanced tree.
Space Complexity:
- O(n) for the tree structure, where n is the number of nodes in the tree.
Unbalanced Binary Trees can degrade to O(n) in the worst case (like a linked list).

Time Complexity for balanced binary trees:
- Insert: O(log n) for a balanced binary tree.
- Search: O(log n) for a balanced binary tree.
- Delete: O(log n) for a balanced binary tree.
Space Complexity for balanced binary trees:
- O(n) for the tree structure, where n is the number of nodes in the tree.
*/

class BinaryTree {
    // Node struct moved to Node.h
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    // Insert, search, delete methods will go here
    void insert(int val) {
        if (!root) {
            root = new Node(val);
            return;
        }
        insertHelper(root, val);
    }
    void insertHelper(Node* node, int val) {
        if (val < node->data) {
            if (node->left) {
                insertHelper(node->left, val);
            } else {
                node->left = new Node(val);
            }
        } else {
            if (node->right) {
                insertHelper(node->right, val);
            } else {
                node->right = new Node(val);
            }
        }
    }

    boolean search(int val) {
        return searchHelper(root, val);
    }

    boolean searchHelper(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) {
            return searchHelper(node->left, val);
        } else {
            return searchHelper(node->right, val);
        }
    }

    int deleteRoot() {
    if (!root) return -1;        // empty tree

    Node* toDelete = root;
    // Case 1 & 2: 0 or 1 child
    if (!root->left || !root->right) {
        root = (root->left) ? root->left : root->right;
    }
    else {
        // Case 3: two children → find in-order successor
        Node* parent = root;
        Node* succ   = root->right;
        // go left as far as possible
        while (succ->left) {
            parent = succ;
            succ   = succ->left;
        }
        // copy successor value
        root->val = succ->val;
        // detach successor from its parent
        if (parent->left == succ)
            parent->left  = succ->right;
        else
            parent->right = succ->right;
        toDelete = succ;        // we’ll delete this node
    }

    int ret = toDelete->val;
    delete toDelete;            // free memory
    return ret;
}
};