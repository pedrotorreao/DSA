/*********************************************************************************************/
/* Problem: 572. Subtree of Another Tree ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given the roots of two binary trees root and subRoot, return true if there is a subtree of
  root with the same structure and node values of subRoot and false otherwise.
  A subtree of a binary tree tree is a tree that consists of a node in tree and all of this
  node's descendants. The tree tree could also be considered as a subtree of itself.

  > Example 1:
  Input: root = [3,4,5,1,2], subRoot = [4,1,2]
  Output: true

  > Example 2:
  Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
  Output: false

--Inputs:
  -TreeNode*: roots of two binary trees

--Outputs:
  -bool: whether there is a subtree of root with the same structure and node values of subRoot.

--Constraints:
   :: The number of nodes in the root tree is in the range [1, 2000].
   :: The number of nodes in the subRoot tree is in the range [1, 1000].
   :: -10^4 <= root.val <= 10^4
   :: -10^4 <= subRoot.val <= 10^4

--Reasoning: See comments below.

--Time complexity:
    O(N*M), where N is the size of the main binary tree and M is the size of the subtree. This
    is the case because we may have to compare each node in the main binary tree to all of the
    nodes in the subtree.

--Space complexity: O(N), due to recursive function calls.

*/

#include <iostream>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    // - base case:
    //    main tree is empty, return false:
    if (!root)
      return false;
    // - base case:
    //    current root node matches the root of the subtree and their subtrees are the same,
    //    return true:
    if (isSameTree(root, subRoot))
      return true;
    // - recursive case:
    //    for each children, compare them to the subtree:
    return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
  }

  // check whether two binary trees are the same:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // - base case:
    //    both trees are empty, so they are technically the same, return true:
    if (!p && !q)
      return true;
    // - base case:
    //    one of the trees is empty, which makes them different, return false:
    if (!p || !q)
      return false;
    // - recursive case:
    //    check whether the trees are the same by comparing their root values and
    //    their subtrees recursively:
    return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
  }
};

int main() {
  std::cout << std::boolalpha;

  Solution sol;

  TreeNode *root = nullptr;
  TreeNode *subRoot = nullptr;

  root = new TreeNode(3);
  root->left = new TreeNode(4);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(2);
  root->right = new TreeNode(5);

  subRoot = new TreeNode(4);
  subRoot->left = new TreeNode(1);
  subRoot->right = new TreeNode(2);

  std::cout << "subRoot is a subtree of root: " << sol.isSubtree(root, subRoot) << "\n\n";

  root->left->right->left = new TreeNode(0);

  std::cout << "subRoot is a subtree of root: " << sol.isSubtree(root, subRoot) << "\n\n";

  return 0;
}