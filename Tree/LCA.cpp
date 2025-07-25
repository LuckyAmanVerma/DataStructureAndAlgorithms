/*
We need to check two condition:-
If root is less than both nodes  , then go right 
If root is greater than both nodes , then go left
else return root
*/

#include<iostream>
using namespace std;


#include "Node.h"

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(!root){
            return nullptr;
        }
        if(root->val<p->val && root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }