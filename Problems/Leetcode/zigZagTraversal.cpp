/*********************************************************************************************/
/* Problem: 103. Binary Tree Zigzag Level Order Traversal  ***********************************/
/*********************************************************************************************/
/*
--Problem statement:
  Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
  (i.e., from left to right, then right to left for the next level and alternate between).

  > Example 1:
  Input: root = [3,9,20,null,null,15,7]
  Output: [[3],[20,9],[15,7]]

  > Example 2:
  Input: root = [1]
  Output: [[1]]

  > Example 3:
  Input: root = []
  Output: []

--Inputs:
  -TreeNode*: root of a binary tree.

--Output:
  -int[][]: zig-zag traversal of the tree nodes.

--Constraints:
  :: -100 <= Node.val <= 100
  :: The number of nodes in the tree is in the range [0, 2000].

--Reasoning: See comments below.

--Time complexity:
  O(N), where N is the total number of nodes in the tree, since we must traverse each node on
  the tree.

--Space complexity:
  O(N), where N is the total number of nodes in the tree, since we need O(N) space for the return
  list and for the queue (even, though it will at most contain N/2 elements simultaneosly).
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

template <typename T>
void display2D(const std::vector<std::vector<T>> &mat);

TreeNode *insertNode(TreeNode *root, int newVal);

class Solution {
public:
  static std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    // if the tree is empty, return an empty vector:
    if (root == nullptr)
      return std::vector<std::vector<int>>();

    // output array:
    std::vector<std::vector<int>> zigZagTraversal;

    // variable which tracks whether a level is an even or odd level in order
    // to know when to zig and when to zag:
    bool rightToLeft{false};
    // queue for storing node neighbors:
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      // number of elements in the current level:
      int nodesAtCurrLevel = q.size();
      // temp array to hold all the nodes present in a single level:
      std::vector<int> currLevelNodes(nodesAtCurrLevel);
      // remove "nodesAtCurrLevel" elements from the queue and add them to
      // the temp array holding the values for the current level:
      for (int node{0}; node < nodesAtCurrLevel; ++node) {
        TreeNode *curr = q.front();
        q.pop();

        // perform reverse (right-to-left) level order traversal:
        if (rightToLeft)
          currLevelNodes.at(nodesAtCurrLevel - node - 1) = curr->val;
        // perform regular (left-to-right) level order traversal:
        else
          currLevelNodes.at(node) = curr->val;

        if (curr->left != nullptr)
          q.push(curr->left);
        if (curr->right != nullptr)
          q.push(curr->right);
      }
      zigZagTraversal.push_back(currLevelNodes);
      rightToLeft = !rightToLeft;
    }

    return zigZagTraversal;
  }
};

int main() {
  TreeNode *root = nullptr;
  root = insertNode(root, 5);

  root = insertNode(root, 3);
  root = insertNode(root, 11);

  root = insertNode(root, -1);
  root = insertNode(root, 4);
  root = insertNode(root, 7);
  root = insertNode(root, 39);

  root = insertNode(root, 2);
  root = insertNode(root, 6);
  root = insertNode(root, 9);
  root = insertNode(root, 100);

  std::vector<std::vector<int>> zigzagTrav;

  zigzagTrav = Solution::zigzagLevelOrder(root);
  display2D<int>(zigzagTrav);

  root = nullptr;

  root = insertNode(root, 3);

  root = insertNode(root, -9);
  root = insertNode(root, 20);

  root = insertNode(root, 0);
  root = insertNode(root, 7);
  root = insertNode(root, 93);
  root = insertNode(root, 2);

  zigzagTrav = Solution::zigzagLevelOrder(root);
  display2D<int>(zigzagTrav);

  return 0;
}

// helpers - 2d grid displayer:
template <typename T>
void display2D(const std::vector<std::vector<T>> &mat) {
  for (T i{0}; i < mat.size(); ++i) {
    std::cout << "[ ";
    for (T j{0}; j < mat.at(i).size(); ++j) {
      std::cout << mat.at(i).at(j) << "  ";
    }
    std::cout << "]\n";
  }
  std::cout << "\n";
}

// helpers - insert new node function:
TreeNode *insertNode(TreeNode *root, int val) {
  if (!root)
    return new TreeNode(val);
  if (val > root->val)
    root->right = insertNode(root->right, val);
  else if (val < root->val)
    root->left = insertNode(root->left, val);
  else
    return root;

  return root;
}