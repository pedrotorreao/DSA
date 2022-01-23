/*********************************************************************************************/
/* Problem: Same Tree (LC)  ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given the roots of two binary trees 'p' and 'q', write a function to check if they are the
  same or not. Two binary trees are considered the same if they are structurally identical, and
  the nodes have the same value.
  > Example:
    a.) Input: p = [1,2,3], q = [1,2,3]
        Output: true
    b.) Input: p = [1,2], q = [1,null,2]
        Output: false
    c.) Input: p = [1,2,1], q = [1,1,2]
        Output: false

--Inputs:
  Node* p: root node for 'p'
  Node* q: root node for 'q'

--Output:
  - boolean: the height of the stacks when they are equalized

--Constraints:
  The number of nodes in both trees is in the range [0, 100].
  -10^4 <= Node.val <= 10^4

--Reasoning:
  Recursively traverse both trees at the same time and in the same way comparing the node's values
  and the trees' structure (location of null nodes), if any mismatch is found, return false; otherwise,
  return true;

--Time complexity:
  O(N), because in the worst case scenario we'll have too check all the nodes in the trees.

--Space complexity: O(1), no additional input-dependent space is allocated.

*/

#include <iomanip>
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

  TreeNode *insert(TreeNode *root, int value) {
    if (root == nullptr) {
      return new TreeNode(value);
    }

    if (root->val < value)
      root->left = insert(root->left, value);
    else if (root->val > value)
      root->right = insert(root->right, value);

    return root;
  }
};

bool isSameTree(TreeNode *p, TreeNode *q) {
  if (p == nullptr && q == nullptr)
    return true;

  if (p == nullptr || q == nullptr)
    return false;

  if (p->val != q->val)
    return false;

  return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main() {
  std::cout << std::boolalpha;

  TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode *q = new TreeNode(1, new TreeNode(2), new TreeNode(3));

  std::cout << "Trees are equal: " << isSameTree(p, q) << "\n";

  q->left = 0;
  std::cout << "Trees are equal: " << isSameTree(p, q) << "\n";

  p->left = 0;
  std::cout << "Trees are equal: " << isSameTree(p, q) << "\n";

  p->val = 9;
  std::cout << "Trees are equal: " << isSameTree(p, q) << "\n";

  return 0;
}