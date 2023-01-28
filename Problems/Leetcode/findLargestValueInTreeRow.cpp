/*********************************************************************************************/
/* Problem: 515. Find Largest Value in Each Tree Row  ***********************************/
/*********************************************************************************************/
/*
--Problem statement:
  Given the root of a binary tree, return an array of the largest value in each row of the tree
  (0-indexed).

  > Example 1:
  Input: root = [1,3,2,5,3,null,9]
  Output: [1,3,9]

  > Example 2:
  Input: root = [1,2,3]
  Output: [1,3]

--Inputs:
  -TreeNode*: root of a binary tree.

--Output:
  -int[]: array of the largest value in each row of the tree.

--Constraints:
  :: The number of nodes in the tree will be in the range [0, 104].
  :: -2^31 <= Node.val <= 2^31 - 1

--Reasoning: See comments below.

--Time complexity:
  O(N), where N is the total number of nodes in the tree, since we must traverse each node on
  the tree.

--Space complexity:
  O(N), where N is the total number of nodes in the tree, since we need O(N) space for the return
  list and for the queue (even, though it will at most contain N/2 elements simultaneosly).
*/

#include <iostream>
#include <limits>
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

template <typename T>
void display1D(const std::vector<T> &mat);

TreeNode *insertNode(TreeNode *root, int newVal);

class Solution {
public:
  static std::vector<int> largestValues(TreeNode *root) {
    // if the tree is empty, return an empty vector:
    if (root == nullptr)
      return std::vector<int>();

    // output array containing the max values at each level
    // of the binary tree:
    std::vector<int> maxLvlValues;
    // variable for tracking the max value at each level:
    int maxValueCurrLvl = std::numeric_limits<int>::min();

    // queue for storing node neighbors:
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      // number of elements in the current level:
      int nodesAtCurrLevel = q.size();
      // temp array to hold all the nodes present in a single level:
      std::vector<int> currLevelNodes(nodesAtCurrLevel);
      // traverse all the nodes, "nodesAtCurrLevel", on the current level
      // and store the largest value in "maxValueCurrLvl":
      for (int node{0}; node < nodesAtCurrLevel; ++node) {
        TreeNode *curr = q.front();
        q.pop();

        maxValueCurrLvl = std::max(maxValueCurrLvl, curr->val);

        if (curr->left != nullptr)
          q.push(curr->left);
        if (curr->right != nullptr)
          q.push(curr->right);
      }
      // add the largest value of the current level to the output:
      maxLvlValues.push_back(maxValueCurrLvl);
      // reset "maxValueCurrLvl" for the next level:
      maxValueCurrLvl = std::numeric_limits<int>::min();
    }

    return maxLvlValues;
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

  std::vector<int> levelLargestVals;

  levelLargestVals = Solution::largestValues(root);
  display1D<int>(levelLargestVals);

  root = nullptr;

  root = insertNode(root, 3);

  root = insertNode(root, -9);
  root = insertNode(root, 20);

  root = insertNode(root, 0);
  root = insertNode(root, 7);
  root = insertNode(root, 93);
  root = insertNode(root, 2);

  levelLargestVals = Solution::largestValues(root);
  display1D<int>(levelLargestVals);

  return 0;
}

// helpers - displayers:
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

template <typename T>
void display1D(const std::vector<T> &mat) {
  std::cout << "[  ";
  for (auto &m : mat)
    std::cout << m << "  ";
  std::cout << "]\n\n";
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