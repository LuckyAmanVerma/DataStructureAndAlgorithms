/*
f you’re writing a function to find predecessor/successor in a BST:
- Predecessor: rightmost node in left subtree
- Successor: leftmost node in right subtree

*/

#include<iostream>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int val;
    Node(int val):val(val),left(nullptr),right(nullptr) {}
};

void preAndSuc(Node* root,int target){
    if(!root) {
        cout<<"No data to check"<<endl;
    }

    Node * temp = root;
    int succ = -1;
    int pred = -1;

    while(temp->val!=target){
        if(temp->val>target){
            succ = temp->val;
            temp=temp->left;
        }
        else {
            pred = temp->val;
            temp=temp->right;
        }
    }

    // now our temp point to target node we calculate pred and succ now

    Node* leftTree = temp->left;
    Node* rightTree = temp->right;

    while(leftTree!=nullptr) {
        pred=leftTree->val;
        leftTree=leftTree->right;
    }

    while(rightTree!=nullptr) {
        succ=rightTree->val;
        rightTree=rightTree->left;
    }

    cout<<"Predecessor is "<<pred<<" and successor is "<<succ;
}

int main(){
    Node* root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    preAndSuc(root,3);
}