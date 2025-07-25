#include<iostream>
using namespace std;

#include "Node.h"

bool identicalTree(Node* root1,Node* root2){
    if(!root1 && !root2){
        return true;
    }
   if((!root1 && root2) || (root1 && !root2)){
        return false;
    }
    
    bool left=identicalTree(root1->left,root2->left);
    bool right=identicalTree(root1->right,root2->right);
    bool rootVal = root1->val==root2->val;
    
    return left &&right && rootVal;
}