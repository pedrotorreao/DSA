/****************************************************************************************/
/* Problem: ???. Path With Given Sequence  **********************************************/
/****************************************************************************************/
/*
--Problem statement:
  Given a binary tree and a number sequence, find if the sequence is present as a
  root-to-leaf path in the given tree.

  A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf
  is a node with no children.

  > Example 1:
  Binary Tree:
        (1)
      /			\
    (7)      (9)
            /		\
          (2) 	(9)
  Input: sequence = [1,9,9]
  Output: true
  Explanation:
    The tree has a path 1->9->9

  > Example 2:
          (1)
        /     \
      (0)      (1)
        \			/		\
        (1)	(6)		(5)
  Input: sequence = [1,0,7]
  Output: false
  Explanation:
    The tree does not have a path 1->0->7


--Inputs:
  -TreeNode*: root of a binary tree.
  -int[]: sequence to be matched

--Output:
  -bool: whether there is a root-to-leaf path which matches the given sequence.

--Constraints:
  :: ?

--Reasoning: See comments below.

--Time complexity:
  O(N), where N is the total number of nodes in the tree, since, in the worst scenario, we'll
  need to visit each node of the tree.

--Space complexity:
  O(N) in the worst case, where N is the total number of nodes in the tree. This is due to the storage
  required for the recursion stack. In the worst case, the tree is completely skewed and has the structure
  of a linked list.
*/

#include <iostream>
#include <queue>
#include <stack>
#include <utility>
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

class Solution {
public:
  bool isSequencePresentInTreePath(TreeNode *root, std::vector<int> &sequence) {
    if (root == nullptr || sequence.empty())
      return false;

    return sequenceSearch_DFS(root, sequence, 0);
  }

private:
  bool sequenceSearch_DFS(TreeNode *node, std::vector<int> &sequence, int idx) {
    // Base cases:
    // a.) the sequence is smaller than the path, so the sequence does not cover root-to-leaf:
    if (node == nullptr)
      return false;
    // b.) there is a mismatch between the path and the sequence:
    if (node->val != sequence.at(idx) || idx >= sequence.size())
      return false;
    // c.) current node is a leaf and we've got to the end of the sequence, e.g. sequence covers
    // path root-to-leaf:
    if (isLeaf(node) && (idx == sequence.size() - 1))
      return true;

    // advance in the sequence:
    ++idx;
    // recurse for current' node subtrees:
    return sequenceSearch_DFS(node->left, sequence, idx) || sequenceSearch_DFS(node->right, sequence, idx);
  }

  // check if a given node is a leaf node:
  bool isLeaf(TreeNode *node) {
    return (node->left == nullptr && node->right == nullptr);
  }
};

int main() {
  std::cout << std::boolalpha;

  TreeNode *root = nullptr;
  bool hasSequence{false};
  std::vector<int> sequence;
  Solution s;

  /*	-- Example #1:
        (1)
      /			\
    (7)      (9)
            /		\
          (2) 	(9)
  */
  root = new TreeNode(1);
  root->left = new TreeNode(7);
  root->right = new TreeNode(9);
  root->right->left = new TreeNode(2);
  root->right->right = new TreeNode(9);
  sequence = {1, 9, 9};
  hasSequence = s.isSequencePresentInTreePath(root, sequence);
  std::cout << "Sequence is present: " << hasSequence << "\n"; // true
  sequence = {1, 9, 2};
  hasSequence = s.isSequencePresentInTreePath(root, sequence);
  std::cout << "Sequence is present: " << hasSequence << "\n"; // true

  root = nullptr;

  /*	-- Example #2:
          (1)
        /     \
      (0)      (1)
        \			/		\
        (1)	(6)		(5)
  */
  root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->left->right = new TreeNode(1);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);
  sequence = {1, 0, 7};
  hasSequence = s.isSequencePresentInTreePath(root, sequence);
  std::cout << "Sequence is present: " << hasSequence << "\n"; // false
  sequence = {1, 1, 6};
  hasSequence = s.isSequencePresentInTreePath(root, sequence);
  std::cout << "Sequence is present: " << hasSequence << "\n"; // true
  sequence = {1, 0, 1};
  hasSequence = s.isSequencePresentInTreePath(root, sequence);
  std::cout << "Sequence is present: " << hasSequence << "\n"; // true

  return 0;
}