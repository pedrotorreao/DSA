/****************************************************************/
/*Problem: Tree - Insert (HR)  ********/
/****************************************************************/
/*
-- Summary:
You are given a pointer to the root of a binary search tree and values to be inserted into the tree. Insert the values into their appropriate position in the binary search tree and return the root of the updated binary tree. 
-- Input(s):
Pointer to the root of a binary search tree.
-- Expected output(s):
Return the root of the binary search tree after inserting the value into the tree.
-- Constraints:
1 <= Nodes in the tree <= 500
*/
/* ----------- Rest of the code for context ------------: 
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	  Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

                return root;
            }
      }
*/
Node * insert(Node * root, int data) {
  if (root == NULL) {
      root = new Node(data);
      return root;
  } 
  if (data < root->data) {
      if (root->left == NULL) { 
          root->left = new Node(data); return root;
      }
      insert(root->left, data);
  }
  else if (data > root->data) {
      if (root->right == NULL) { 
          root->right = new Node(data); return root;
      }
      insert(root->right, data);
  }
  return root;
}

//}; //End of Solution

/* ----------- main() function ------------: 
int main() {
  Solution myTree;
  Node* root = NULL;

  int t;
  int data;

  std::cin >> t;

  while(t-- > 0) {
    std::cin >> data;
    root = myTree.insert(root, data);
  }

  myTree.levelOrder(root);
  return 0;
}
*/