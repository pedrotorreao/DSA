/****************************************************************/
/*Problem: Tree - Preorder Traversal (HR)  ********/
/****************************************************************/
/*
-- Summary:
Complete the preOrder function in your editor below, which has 1 parameter: a pointer to the root of a binary tree. It must print the values in the tree's preorder traversal as a single line of space-separated values.
-- Input(s):
Our hidden tester code passes the root node of a binary tree to your preOrder function.
-- Expected output(s):
Print the tree's preorder traversal as a single line of space-separated values.
-- Constraints:
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
  //preOrder() is a method of the Solution class
  //Pre-order traversal: Root --> Left Subtree --> Right Subtree
  void preOrder(Node *root) {
    if(root == NULL) {
      return;
    } else {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
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

  myTree.preOrder(root);
  return 0;
}
*/