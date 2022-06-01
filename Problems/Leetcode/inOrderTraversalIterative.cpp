/*********************************************************************************************/
/* Problem: Binary Tree Inorder Traversal (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given the root of a binary tree, return the inorder traversal of its nodes' values.

  > Example 1:
    Input: root = [1,null,2,3]
    Output: [1,3,2]
        1
         \
          2
        /
      3

  > Example 2:
    Input: root = []
    Output: []

  > Example 3:
    Input: root = [1]
    Output: [1]

--Inputs:
  -TreeNode *: pointer to the 'root' node of a binary tree

--Output:
  -std::vector<int>: inorder traversal of its nodes' values.

--Constraints:
    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
    Please note: binary tree != binary search tree

--Reasoning: See comments below.

--Time complexity: O(N), where N is the number of nodes

--Space complexity: O(N), due to the stack and hash set created, where N is the number of nodes.

*/

#include <iostream>
#include <stack>
#include <unordered_set>
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

std::vector<int> inorderTravIteratively(TreeNode *root) {
  // use a stack to add the nodes that will be processed later while backtracking:
  std::stack<TreeNode *> st;
  // use a hash set to keep track of the nodes traversed (added to the result array):
  std::unordered_set<TreeNode *> hs;
  // result array:
  std::vector<int> res;

  // tree is empty, return empty array:
  if (root == nullptr)
    return res;

  // add root node to the stack:
  st.push(root);

  // pointer to the current node being visited:
  TreeNode *curr = root;

  // iterate while the stack still has nodes to be processed:
  while (!st.empty()) {
    // go as deep as possible into the left subtree if there is a
    // left child and if it has not been traversed yet:
    if (curr->left != nullptr && hs.count(curr->left) == 0) {
      // traverse the left child's subtree:
      curr = curr->left;
      // add it to the stack so we can backtrack later:
      st.push(curr);
    }
    // since there's no left child, add the root' value to the result
    // and traverse the right child's subtree:
    //(Remember - inOrder: left child --> root --> right child)
    else if (curr->right != nullptr && hs.count(curr->right) == 0) {
      // add current subtree root to the result:
      res.push_back(curr->val);
      // add it to the set to mark it as visited:
      hs.insert(curr);
      // traverse the right child's subtree:
      curr = curr->right;
      // add it to the stack so we can backtrack later:
      st.push(curr);
    }
    // since current node has no children, it is a leaf node:
    // -- add it to the result and mark it as visited
    // -- pop it from the stack since it's been traversed
    // -- backtrack to be able to traverse unvisited nodes
    else {
      // if node has not been traversed yet:
      if (hs.count(curr) == 0) {
        // add it to the result:
        res.push_back(curr->val);
        // mark it as visited:
        hs.insert(curr);
      }
      // pop 'curr' node from the stack, since 'curr' has been visited already:
      st.pop();
      // if there are still nodes to be traversed, backtrack:
      if (!st.empty())
        curr = st.top();
    }
  }

  return res;
}

void inOrderTravRecursively(const TreeNode *root);
void displayTraversalVec(const std::vector<int> &vec);

int main() {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  std::cout << "In order traversal - recursive: ";
  inOrderTravRecursively(root);
  std::cout << "\n";
  std::cout << "In order traversal - iterative: ";
  displayTraversalVec(inorderTravIteratively(root));

  return 0;
}

void inOrderTravRecursively(const TreeNode *root) {
  if (root != nullptr) {
    inOrderTravRecursively(root->left);
    std::cout << root->val << "  ";
    inOrderTravRecursively(root->right);
  }
}

void displayTraversalVec(const std::vector<int> &vec) {
  for (const auto &v : vec) {
    std::cout << v << "  ";
  }
  std::cout << "\n";
}