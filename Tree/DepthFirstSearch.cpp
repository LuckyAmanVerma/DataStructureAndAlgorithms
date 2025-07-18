/*
# In-Order Traversal ki Zaroorat (Why We Need It)

In-order traversal me hum **Left → Root → Right** order follow karte hain. Iski kuch key zarooratein yeh hain:

- BST se **sorted sequence** nikalne ke liye  
  In-order pehle left subtree, phir root, phir right subtree visit karta hai. BST me left < root < right rule ki wajah se ye traversal hamesha **ascending order** me values dega.

- **Kth smallest (ya largest)** element find karna  
  Jab sequence sorted hoti hai, to simple index count karke aap easily kth smallest element retrieve kar sakte ho.

- **BST validation**  
  Agar kisi tree ka in-order traversal strictly increasing sequence deta hai, to wo tree valid BST hai.

- **Expression trees me infix notation**  
  Arithmetic expression stored as binary tree me in-order se infix form (jaise `(a + b) * c`) milta hai.

- **Consistent recursive framework**  
  Binary tree ke har node pe recursive approach uniform rehta hai, jisse implementation aur reasoning dono simple ho jate hain.

---

Ab jab purpose clear ho gaya, to next step me hum code dekh sakte hain—recursive aur iterative dono tarike. Shall we jump into implementation?
In-Order - Left → Root → Right - Used in BSTs for sorted output  
Pre-Order - Root → Left → Right -Useful for copying trees, prefix notation
Post-Order Left → Right → Root - Used in deleting trees, postfix notation
Time Complexity : - 0 n , for all cases

*/

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    std::cout << root->val << " ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    if (!root) return;
    std::cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->val << " ";
}

