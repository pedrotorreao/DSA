/******************************************************************************/
/* Problem: 105. Construct Binary Tree from Preorder and Inorder Traversal ****/
/******************************************************************************/
/*
--Problem statement:
  Given two integer arrays preorder and inorder where preorder is the preorder
  traversal of a binary tree and inorder is the inorder traversal of the same tree,
  construct and return the binary tree.

  > Example 1:
      Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
      Output: [3,9,20,null,null,15,7]

  > Example 2:
      Input: preorder = [-1], inorder = [-1]
      Output: [-1]

--Inputs:
  -std::vector<int>: integer arrays containing preorder and inorder traversals.

--Output:
  -TreeNode *: 'root' of the constructed binary tree.

--Constraints:
  :: 1 <= preorder.length <= 3000
  :: inorder.length == preorder.length
  :: -3000 <= preorder[i], inorder[i] <= 3000
  :: preorder and inorder consist of unique values.
  :: Each value of inorder also appears in preorder.
  :: Preorder is guaranteed to be the preorder traversal of the tree.
  :: Inorder is guaranteed to be the inorder traversal of the tree.

--Reasoning: See comments below.

--Time complexity: O(N^2), where N is the total number of nodes to be added.

--Space complexity: O(1), if we don't take into account the memory allocated for the output.

*/

#include <iostream>
#include <queue>
#include <vector>

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

class TreeBuilder {
public:
  static TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    int current_root_index = 0,           // current root index in the 'preorder' array
        start_subtree = 0,                // start of the current subtree in 'inorder'
        end_subtree = inorder.size() - 1; // end of the current subtree in 'inorder'

    return buildTree_helper(preorder, inorder, current_root_index, start_subtree, end_subtree);
  }

  static TreeNode *buildTree_helper(std::vector<int> &preorder,
                                    std::vector<int> &inorder,
                                    int &curr_root_id,
                                    int start_subtree,
                                    int end_subtree) {
    // reached a leaf node:
    if (start_subtree > end_subtree)
      return nullptr;

    TreeNode *root = new TreeNode(preorder.at(curr_root_id));

    int split_id{0};

    for (int i{0}; i < inorder.size(); ++i) {
      if (root->val == inorder.at(i)) // found the position of the current root in 'inorder',
      {                               // values to the left of 'i' will be part of the left subtree
        split_id = i;
        break; // and values to the right of 'i' will part of the right subtree.
      }
    }

    ++curr_root_id;

    root->left = buildTree_helper(preorder, inorder, curr_root_id, start_subtree, split_id - 1); // recur for left subtree
    root->right = buildTree_helper(preorder, inorder, curr_root_id, split_id + 1, end_subtree);  // recur for right subtree

    return root;
  }
};

void levelOrderTraversal(TreeNode *root);

int main() {
  std::vector<int> pre_order{3, 9, 20, 15, 7};
  std::vector<int> in_order{9, 3, 15, 20, 7};

  TreeNode *root = TreeBuilder::buildTree(pre_order, in_order);

  levelOrderTraversal(root);

  return 0;
}

void levelOrderTraversal(TreeNode *root) {
  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *curr = q.front();
    q.pop();

    std::cout << curr->val << "  ";
    if (q.empty())
      std::cout << "\n";

    if (curr->left)
      q.push(curr->left);
    if (curr->right)
      q.push(curr->right);
  }
}