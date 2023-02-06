/****************************************************************************************/
/* Problem: 199. Binary Tree Right Side View  ***************************/
/****************************************************************************************/
/*
--Problem statement:
  Given the root of a binary tree, imagine yourself standing on the right side of it,
  return the nodes you can see ordered from top to bottom.

  > Example 1:
  Input: root = [1,2,3,null,5,null,4]
  Output: [1,3,4]

  > Example 2:
  Input: root = [1,null,3]
  Output: [1,3]

  > Example 3:
  Input: root = []
  Output: []

--Inputs:
  -TreeNode*: root of a binary tree.

--Output:
  -TreeNode*[]: array containing the nodes in the tree' right side view.

--Constraints:
  :: The number of nodes in the tree is in the range [0, 100].
  :: -100 <= Node.val <= 100

--Reasoning: See comments below.

--Time complexity:
  O(N), where N is the total number of nodes in the tree, since we must traverse each node on
  the tree.

--Space complexity:
  O(N), where N is the total number of nodes in the tree, since we need O(N) space for the queue
  (even, though it will at most contain N/2 elements simultaneosly).
*/

#include <iostream>
#include <queue>
#include <vector>

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;

  TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}

  TreeNode(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  TreeNode(int _val, TreeNode *_left, TreeNode *_right, TreeNode *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

template <typename T>
void display1D(const std::vector<T> &mat);

TreeNode *insertNode(TreeNode *root, int newVal);

class Solution {
public:
  static std::vector<TreeNode *> treeRightSideView_1(TreeNode *root) {
    if (root == nullptr)
      return std::vector<TreeNode *>();

    // output array:
    std::vector<TreeNode *> rightSideView;

    // queue for storing the nodes in leve order:
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int nodesAtCurrLvl = q.size();

      // number of nodes at the current level:
      for (int node{0}; node < nodesAtCurrLvl; ++node) {
        TreeNode *curr = q.front();
        q.pop();

        // append the rightmost node to the result, i.e. the last node
        // of each level to the result array:
        if (node + 1 == nodesAtCurrLvl)
          rightSideView.push_back(curr);

        if (curr->left != nullptr)
          q.push(curr->left);
        if (curr->right != nullptr)
          q.push(curr->right);
      }
    }

    return rightSideView;
  }

  // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
  // DFS Approach:
  static std::vector<TreeNode *> treeRightSideView_2(TreeNode *root) {
    // output array:
    std::vector<TreeNode *> rightSideView;
    // dfs:
    rightView(root, rightSideView, 0);

    return rightSideView;
  }

  static void rightView(TreeNode *root, std::vector<TreeNode *> &view, int level) {
    if (root == nullptr)
      return;

    // Each level has exactly 1 rightmost node, so once that node is added to the
    // result, there are no more nodes to be added on that level. If we traverse the
    // tree "right->left", we add current node' right child first (in case there is
    // one) to the result array and its size will grow by 1, which will be then
    // greater than the value of "level". Then, when we visit the left child,
    // "view.size() > level", and the node is not added.
    if (view.size() == level)
      view.push_back(root);

    rightView(root->right, view, level + 1);
    rightView(root->left, view, level + 1);
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

  std::vector<TreeNode *> rightSideView = Solution::treeRightSideView_2(root);
  // traverse the tree and print out its content:
  display1D<TreeNode *>(rightSideView);
  std::cout << "\n";

  root = nullptr;

  root = insertNode(root, 3);

  root = insertNode(root, -9);
  root = insertNode(root, 20);

  root = insertNode(root, 0);
  root = insertNode(root, 7);
  root = insertNode(root, 93);
  root = insertNode(root, 2);

  rightSideView = Solution::treeRightSideView_2(root);
  // traverse the tree and print out its content:
  display1D<TreeNode *>(rightSideView);
  std::cout << "\n";

  root = nullptr;

  root = insertNode(root, 9);

  root = insertNode(root, 5);
  root = insertNode(root, 21);

  root = insertNode(root, 2);
  root = insertNode(root, 7);
  root = insertNode(root, 17);

  root = insertNode(root, 0);
  root = insertNode(root, 3);
  root = insertNode(root, 11);

  root = insertNode(root, -5);
  root = insertNode(root, 1);
  root = insertNode(root, 4);

  root = insertNode(root, -12);
  root = insertNode(root, -3);

  root = insertNode(root, -23);

  rightSideView = Solution::treeRightSideView_2(root);
  // traverse the tree and print out its content:
  display1D<TreeNode *>(rightSideView);
  std::cout << "\n";

  return 0;
}

// helpers - displayers:
template <typename T>
void display1D(const std::vector<T> &mat) {
  std::cout << "[  ";
  for (auto &m : mat)
    std::cout << (*m).val << "  ";
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