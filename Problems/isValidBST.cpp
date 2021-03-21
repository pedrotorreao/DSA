/******************************************************************/
/* Problem: Binary Search Tree - Check if BST is valid (LC)********/
/******************************************************************/
/**
 * Summary:
 *    Given the root of a binary tree, determine if it is a valid 
 *    binary search tree (BST). A valid BST is defined as follows:
 *    <> The left subtree of a node contains only nodes with keys less than the node's key.
 *    <> The right subtree of a node contains only nodes with keys greater than the node's key.
 *    <> Both the left and right subtrees must also be binary search trees.
 * Constraints:
 *    <> -2^11 <= Node.val <= 2^31 - 1
 *    <> The number os nodes in the tree is in the range [1, 10^6]

 */

#include <iostream>
#include <vector>

/* * * * * * * * PROVIDED * * * * * * * */
/**
 * Definition for a binary tree node. 
 */
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/* * * * * * * * * * * * * * * * * * * */

class Solution
{
public:
  void inOrder(TreeNode *root, std::vector<long> &list)
  {
    if (root == NULL)
    {
      return;
    }

    inOrder(root->left, list);
    list.push_back(root->val);
    inOrder(root->right, list);
  }

  bool isValidBST(TreeNode *root)
  {
    long minLimit = -2147483649;

    std::vector<long> sortedList;

    /**Use In-order traversal to go through the tree 
         * and fill the vector. If the tree satisfies the BST  
         * properties, the vector elements will be sorted. */
    inOrder(root, sortedList);

    // Checks if the vector sortedList is sorted.
    for (size_t i{0}; i < sortedList.size(); i++)
    {
      if (sortedList.at(i) <= minLimit)
      {
        return false;
      }
      minLimit = sortedList.at(i);
    }
    return true;
  }
};