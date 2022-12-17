/*********************************************************************************************/
/* Problem: 226. Invert Binary Tree   ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given the root of a binary tree, invert the tree, and return its root.

  Example 1:
    Input: root = [4,2,7,1,3,6,9]
    Output: [4,7,2,9,6,3,1]

  Example 2:
    Input: root = [2,1,3]
    Output: [2,3,1]

  Example 3:
    Input: root = []
    Output: []

--Inputs:
  -TreeNode*: root of the binary tree

--Output:
  -TreeNode*: root of the inverted binary tree

--Constraints:
  :: The number of nodes in the tree is in the range [0, 100].
  :: -100 <= Node.val <= 100

--Reasoning:

--Time complexity:

--Space complexity:

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Approach #1 - recursive DFS:
--Reasoning:
  Pre-order traversal, at each node, swap it's left and right children.
--Time Complexity: O(N)
--Space Complexity: O(N)
*/
TreeNode *invertTree_1(TreeNode *root) {
  if (!root)
    return nullptr;
  if (!root->left && !root->right)
    return root;

  TreeNode *l = root->left;
  TreeNode *r = root->right;

  root->left = invertTree_1(r);
  root->right = invertTree_1(l);

  return root;
}

/* Approach #2 - :
--Reasoning:
  Level-order traversal, at each node, swap it's left and right children.
--Time Complexity: O(N)
--Space Complexity: O(N)
*/
TreeNode *invertTree_2(TreeNode *root) {
  if (!root)
    return nullptr;

  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *curr = q.front();
    q.pop();

    if (curr->left)
      q.push(curr->left);
    if (curr->right)
      q.push(curr->right);

    std::swap(curr->left, curr->right);
  }

  return root;
}

int main() {
  // ... tests performed on LeetCode's platform

  return 0;
}