/****************************************************************/
/*Problem: Tree: Height of a Binary Tree (HR)  ********/
/****************************************************************/
/*
-- Summary:
Complete the getHeight or height function in the editor. It must return the height of a binary tree as an integer.
-- Input(s):
getHeight or height has the following parameter(s):
root: a reference to the root of a binary tree.
-- Expected output(s):
Your function should return a single integer denoting the height of the binary tree.
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

int height(Node* root) {
  // Write your code here.
  if (root == NULL) {
      return -1;
  }
  int l = height(root->left);
  int r = height(root->right);
  
  if(l > r) {
      return (l + 1);
  } else {
      return (r + 1);
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

  myTree.levelOrder(root);
  return 0;
}
*/