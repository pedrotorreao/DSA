/*********************************************************************************************/
/* Problem: 235. Lowest Common Ancestor of a Binary Search Tree ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given
  nodes in the BST.

  According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between
  two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow
  a node to be a descendant of itself).”

  > Example 1:
  Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
  Output: 6
  Explanation: The LCA of nodes 2 and 8 is 6.

  > Example 2:
  Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
  Output: 2
  Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

  > Example 3:
  Input: root = [2,1], p = 2, q = 1
  Output: 2

--Inputs:
  -TreeNode*: root and two other nodes from the binary tree.

--Outputs:
  -TreeNode*: lowest common ancestor.

--Constraints:
   :: The number of nodes in the tree is in the range [2, 105].
   :: -10^9 <= Node.val <= 10^9
   :: All Node.val are unique.
   :: p != q
   :: p and q will exist in the BST.

--Reasoning: See comments below.

--Time complexity:

--Space complexity:

*/

#include <iostream>

// Definition for a binary tree node:
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *insert(TreeNode *root, int value) {
  if (root == nullptr)
    return new TreeNode(value);

  if (value > root->val)
    root->right = insert(root->right, value);
  else if (value < root->val)
    root->left = insert(root->left, value);

  return root;
}

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root)
      return nullptr;

    if (root->val < p->val && root->val < q->val)
      return lowestCommonAncestor(root->right, p, q);

    if (root->val > p->val && root->val > q->val)
      return lowestCommonAncestor(root->left, p, q);

    return root;
  }
};

int main() {
  Solution sol;

  TreeNode *root = nullptr;

  root = new TreeNode(6);

  root->left = new TreeNode(2);
  root->right = new TreeNode(8);

  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);

  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);

  return 0;
}