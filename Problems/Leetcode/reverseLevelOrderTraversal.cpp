/*********************************************************************************************/
/* Problem: 107. Binary Tree Level Order Traversal II  ***************************************/
/*********************************************************************************************/
/*
--Problem statement:
  Given the root of a binary tree, return the bottom-up level order traversal of its nodes'
  values. (i.e., from left to right, level by level from leaf to root).

  > Example 1:
  Input: root = [3,9,20,null,null,15,7]
  Output: [[15,7],[9,20],[3]]

  > Example 2:
  Input: root = [1]
  Output: [[1]]

  > Example 3:
  Input: root = []
  Output: []

--Inputs:
  -TreeNode*: root of a binary tree.

--Output:
  -int[][]: bottom-up level order traversal of its nodes'  values

--Constraints:
  :: The number of nodes in the tree is in the range [0, 2000].
  :: -1000 <= Node.val <= 1000

--Reasoning: See comments below.
*/

#include <iostream>
#include <queue>
#include <stack>
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

/**********************************************************************************************
***********************************************************************************************
** Solution #1: Use a stack for getting th
--Time complexity:
  O(N), where N is the total number of nodes in the tree, since we must traverse each node on
  the tree.

--Space complexity:
  O(N), where N is the total number of nodes in the tree, since we need O(N) space for the return
  list, the queue (even, though it will at most contain N/2 elements) and the stack.
**********************************************************************************************/
class Solution_1 {
public:
  static std::vector<std::vector<int>> levelOrderBottom_1(TreeNode *root) {
    if (root == nullptr)
      return std::vector<std::vector<int>>();

    // output 2d array containing the levels' subarrays:
    std::vector<std::vector<int>> lvlOrderTrav;
    // temp array to hold all the nodes present in a single level:
    std::vector<int> currLevelNodes;
    // stack for storing the level nodes in the correct order:
    std::stack<std::vector<int>> st;
    // queue for storing pointers to "TreeNode" objects:
    std::queue<TreeNode *> q;

    // add the root node to the queue:
    q.push(root);

    // iterate while we still have nodes left to process:
    while (!q.empty()) {
      // number of elements in the current level:
      int nodesAtCurrLevel = q.size();

      // remove "nodesAtCurrLevel" elements from the tree and add them to
      // the temp array holding the values for the current level:
      for (int node{0}; node < nodesAtCurrLevel; ++node) {
        TreeNode *curr = q.front();
        q.pop();

        currLevelNodes.push_back(curr->val);

        // check is the current node has any existing children; if so,
        // add them to the queue:
        if (curr->left != nullptr)
          q.push(curr->left);

        if (curr->right != nullptr)
          q.push(curr->right);
      }
      // add all the nodes from the current level to the output array:
      // lvlOrderTrav.push_front(currLevelNodes);
      st.push(currLevelNodes);
      // clear the temp array for the next level:
      currLevelNodes.clear();
    }

    while (!st.empty()) {
      lvlOrderTrav.push_back(st.top());
      st.pop();
    }

    return lvlOrderTrav;
  }
};
/*********************************************************************************************/

/**********************************************************************************************
** Solution #2:
--Time complexity:
  O(N), where N is the total number of nodes in the tree, since we must traverse each node on
  the tree.

--Space complexity:
  O(N), where N is the total number of nodes in the tree, since we need O(N) space for the return
  list and for the queue (even, though it will at most contain N/2 elements simultaneosly).
**********************************************************************************************/
class Solution_2 {
private:
  static int height(TreeNode *root) {
    if (root == nullptr)
      return 0;

    return std::max(height(root->left), height(root->right)) + 1;
  }

public:
  static std::vector<std::vector<int>> levelOrderBottom_2(TreeNode *root) {
    int h = height(root);
    // output 2d array containing the levels' subarrays:
    std::vector<std::vector<int>> lvlOrderTrav(h);
    // if tree is empty, return the empty array:
    if (root == nullptr)
      return lvlOrderTrav;

    // queue for storing pointers to "TreeNode" objects:
    std::queue<TreeNode *> q;
    // add the root node to the queue:
    q.push(root);

    // iterate while we still have nodes left to process:
    while (!q.empty()) {
      // number of elements in the current level:
      int nodesAtCurrLevel = q.size();
      // temp array to hold all the nodes present in a single level:
      std::vector<int> currLevelNodes;

      // remove "nodesAtCurrLevel" elements from the tree and add them to
      // the temp array holding the values for the current level:
      for (int node{0}; node < nodesAtCurrLevel; ++node) {
        TreeNode *curr = q.front();
        q.pop();

        currLevelNodes.push_back(curr->val);

        // check is the current node has any existing children; if so,
        // add them to the queue:
        if (curr->left != nullptr)
          q.push(curr->left);

        if (curr->right != nullptr)
          q.push(curr->right);
      }
      // add all the nodes from the current level to the opposite end of the output array:
      lvlOrderTrav.at(h - 1) = currLevelNodes;
      --h;
    }

    return lvlOrderTrav;
  }
};
/*********************************************************************************************/

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

  std::vector<std::vector<int>> trav;

  trav = Solution_1::levelOrderBottom_1(root);
  display2D<int>(trav);

  trav = Solution_2::levelOrderBottom_2(root);
  display2D<int>(trav);

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