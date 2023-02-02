/****************************************************************************************/
/* Problem: xyz. Connect All Level Order Siblings  **************************************/
/****************************************************************************************/
/*
--Problem statement:
  Given a binary tree, connect each node with its level order successor. The last node of each
  level should point to the first node of the next level.

--Inputs:
  -TreeNode*: root of a binary tree.

--Output:
  -TreeNode*: root of the modified binary tree.

--Constraints:
  :: The number of nodes in the tree is in the range [0, 212 - 1].
  :: -1000 <= Node.val <= 1000

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
  /*
  --Time complexity:
    O(N), where N is the total number of nodes in the tree, since we must traverse each node on
    the tree.

  --Space complexity:
    O(N), where N is the total number of nodes in the tree, since we need O(N) space for the queue
    (even, though it will at most contain N/2 elements simultaneosly).
  */
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

        // add "curr" children to the queue, if they exist:
        if (curr->left != nullptr)
          q.push(curr->left);

        if (curr->right != nullptr)
          q.push(curr->right);

        // if "curr" is the last node of the current tree' level, its "next"
        // pointer should point to its successor:
        if (!q.empty())
          curr->next = q.front();
        // otherwise, if it's the last node in the tree, it should point to "NULL":
        else
          curr->next = nullptr;
      }
    }

    return root;
  }

  /*
  --Time complexity:
    O(N), where N is the total number of nodes in the tree, since we must traverse each node on
    the tree.

  --Space complexity:
    O(N), where N is the total number of nodes in the tree, since we need O(N) space for the queue
    (even, though it will at most contain N/2 elements simultaneosly).
  */
  static TreeNode *connectLevelOrderSiblings_2(TreeNode *root) {
    // if the tree is empty, return NULL:
    if (root == nullptr)
      return root;

    // queue for storing node neighbors:
    std::queue<TreeNode *> q;
    q.push(root);

    // we'll perform a BFS approach and, while traversing the tree, we will
    // remember (irrespective of the level) the previous node, 'prev', to connect
    // it with the current node.
    TreeNode *curr = nullptr, *prev = nullptr;

    while (!q.empty()) {
      curr = q.front();
      q.pop();

      // add "curr" children to the queue, if they exist:
      if (curr->left != nullptr)
        q.push(curr->left);

      if (curr->right != nullptr)
        q.push(curr->right);

      if (prev != nullptr)
        prev->next = curr;
      prev = curr;
    }

    return root;
  }

  /*
  --Time complexity:
    O(N), where N is the total number of nodes in the tree, since we must traverse each node on
    the tree.

  --Space complexity:
    O(1), no additional input dependent space is allocated.
  */
  static TreeNode *connectLevelOrderSiblings_3(TreeNode *root) {
    // after we connect all the siblings, a "linked-list-like" structure is formed whose
    // 'head' is the root node. Keep two pointers 'curr' and 'prev', 'curr' is the node
    // we are the moment in the traversal and 'prev' is the last node in the "linked-list-like"
    // structure already constructed (i.e. siblings already connected). Steps for connecting
    // all siblings in the tree:

    //
    //   2.2 If current node has a right child, append this right node to the last and make it 'prev' node.
    //   update current node to current's next node

    // if the tree is empty, return NULL:
    if (root == nullptr)
      return root;

    //  1. Initially set both 'curr' and 'prev' as 'root'
    TreeNode *curr = root, *prev = root;
    //  2. while 'curr' node is not null:
    while (curr != nullptr) {
      //  2.1 if 'curr' node has a left child, append this left node to the 'prev'
      // and make it 'prev' node:
      if (curr->left != nullptr) {
        prev->next = curr->left;
        prev = curr->left;
      }
      //  2.2 if 'curr' node has a right child, append this right node to the 'prev'
      // and make it 'prev' node:
      if (curr->right != nullptr) {
        prev->next = curr->right;
        prev = curr->right;
      }
      //  2.3 update 'curr' node to 'curr''s next node:
      prev->next = nullptr;
      curr = curr->next;
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

  root = Solution::connectLevelOrderSiblings_3(root);
  // traverse the tree and print out its content:
  customTraversal(root);
  std::cout << "\n";

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
  TreeNode *curr = root;

  while (curr) {
    std::cout << curr->val << "  ";

    curr = curr->next;
  }

  std::cout << "\n";
}