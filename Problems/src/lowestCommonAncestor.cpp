/****************************************************************/
/*Problem: Binary Search Tree: Lowest Common Ancestor (HR) ******/
/****************************************************************/
/*
-- Summary:
You are given pointer to the root of the binary search tree and two values v1 and v2. You need to return the lowest common ancestor (LCA) of v1 and v2 in the binary search tree.
-- Input(s):
lca has the following parameters:
- root: a pointer to the root node of a binary search tree
- v1: a node.data value
- v2: a node.data value
-- Expected output(s):
Return the a pointer to the node that is the lowest common ancestor of v1 and v2.
-- Constraints:
1<=n,node.data<=25 | 1<=v1,v2<=25 | v1 != v2
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
Node *lca(Node *root, int v1,int v2) {
      //recursive solution:
      if (v1 < root->data && v2 < root->data) { //if both v1 and v2 values are smaller than root.data, keep going left on bst
          return lca(root->left, v1, v2);
      } else if (v1 > root->data && v2 > root->data) { //if both v1 and v2 values are greater than root.data, keep going right on bst
          return lca(root->right, v1, v2);
      }
      //otherwise, if one of the values is greater than root.data and the other one is smaller, it is the point the go to different subtrees and we have found our lowest common ancestor.
      return root;

      /* non-recursive solution:
      while (root != NULL) {
        if (v1 < root->data && v2 < root->data) {
          root = root->left;
        } else if(v1 > root->data && v2 > root->data) {
          root = root->right;
        } else {
          break;
        }
      }
      return root;
      */
}

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