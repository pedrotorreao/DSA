/****************************************************************************************/
/* Problem: 112. Path Sum  **************************************************************/
/****************************************************************************************/
/*
--Problem statement:
  Given the 'root' of a binary tree and an integer 'targetSum', return true if the tree
  has a root-to-leaf path such that adding up all the values along the path equals 'targetSum'.
  A leaf is a node with no children.

  > Example 1:
  Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
  Output: true
  Explanation:
    The root-to-leaf path with the target sum is shown.

  > Example 2:
  Input: root = [1,2,3], targetSum = 5
  Output: false
  Explanation:
    There two root-to-leaf paths in the tree:
    (1 --> 2): The sum is 3.
    (1 --> 3): The sum is 4.
    There is no root-to-leaf path with sum = 5.

  > Example 3:
  Input: root = [], targetSum = 0
  Output: false
  Explanation:
    Since the tree is empty, there are no root-to-leaf paths.

--Inputs:
  -TreeNode*: root of a binary tree.
  -int: target value to be matched

--Output:
  -bool: boolean indicating whether there is a root to leaf path which adds up to targetSum.

--Constraints:
  :: The number of nodes in the tree is in the range [0, 5000].
  :: -1000 <= Node.val <= 1000
  :: -1000 <= targetSum <= 1000

--Reasoning: See comments below.

--Time complexity:
  O(N), where N is the total number of nodes in the tree, since, in the worst scenario, we'll
  need to visit each node of the tree.

--Space complexity:
  O(N) in the worst case, where N is the total number of nodes in the tree. This is due to the storage
  required for the recursion stack. In the worst case, the tree is completely skewed and has the structure
  of a linked list..
*/
#include <iostream>
#include <stack>
#include <vector>

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

  static bool hasPathSumDFS_rec(TreeNode *root, int target, int currSum) {
    if (root == nullptr)
      return false;

    // add current node value to the sum:
    currSum += root->val;
    // if current path sum matches the target value and current node is a
    // leaf node, we've got a matching path:
    if ((currSum == target) && isLeaf(root))
      return true;

    // otherwise, recurse down the tree with the updated path sum:
    return (hasPathSumDFS_rec(root->left, target, currSum) || hasPathSumDFS_rec(root->right, target, currSum));
  }

  static bool hasPathSumDFS_ite(TreeNode *root, int target) {
    if (root == nullptr)
      return false;

    std::stack<TreeNode *> st;
    TreeNode *curr = root;
    TreeNode *prev = nullptr;

    int currSum{0};

    // For this solution, we use a the postorder traversal approach
    // where a given node will only be removed from the stack when
    // its right sub-tree has been visited. This way, the current path
    // will be stored in the stack.

    // Iterate while there are nodes to be traversed:
    while (!st.empty() || curr != nullptr) {
      // Go as deep as possible in current node' left subtree
      // (i.e. while there are left children) keeping track of the current
      // path sum:
      while (curr != nullptr) {
        st.push(curr);
        currSum += curr->val;

        curr = curr->left;
      }

      // Get 'curr' back to the previous valid node:
      curr = st.top();

      // If current path sum matches the target value and current node is a
      // leaf node, we've got a matching path:
      if ((currSum == target) && isLeaf(curr))
        return true;

      // Else, if there is a valid right subtree which has not been visited
      // before, traverse it down. The expression "(prev != curr->right)" means
      // that 'curr' has a right child and it was not visited yet.
      if ((curr->right != nullptr) && (prev != curr->right))
        curr = curr->right;
      // Else, 'curr' node is a leaf node, but its path sum do not match the
      // target value, so update the 'prev' reference to point to 'curr', and
      // remove its value from the current path sum:
      else {
        prev = curr;
        st.pop();
        currSum -= curr->val;
        curr = nullptr;
      }
    }

    return false;
  }
};

int main() {
  std::cout << std::boolalpha;

  TreeNode *root = nullptr;

  root = insertNode(root, 3);

  root = insertNode(root, -9);
  root = insertNode(root, 20);

  root = insertNode(root, 0);
  root = insertNode(root, 7);
  root = insertNode(root, 93);
  root = insertNode(root, 2);

  int target{};
  bool hasPath{false};

  target = 116;
  hasPath = Solution::hasPathSumDFS_rec(root, target, 0);
  std::cout << "[rec] Tree has a path root->leaf which sum to " << target << ": " << hasPath << "\n"; // true
  hasPath = Solution::hasPathSumDFS_ite(root, target);
  std::cout << "[ite] Tree has a path root->leaf which sum to " << target << ": " << hasPath << "\n"; // true

  target = -4;
  hasPath = Solution::hasPathSumDFS_rec(root, target, 0);
  std::cout << "[rec] Tree has a path root->leaf which sum to " << target << ": " << hasPath << "\n"; // true
  hasPath = Solution::hasPathSumDFS_ite(root, target);
  std::cout << "[ite] Tree has a path root->leaf which sum to " << target << ": " << hasPath << "\n"; // true

  target = 5;
  hasPath = Solution::hasPathSumDFS_rec(root, target, 0);
  std::cout << "[rec] Tree has a path root->leaf which sum to " << target << ": " << hasPath << "\n"; // false
  hasPath = Solution::hasPathSumDFS_ite(root, target);
  std::cout << "[ite] Tree has a path root->leaf which sum to " << target << ": " << hasPath << "\n"; // false

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