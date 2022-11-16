/*********************************************************************************************/
/* Problem: LC 104. Maximum Depth of Binary Tree ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given the root of a binary tree, return its maximum depth. A binary tree's maximum depth is
  the number of nodes along the longest path from the root node down to the farthest leaf node.

  > Example 1:
  Input: root = [3,9,20,null,null,15,7]
  Output: 3

  > Example 2:
  Input: root = [1,null,2]
  Output: 2

--Input:
  TreeNode*: root of a binary tree.

--Output:
  int: the maximum depth of the binary tree passed in as argument.

--Constraints:
  :: The number of nodes in the tree is in the range [0, 104].
  :: -100 <= Node.val <= 100

--Reasoning: See comments below.

*/

#include <iostream>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Approach #1 - recursive DFS:
--Time complexity:
  O(N), where N is the size of the array.
--Space complexity:
  O(N), even though memory is not being allocated directly inside the algorithm, there is
  memory being allocated from the stack memory consumed to keep track of the recursive
  function calls. This automatic stack memory allocation may become a problem if the
  binary tree being traversed is too large, as the stack may run out of memory.
*/

int maxDepth_rec(TreeNode *root) {
  if (!root)
    return 0;

  int l_h = 1 + maxDepth_rec(root->left);
  int l_r = 1 + maxDepth_rec(root->right);

  return std::max(l_h, l_r);
}

/* Approach #2 - iterative BFS:
--Time complexity:
  O(N), where N is the size of the array.
--Space complexity:
  O(N), memory is being allocated for the priority queue.
*/
int maxDepth_ite(TreeNode *root) {
  if (!root)
    return 0;

  std::queue<TreeNode *> q;
  q.push(root);
  int max_depth{0};

  while (!q.empty()) {
    int nodes_curr_level = q.size();

    for (int node_i{0}; node_i < nodes_curr_level; ++node_i) {
      TreeNode *curr_node = q.front();
      q.pop();

      if (curr_node->left)
        q.push(curr_node->left);
      if (curr_node->right)
        q.push(curr_node->right);
    }

    ++max_depth;
  }

  return max_depth;
}

int main() {
  TreeNode *n1 = new TreeNode(1);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(4);
  TreeNode *n5 = new TreeNode(5);
  TreeNode *n6 = new TreeNode(6);
  TreeNode *n7 = new TreeNode(7);

  n2->right = n1;
  n4->left = n3;
  n4->right = n2;
  n5->left = n4;
  n6->right = n7;
  n5->right = n6;

  std::cout << "Max depth (rec.): " << maxDepth_rec(n5) << "\n";
  std::cout << "Max depth (ite.): " << maxDepth_ite(n5) << "\n";

  n2->right = nullptr;

  std::cout << "Max depth (rec.): " << maxDepth_rec(n5) << "\n";
  std::cout << "Max depth (ite.): " << maxDepth_ite(n5) << "\n";

  n5->left = nullptr;
  n6->right = nullptr;

  std::cout << "Max depth (rec.): " << maxDepth_rec(n5) << "\n";
  std::cout << "Max depth (ite.): " << maxDepth_ite(n5) << "\n";
}