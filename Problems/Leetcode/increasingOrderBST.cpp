/*********************************************************************************************/
/* Problem: 897. Increasing Order Search Tree (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

  > Example 1:
    Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
    Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
        1
         \
          2
        /
      3

  > Example 2:
    Input: root = [5,1,7]
    Output: [1,null,5,null,7]

--Inputs:
  -TreeNode *: pointer to the 'root' node of a binary search tree.

--Output:
  -TreeNode *: pointer to the 'root' of the updated tree.

--Constraints:
  The number of nodes in the given tree will be in the range [1, 100].
  0 <= Node.val <= 1000

--Reasoning: See comments below.

--Time complexity: See comments below.

--Space complexity: See comments below.

*/

#include <iostream>
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

void inOrderTrav(TreeNode *root) {
  if (root != nullptr) {
    inOrderTrav(root->left);
    std::cout << root->val << "   ";
    inOrderTrav(root->right);
  }
}

// #1: My dumb solution:
// time complexity: O(N), since we visit all the nodes
// space complexity: O(N), since we allocated space all the node in the bst.

void inOrder(TreeNode *root, std::vector<int> &res) {
  if (root != nullptr) {
    inOrder(root->left, res);
    res.push_back(root->val);
    inOrder(root->right, res);
  }
}

TreeNode *skewTree(TreeNode *root, const std::vector<int> &res) {
  int N = res.size();

  TreeNode *cur = root;

  // skip first node, already used to replace old root value:
  for (int i{1}; i < N; ++i) {
    cur->right = new TreeNode(res.at(i));
    cur = cur->right;
  }

  return root;
}

TreeNode *increasingBST_1(TreeNode *root) {
  std::vector<int> inOrderRes;
  inOrder(root, inOrderRes);

  root->left = nullptr;
  root->right = nullptr;

  if (inOrderRes.empty())
    return nullptr;

  root->val = inOrderRes.at(0);

  root = skewTree(root, inOrderRes);

  return root;
}

// #2: Improved short recursive solution, based on LC's Discussion section:
// time complexity: O(N), since we visit all the nodes
// space complexity: O(height), since we allocated space all the node in the bst.

TreeNode *increasingBST_2(TreeNode *root, TreeNode *next = nullptr) {
  if (root == nullptr)
    return next;

  TreeNode *newRoot = increasingBST_2(root->left, root);

  root->left = nullptr;
  root->right = increasingBST_2(root->right, next);

  return newRoot;
}

int main() {
  TreeNode *root = new TreeNode(10);

  TreeNode *n1 = new TreeNode(7);
  TreeNode *n2 = new TreeNode(1);
  TreeNode *n3 = new TreeNode(8);
  n1->left = n2;
  n1->right = n3;

  TreeNode *n4 = new TreeNode(14);
  TreeNode *n5 = new TreeNode(11);
  TreeNode *n6 = new TreeNode(16);
  n4->left = n5;
  n4->right = n6;

  root->left = n1;
  root->right = n4;

  inOrderTrav(root);
  std::cout << "\n";

  inOrderTrav(increasingBST_1(root));
  std::cout << "\n";

  inOrderTrav(increasingBST_2(root));
  std::cout << "\n";

  return 0;
}