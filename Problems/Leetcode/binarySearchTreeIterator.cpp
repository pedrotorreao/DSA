/***
Problem: LC 173. Binary Search Tree Iterator
(https://leetcode.com/problems/binary-search-tree-iterator/description/)

--Problem statement:
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search
tree (BST):
    - 'BSTIterator(TreeNode root)': Initializes an object of the 'BSTIterator' class. The root of the BST is
    given as part of the constructor. The pointer should be initialized to a non-existent number smaller
    than any element in the BST.
    - boolean 'hasNext()': Returns true if there exists a number in the traversal to the right of the pointer,
    otherwise returns false.
    - 'int next()': Moves the pointer to the right, then returns the number at the pointer.

Notice that by initializing the pointer to a non-existent smallest number, the first call to 'next()' will
return the smallest element in the BST.

You may assume that 'next()' calls will always be valid. That is, there will be at least a next number in the
in-order traversal when 'next()' is called.

  > Example 1:
      Input:
        ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
        [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
      Output:
        [null, 3, 7, true, 9, true, 15, true, 20, false]
      Explanation:
        BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
        bSTIterator.next();    // return 3
        bSTIterator.next();    // return 7
        bSTIterator.hasNext(); // return True
        bSTIterator.next();    // return 9
        bSTIterator.hasNext(); // return True
        bSTIterator.next();    // return 15
        bSTIterator.hasNext(); // return True
        bSTIterator.next();    // return 20
        bSTIterator.hasNext(); // return False


Follow up:
    Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the
    height of the tree?

--Inputs:
    TreeNode *: the root of a binary search tree.

--Output:
    bool: output of calling 'hasNext', whether there are still nodes to be traversed in the BST.
    int: next node value, output of calling 'next'.

--Constraints:
    :: The number of nodes in the tree is in the range [1, 10^5].
    :: 0 <= Node.val <= 10^6
    :: At most 10^5 calls will be made to 'hasNext', and 'next'.

--Reasoning: see the comments below.

--Time complexity:
    > hasNext: O(1).
    > next: O(1).

--Space complexity:
    O(h), due to storing the current branch' nodes in the stack, where 'h' is the height of the tree
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

class BSTIterator {
  // stack for holding the next 'h' nodes in the current
  // branch of the tree. the top of the stack will be the
  // deepest node in the current path of the tree, i.e. the
  // the lowest value on the current branch:
  std::stack<TreeNode *> st;

public:
  BSTIterator(TreeNode *root) {
    traverseLeft(root);
  }

  // in case there are still nodes to be processed in the stack, pop
  // the top node (lowest) and traverse its right path to add the next
  // nodes that should be processed (in order traversal) to the stack:
  int next() {
    if (hasNext()) {
      TreeNode *n = st.top();
      st.pop();

      traverseLeft(n->right);

      return n->val;
    }
    return -1;
  }

  // return whether there are still nodes to be processed in the stack: - O(1):
  bool hasNext() {
    return !st.empty();
  }

  // add the next 'h' nodes in the current  branch of the tree
  // to the stack to be processed later - O(h):
  void traverseLeft(TreeNode *node) {
    while (node != nullptr) {
      st.push(node);
      node = node->left;
    }
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
  // test cases ..

  return 0;
}