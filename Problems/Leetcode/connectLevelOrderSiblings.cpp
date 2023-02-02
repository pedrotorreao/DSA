/****************************************************************************************/
/* Problem: 116. Populating Next Right Pointers in Each Node  ***************************/
/****************************************************************************************/
/*
--Problem statement:
  You are given a perfect binary tree where all leaves are on the same level, and every
  parent has two children. The binary tree has the following definition:

    struct Node {
      int val;
      Node *left;
      Node *right;
      Node *next;
    }

  Populate each next pointer to point to its next right node. If there is no next right node,
  the next pointer should be set to NULL.
  Initially, all next pointers are set to NULL.

  > Example 1:
  Input: root = [1,2,3,4,5,6,7]
  Output: [1,#,2,3,#,4,5,6,7,#]
  Explanation:
    Given the above perfect binary tree (Figure A), your function should populate each next
    pointer to point to its next right node, just like in Figure B. The serialized output is
    in level order as connected by the next pointers, with '#' signifying the end of each level.

  > Example 2:
  Input: root = []
  Output: []

--Inputs:
  -TreeNode*: root of a binary tree.

--Output:
  -TreeNode*: root of the modified binary tree.

--Constraints:
  :: The number of nodes in the tree is in the range [0, 212 - 1].
  :: -1000 <= Node.val <= 1000

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
void display2D(const std::vector<std::vector<T>> &mat);

template <typename T>
void display1D(const std::vector<T> &mat);

TreeNode *insertNode(TreeNode *root, int newVal);
void customTraversal(TreeNode *root);

class Solution {
public:
  static TreeNode *connectLevelOrderSiblings_1(TreeNode *root) {
    // if the tree is empty, return NULL:
    if (root == nullptr)
      return root;

    // queue for storing node neighbors:
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      // number of elements on the current tree level:
      int nodesAtCurrLevel = q.size();
      // traverse all the nodes, "nodesAtCurrLevel", on the current level:
      for (int node{0}; node < nodesAtCurrLevel; ++node) {
        TreeNode *curr = q.front();
        q.pop();

        // if "curr" is the last node of the current tree' level, its "next"
        // pointer should point to NULL:
        if (node + 1 < nodesAtCurrLevel)
          curr->next = q.front();
        // otherwise, it should point to its right sibling, "q.front()":
        else
          curr->next = nullptr;

        // add "curr" children to the queue, if they exist:
        if (curr->left != nullptr)
          q.push(curr->left);

        if (curr->right != nullptr)
          q.push(curr->right);
      }
    }

    return root;
  }

  static TreeNode *connectLevelOrderSiblings_2(TreeNode *root) {
    // if the tree is empty, return NULL:
    if (root == nullptr)
      return root;
    // queue for storing node neighbors:
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      // remember the previous node to connect it with the current node:
      TreeNode *prev = nullptr;
      // number of elements on the current tree level:
      int nodesAtCurrLevel = q.size();
      // traverse all the nodes, "nodesAtCurrLevel", on the current level:
      for (int node{0}; node < nodesAtCurrLevel; ++node) {
        TreeNode *curr = q.front();
        q.pop();

        if (prev != nullptr)
          prev->next = curr;
        prev = curr;

        // add "curr" children to the queue, if they exist:
        if (curr->left != nullptr)
          q.push(curr->left);

        if (curr->right != nullptr)
          q.push(curr->right);
      }
    }

    return root;
  }

  static TreeNode *connectLevelOrderSiblings_3(TreeNode *root) {
    if (root == nullptr)
      return root;

    std::queue<TreeNode *> q;
    q.push(root);

    // we are performing right-to-left BFS, starting at the rightmost node of each level,
    // we then set the 'next' node of 'curr' as 'rightNode' and update "rightNode = cur".
    // this ensures that each node is assigned its 'rightNode' properly while traversing
    // from right to left:
    while (!q.empty()) {
      TreeNode *rightNode = nullptr;
      int nodesAtCurrLevel = q.size();

      // traverse all the nodes, "nodesAtCurrLevel", on the current level:
      for (int node{0}; node < nodesAtCurrLevel; ++node) {
        TreeNode *curr = q.front();
        q.pop();

        curr->next = rightNode;
        rightNode = curr;

        // add "curr" children to the queue, if they exist:
        if (curr->right)
          q.push(curr->right);
        if (curr->left)
          q.push(curr->left);
      }
    }

    return root;
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

  root = Solution::connectLevelOrderSiblings_3(root);
  // traverse the tree and print out its content:
  customTraversal(root);
  std::cout << "\n";

  root = nullptr;

  root = insertNode(root, 3);

  root = insertNode(root, -9);
  root = insertNode(root, 20);

  root = insertNode(root, 0);
  root = insertNode(root, 7);
  root = insertNode(root, 93);
  root = insertNode(root, 2);

  root = Solution::connectLevelOrderSiblings_2(root);
  // traverse the tree and print out its content:

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

// helpers - traversal:
void customTraversal(TreeNode *root) {
  if (root != nullptr) {
    std::cout << root->val << "  ";
    if (root->next)
      std::cout << root->next->val << "  ";
    else
      std::cout << "NIL   ";
    customTraversal(root->left);
    customTraversal(root->right);
    // customTraversal(root->next);
  }
  // else
  //   std::cout << " NIL \n";
}