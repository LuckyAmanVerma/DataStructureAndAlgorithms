/*
Binary Search Tree (BST) Implementation in C++
This code implements a basic Binary Search Tree (BST) with insert, search, and delete operations.
Time Complexity:
- Insert: O(h) where h is the height of the tree (O(log n) for balanced trees, O(n) for skewed trees).
- Search: O(h) for the same reasons as insert.
- Delete: O(h) for the same reasons as insert.
Space Complexity:   
- O(n) for the tree structure, where n is the number of nodes in the tree.
Unbalanced BST can degrade to O(n) in the worst case (like a linked list).
A BST is balanced if the height of the left and right subtrees of any node differ by at most one.
*/

TreeNode* createNode(int data) {
    TreeNode* newNode = new TreeNode();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
TreeNode* search(TreeNode* root, int target) {
    if(root == nullptr || root->data == target) {
        return root;
    }
    if(target < root->data) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

