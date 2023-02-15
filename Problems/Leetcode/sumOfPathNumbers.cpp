/****************************************************************************************/
/* Problem: 129. Sum Root to Leaf Numbers  **********************************************/
/****************************************************************************************/
/*
--Problem statement:
  You are given the root of a binary tree containing digits from 0 to 9 only. Each
  root-to-leaf path in the tree represents a number.
  For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
  Return the total sum of all root-to-leaf numbers. Test cases are generated so that the
  answer will fit in a 32-bit integer.

  A leaf node is a node with no children.

  > Example 1:
  Input: root = [1,2,3]
  Output: 25
  Explanation:
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.
    Therefore, sum = 12 + 13 = 25.

  > Example 2:
  Input: root = [4,9,0,5,1]
  Output: 1026
  Explanation:
    The root-to-leaf path 4->9->5 represents the number 495.
    The root-to-leaf path 4->9->1 represents the number 491.
    The root-to-leaf path 4->0 represents the number 40.
    Therefore, sum = 495 + 491 + 40 = 1026.

--Inputs:
  -TreeNode*: root of a binary tree.

--Output:
  -int: sum of all root-to-leaf numbers

--Constraints:
  :: The number of nodes in the tree is in the range [1, 1000].
  :: 0 <= Node.val <= 9
  :: The depth of the tree will not exceed 10.

--Reasoning: See comments below.
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

TreeNode *insertNode(TreeNode *root, int val);

class Solution {
public:
  /*  Approach #1 - Recursive DFS - naive approach:
    --Time complexity:
    O(N^2), if we consider the fact that for every leaf node, we might have to store its path, by
    making a copy of the current path, that takes O(N), which will then amount a total time complexity
    of O(N^2).

    --Space complexity:
    O(N^2) in the worst case, for storing all the leaf nodes paths.
  */
  int sumOfAllPaths_1(TreeNode *root) {
    std::vector<std::vector<int>> paths;
    std::vector<int> curr;

    getAllPaths_DFS_1(root, paths, curr);

    int sum{0}, mult{1};

    // iterate over all root->to->leaf paths, computing the sum for each one of them:
    for (int i{0}; i < paths.size(); ++i) {
      for (int j = paths.at(i).size() - 1; j >= 0; --j) {
        sum += paths.at(i).at(j) * mult;
        mult *= 10;
      }
      mult = 1;
    }

    return sum;
  }

  /*  Approach #2 - Recursive DFS - optimized approach:
    --Time complexity:
    O(N), where N is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

    --Space complexity:
    O(N) in the worst case, where this space will be used to store the recursion stack.
  */
  int sumOfAllPaths_2(TreeNode *root) {
    if (root == nullptr)
      return 0;

    return getAllPaths_DFS_2(root, 0);
  }

  /* Approach #3 - Iterative DFS - preorder:
    --Time complexity:
    O(N), where N is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

    --Space complexity:
    O(N) in the worst case, where this space will be used to store the recursion stack, if the tree is completely
    skewed.
  */
  int sumOfAllPaths_3(TreeNode *root) {
    if (root == nullptr)
      return 0;

    std::stack<std::pair<TreeNode *, int>> st; // {current node, current sum}
    st.push({root, 0});

    int sum{0};

    while (!st.empty()) {
      // structured bindings only available with c++ 17 or greater
      auto [node, currSum] = st.top();
      st.pop();

      currSum = (currSum * 10) + node->val;

      if (isLeaf(node)) { // reached a leaf node, add path sum to the total:
        sum += currSum;
        continue;
      }

      if (node->right != nullptr)
        st.push({node->right, currSum});
      if (node->left != nullptr)
        st.push({node->left, currSum});
    }

    return sum;
  }

  /* Approach #4 - Iterative BFS:
    --Time complexity:
    O(N), where N is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

    --Space complexity:
    O(N), atmost (N+1)/2 elements will be stored in queue in case of complete binary tree.
  */
  int sumOfAllPaths_4(TreeNode *root) {
    if (root == nullptr)
      return 0;

    std::queue<std::pair<TreeNode *, int>> q; // {current node, current sum}
    q.push({root, 0});

    int sum{0};

    while (!q.empty()) {
      // structured bindings only available with c++ 17 or greater:
      auto [node, currSum] = q.front();
      q.pop();

      currSum = (currSum * 10) + node->val;

      if (isLeaf(node)) { // reached a leaf node, add path sum to the total:
        sum += currSum;
        continue;
      }

      if (node->right != nullptr)
        q.push({node->right, currSum});
      if (node->left != nullptr)
        q.push({node->left, currSum});
    }

    return sum;
  }

private:
  void getAllPaths_DFS_1(TreeNode *root, std::vector<std::vector<int>> &allPaths, std::vector<int> &currPath) {
    if (root == nullptr)
      return;

    currPath.push_back(root->val);

    if (isLeaf(root))
      allPaths.push_back(currPath);

    getAllPaths_DFS_1(root->left, allPaths, currPath);
    getAllPaths_DFS_1(root->right, allPaths, currPath);

    currPath.pop_back();
  }

  int getAllPaths_DFS_2(TreeNode *root, int currSum) {
    if (root == nullptr)
      return 0;

    // calculate the path sum for the current node:
    currSum = 10 * currSum + (root->val);

    // return the current path sum in case we've reached a leaf node:
    if (isLeaf(root))
      return currSum;

    // traverse subtrees:
    return (getAllPaths_DFS_2(root->left, currSum) + getAllPaths_DFS_2(root->right, currSum));
  }

  bool isLeaf(TreeNode *node) {
    return (node->left == nullptr && node->right == nullptr);
  }
};

int main() {
  TreeNode *root = nullptr;

  root = new TreeNode(1);
  root->left = new TreeNode(7);
  root->right = new TreeNode(9);
  root->right->left = new TreeNode(2);
  root->right->right = new TreeNode(9);

  Solution sol;
  int sumAllPaths{0};

  sumAllPaths = sol.sumOfAllPaths_1(root);
  std::cout << "Sum of all paths in the binary tree: " << sumAllPaths << "\n";
  sumAllPaths = sol.sumOfAllPaths_2(root);
  std::cout << "Sum of all paths in the binary tree: " << sumAllPaths << "\n";
  sumAllPaths = sol.sumOfAllPaths_3(root);
  std::cout << "Sum of all paths in the binary tree: " << sumAllPaths << "\n";
  sumAllPaths = sol.sumOfAllPaths_4(root);
  std::cout << "Sum of all paths in the binary tree: " << sumAllPaths << "\n";
  std::cout << "\n";

  root = nullptr;
  root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->left->right = new TreeNode(1);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  sumAllPaths = sol.sumOfAllPaths_1(root);
  std::cout << "Sum of all paths in the binary tree: " << sumAllPaths << "\n";
  sumAllPaths = sol.sumOfAllPaths_2(root);
  std::cout << "Sum of all paths in the binary tree: " << sumAllPaths << "\n";
  sumAllPaths = sol.sumOfAllPaths_3(root);
  std::cout << "Sum of all paths in the binary tree: " << sumAllPaths << "\n";
  sumAllPaths = sol.sumOfAllPaths_4(root);
  std::cout << "Sum of all paths in the binary tree: " << sumAllPaths << "\n";
  std::cout << "\n";

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