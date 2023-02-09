/****************************************************************************************/
/* Problem: 113. Path Sum II  ***********************************************************/
/****************************************************************************************/
/*
--Problem statement:
  Given the root of a binary tree and an integer 'targetSum', return all root-to-leaf paths
  where the sum of the node values in the path equals 'targetSum'. Each path should be returned
  as a list of the node values, not node references.

  A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf
  is a node with no children.

  > Example 1:
  Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
  Output: [[5,4,11,2],[5,8,4,5]]
  Explanation:
    There are two paths whose sum equals targetSum:
    5 + 4 + 11 + 2 = 22
    5 + 8 + 4 + 5 = 22

  > Example 2:
  Input: root = [1,2,3], targetSum = 5
  Output: []

  > Example 3:
  Input: root = [1,2], targetSum = 0
  Output: []

--Inputs:
  -TreeNode*: root of a binary tree.
  -int: target value to be matched

--Output:
  -int[][]: all root-to-leaf paths where the sum of the node values in the path equals 'targetSum'

--Constraints:
  :: The number of nodes in the tree is in the range [0, 5000].
  :: -1000 <= Node.val <= 1000
  :: -1000 <= targetSum <= 1000

--Reasoning: See comments below.

--Time complexity:
  O(N), where N is the total number of nodes in the tree, since, in the worst scenario, we'll
  need to visit each node of the tree.
  O(N^2), if we consider the fact that for every leaf node, we might have to store its path, by
  making a copy of the current path, that takes O(N), which will then amount a total time complexity
  of O(N^2).

--Space complexity:
  O(N) in the worst case, where N is the total number of nodes in the tree. This is due to the storage
  required for the recursion stack. In the worst case, the tree is completely skewed and has the structure
  of a linked list. Also, this is if we ignore the space requires to return to array with all the paths
  matching the target sum.
*/

#include <iostream>
#include <stack>
#include <vector>

template <typename T>
void display2D(const std::vector<std::vector<T>> &mat);

// Definition for a binary tree node:
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *insertNode(TreeNode *root, int val);

class Solution {
public:
  static bool isLeaf(TreeNode *node) {
    return (node->left == nullptr) && (node->right == nullptr);
  }

  static std::vector<std::vector<int>> allPathsToSum(TreeNode *root, int target) {
    std::vector<std::vector<int>> paths;
    std::vector<int> curr;

    traversePaths_DFS(root, target, 0, paths, curr);

    return paths;
  }

  static void traversePaths_DFS(TreeNode *root, int target, int currSum,
                                std::vector<std::vector<int>> &paths,
                                std::vector<int> currPath) {
    if (root == nullptr)
      return;

    // add current node value to the sum:
    currSum += root->val;
    currPath.push_back(root->val);

    // if current path sum matches the target value and current node is a
    // leaf node, we've got a matching path:
    if ((currSum == target) && isLeaf(root))
      paths.push_back(currPath);

    // otherwise, recurse down the tree with the updated path sum:
    // traverse left subtree:
    traversePaths_DFS(root->left, target, currSum, paths, currPath);
    // traverse right subtree:
    traversePaths_DFS(root->right, target, currSum, paths, currPath);
  }
};

int main() {
  std::cout << std::boolalpha;

  TreeNode *root = nullptr;

  root = insertNode(root, 15);

  root = insertNode(root, 5);
  root = insertNode(root, 23);

  root = insertNode(root, -3);
  root = insertNode(root, 9);
  root = insertNode(root, 31);
  root = insertNode(root, -1);
  root = insertNode(root, 6);
  root = insertNode(root, 12);

  int target{};
  std::vector<std::vector<int>> allPaths;

  target = 35;
  allPaths = Solution::allPathsToSum(root, target);
  std::cout << "Tree has a path root->leaf which sum to " << target << ": ";
  display2D(allPaths);

  target = 16;
  allPaths = Solution::allPathsToSum(root, target);
  std::cout << "Tree has a path root->leaf which sum to " << target << ": ";
  display2D(allPaths);

  root = nullptr;

  root = new TreeNode(9);

  root->right = new TreeNode(-12);
  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(0);

  root->left = new TreeNode(5);
  root->left->left = new TreeNode(-14);
  root->left->right = new TreeNode(-11);
  root->left->right->right = new TreeNode(-3);

  target = 0;
  allPaths = Solution::allPathsToSum(root, target);
  std::cout << "Tree has a path root->leaf which sum to " << target << ": ";
  display2D(allPaths);

  return 0;
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