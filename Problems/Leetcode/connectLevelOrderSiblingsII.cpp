/* * * * * * * * * * * * * * * * * *
Problem: LC 117. Populating Next Right Pointers in Each Node II

--Problem statement:
Given a binary tree
  struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
  }
Populate each next pointer to point to its next right node. If there is no next right node, the
next pointer should be set to NULL. Initially, all next pointers are set to NULL.

  > Example 1:
    Input: root = [1,2,3,4,5,null,7]
    Output: [1,#,2,3,#,4,5,7,#]
    Explanation: Given the above binary tree (Figure A), your function should populate each next
    pointer to point to its next right node, just like in Figure B. The serialized output is in level
    order as connected by the next pointerswith '#' signifying the end of each level.

  > Example 2:
    Input: root = []
    Output: []

--Constraints:
    :: The number of nodes in the tree is in the range [0, 6000].
    :: -100 <= Node.val <= 100

--Inputs:
  -TreeNode*: root of a binary tree.

--Output:
  -TreeNode*: root of the modified binary tree.

--Reasoning: Use level order traversal.

--Time complexity:
  O(N), where N is the total number of nodes in the tree, since we must traverse each node on
  the tree.

--Space complexity:
  O(N), where N is the total number of nodes in the tree, since we need O(N) space for the queue
  (even, though it will at most contain N/2 elements simultaneosly).
* * * * * * * * * * * * * * * * * */
#include <iostream>
#include <queue>
#include <vector>

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    // return null if tree is empty:
    if (root == nullptr)
      return nullptr;

    std::queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
      int currentLevelSize = q.size();

      for (int i{0}; i < currentLevelSize; ++i) {
        Node *curr = q.front();
        q.pop();

        // if there are still nodes left in the current level, connect the
        // current node' next pointer to the next node in the level; otherwise,
        // curr->next should be nullptr:
        curr->next = (i < currentLevelSize - 1) ? q.front() : nullptr;

        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);
      }
    }

    return root;
  }
};

int main() {
  /*
    -> test the solution: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
  */
}