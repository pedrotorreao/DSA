/* * * * * * * * * * * * * * * * * *
Problem: LC 543. Diameter of Binary Tree

--Problem statement:

Given the root of a binary tree, return the length of the diameter of the tree. The diameter of
a binary tree is the length of the longest path between any two nodes in a tree. This path may or
may not pass through the root. The length of a path between two nodes is represented by the number
of edges between them.

> Example 1:
    Input: root = [1,2,3,4,5]
    Output: 3
    Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

> Example 2:
    Input: root = [1,2]
    Output: 1

--Constraints:
    :: The number of nodes in the tree is in the range [1, 10^4].
    :: -100 <= Node.val <= 100

--Inputs:
  -TreeNode*: root of a binary tree.

--Output:
  -int: the length of the diameter of the tree.

--Reasoning: Use DFS, see comments below.

--Time complexity:
  O(N), where N is the total number of nodes in the tree, since we traverse each node on
  the tree once.

--Space complexity:
  O(N), where N is the total number of nodes in the tree, since we need O(N) space for storing
  the recursion stack.
* * * * * * * * * * * * * * * * * */

#include <iostream>

// Definition for a binary tree node:
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
  static int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr)
      return 0;

    int treeDiameter = 0;

    countNodes(root, treeDiameter);

    return treeDiameter;
  }

  static int countNodes(TreeNode *node, int &diameter) {
    if (node == nullptr)
      return 0;

    int l_tree_height = countNodes(node->left, diameter);
    int r_tree_height = countNodes(node->right, diameter);

    // diameter at the current node will be equal to:
    //    --> height of left subtree + height of right sub-trees:
    diameter = std::max(diameter, l_tree_height + r_tree_height);

    // the height of the current node will be equal to the maximum value
    // between the heights of the left and right subtrees plus '1'
    // to account for the current node:
    return std::max(l_tree_height, r_tree_height) + 1;
  }
};

int main() {
  /* -- test cases available on:
      https://leetcode.com/problems/diameter-of-binary-tree/description/
  */
}