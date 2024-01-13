/* * * * * * * * * * * * * * * * * *
Problem: LC 145. Binary Tree Postorder Traversal

url: https://leetcode.com/problems/binary-tree-postorder-traversal/description/

--Problem statement:
Given the root of a binary tree, return the postorder traversal of its nodes' values.

  > Example 1:
    Input: root = [1,null,2,3]
    Output: [3,2,1]

  > Example 2:
    Input: root = []
    Output: []

  > Example 3:
    Input: root = [1]
    Output: [1]


--Constraints:
    :: The number of nodes in the tree is in the range [0, 100].
    :: -100 <= Node.val <= 100

--Inputs:
  - TreeNode*: the "root" of a binary tree.

--Outputs:
  - int[]: array containing the postorder traversal of its nodes' values.

--Reasoning: Simple recursive approach.

--Time complexity:
    :: O(n), where n is the total number of nodes in the binary tree, since we need
    to visit all the nodes in the tree.

--Space complexity:
    :: O(log(h)), where h is the max heigth of the binary tree, since that represents the
    deepest we'll recurse before we begin returning, thus we'll use at most log(n) stack space.

* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <vector>

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
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> postorder{};
    postOrderHelper(root, postorder);

    return postorder;
  }
  void postOrderHelper(TreeNode *root, std::vector<int> &traversal) {
    if (root != nullptr) {
      postOrderHelper(root->left, traversal);
      postOrderHelper(root->right, traversal);
      traversal.push_back(root->val);
    }
  }
};

int main() {
  // test cases
}
