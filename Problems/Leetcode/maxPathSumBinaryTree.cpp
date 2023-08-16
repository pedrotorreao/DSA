/*********************************************************************************************/
/* Problem: LC 124. Binary Tree Maximum Path Sum ********/
/*********************************************************************************************/
/*
--Problem statement:
  A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the
  sequence has an edge connecting them. A node can only appear in the sequence at most once.
  Note that the path does not need to pass through the root.
  The path sum of a path is the sum of the node's values in the path.
  Given the root of a binary tree, return the maximum path sum of any non-empty path.

  > Example 1:
    Input: root = [1,2,3]
    Output: 6
    Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

  > Example 2:
    Input: root = [-10,9,20,null,null,15,7]
    Output: 42
    Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

--Inputs:
  -TreeNode*: the root of a binary tree.

--Output:
  -int: maximum path sum of any non-empty path

--Constraints:
  :: The number of nodes in the tree is in the range [1, 3 * 104].
  :: -1000 <= Node.val <= 1000

--Reasoning: See comments below.

--Time complexity: O(N), where N is the number of nodes in the tree.

--Space complexity: O(1), no additional input dependent space is allocated.

*/

#include <iostream>
#include <limits>
#include <vector>

/* *
 * Definition for a binary tree node.
 * */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTreeMaxPathSum {
public:
  static int maxPathSum(TreeNode *root) {
    int max_path_sum = std::numeric_limits<int>::min();

    // cast to void is not needed, but since this is a non-void function, casting to void
    // shows that we're aware of the return value and chose to not use it:
    static_cast<void>(maxPathSum_helper(root, max_path_sum));

    return max_path_sum;
  }

  static int maxPathSum_helper(TreeNode *root, int &max_path_sum) {
    if (!root)
      return 0;

    int sum_l = std::max(maxPathSum_helper(root->left, max_path_sum), // sum of only the left path
                         0                                            // ignore left path sum if negative
    );
    int sum_r = std::max(maxPathSum_helper(root->right, max_path_sum), // sum of only the right path
                         0                                             // ignore right path sum if negative
    );

    // we can only include both left and right children (split path) alongside the subtree' root once, this subtree
    // will then be a path in itself as adding predecessors would invalidate the path since we'd need to traverse
    // the same node more than once:
    int sum_subtree = root->val + sum_l + sum_r; // sum of subtree (i.e. w/ split)

    // update max path sum if a better path is found:
    max_path_sum = std::max(sum_subtree, max_path_sum);

    // in order to backtrack including predecessors (no split path), we have to choose between the left and right
    // child' paths, we then choose the one with the greatest path sum:
    return (root->val + std::max(sum_l, sum_r));
  }
};

int main() {
  TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3));

  std::cout << "Binary Tree Max. path sum: " << BinaryTreeMaxPathSum::maxPathSum(root) << "\n\n";

  delete root;

  root = new TreeNode(-10);
  TreeNode *l_subtree = new TreeNode(9);
  TreeNode *r_subtree = new TreeNode(20, new TreeNode(15), new TreeNode(7));
  root->left = l_subtree;
  root->right = r_subtree;

  std::cout << "Binary Tree Max. path sum: " << BinaryTreeMaxPathSum::maxPathSum(root) << "\n\n";

  return 0;
}