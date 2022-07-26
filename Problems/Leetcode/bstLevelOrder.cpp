/******************************************************************************/
/* Problem: LC 102. Binary Tree Level Order Traversal
/*******************************************************************************/
/*
Given the root of a binary tree, return the level order traversal of its nodes'
values. (i.e., from left to right, level by level).
Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]

Example 2:
    Input: root = [1]
    Output: [[1]]

Example 3:
    Input: root = []
    Output: []

Constraints:
    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000
*/

#include <iostream>
#include <queue>
#include <vector>

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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode *root) {
  std::vector<std::vector<int>> level_order;

  if (root == nullptr)
    return level_order;

  std::queue<TreeNode *> q;
  q.push(root);

  std::vector<int> cur_lvl;

  while (!q.empty()) {
    int nodes_cur_lvl = q.size();

    for (int i{0}; i < nodes_cur_lvl; ++i) {
      TreeNode *cur = q.front();
      q.pop();

      cur_lvl.push_back(cur->val);

      if (cur->left != nullptr)
        q.push(cur->left);

      if (cur->right != nullptr)
        q.push(cur->right);
    }

    level_order.push_back(cur_lvl);
    cur_lvl.clear();
  }

  return level_order;
}

int main() {
  //..

  return 0;
}