#include <iostream>
using namespace std;

/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

node * newNode(int val)
{
    node * newNode = new node;
    
    newNode->val = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->ht = 0;
    
    return newNode;
}
node * getHeight(node * root)
{
    if(root == NULL) {
        return -1;
    } else {
        return root->ht;
    }
}
node * insert(node * root,int val)
{
	if(root == NULL) {
        root = newNode(val); return root;
    }
    if(val > root->val) {
        root->right = insert(root->right, val);
    }
    else if(val < root->val) {
        root->left = insert(root->left, val);
    }
    else{ return nullptr; }
    
    root->ht = 1 + max(getHeight(root->left),getHeight(root->right));
  
    int balance = getHeight(root->left) - getHeight(root->right);
    
    
}