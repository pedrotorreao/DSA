/****************************************************************************************/
/* Problem: 230. Kth Smallest Element in a BST  *****************************************/
/****************************************************************************************/
/*
--Problem statement:
  Given the root of a binary search tree, and an integer k, return the kth smallest value
  (1-indexed) of all the values of the nodes in the tree.

  > Example 1:
      Input: root = [3,1,4,null,2], k = 1
      Output: 1

  > Example 2:
      Input: root = [5,3,6,2,4,null,null,1], k = 3
      Output: 3

--Inputs:
  -TreeNode*: root of a binary tree.
  -int: k, indicating the kth smallest value to be returned.

--Output:
  -int: kth smallest value.

--Constraints:
  :: The number of nodes in the tree is n.
  :: 1 <= k <= n <= 104
  :: 0 <= Node.val <= 104

--Reasoning: Both solutions use some sort of in-order traversal approach.
*/

#include <iostream>
#include <limits>
#include <vector>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  ~TreeNode() = default;
};

/*
--Time complexity:
  O(N), where N is the number of nodes in the tree. If the tree is completely unbalanced with
  nodes added in decreasing order, we could possibly have to traverse the whole tree.

--Space complexity:
  O(N), for the worst case described above, we'd need to allocate space for all the node values.
*/
class Solution_1 {
public:
  static int kthSmallest(TreeNode *root, int k) {
    if (!root)
      return -1;

    int kth = k;
    std::vector<int> inOrderTrav{};
    inOrder(root, inOrderTrav, kth);

    return inOrderTrav.at(k - 1);
  }

  static void inOrder(TreeNode *root, std::vector<int> &tr, int &kth) {
    if (root && kth > 0) {
      inOrder(root->left, tr, kth);
      tr.push_back(root->val);
      --kth;
      inOrder(root->right, tr, kth);
    }
  }
};

/*
--Time complexity:
  O(N), where N is the number of nodes in the tree. If the tree is completely unbalanced with
  nodes added in decreasing order, we could possibly have to traverse the whole tree.

--Space complexity: O(1), no input dependent space needs to be allocated.
*/
class Solution_2 {
public:
  static int kthSmallest(TreeNode *root, int k) {
    if (!root)
      return -1;

    return inOrder(root, k);
  }

  static int inOrder(TreeNode *root, int &k) {
    if (root) {
      int kth = inOrder(root->left, k);

      if (!k)
        return kth;

      if (!--k)
        return root->val;

      return inOrder(root->right, k);
    }

    return std::numeric_limits<int>::max();
  }
};

int main() {
  TreeNode *n_0 = new TreeNode(5);
  TreeNode *n_1 = new TreeNode(3);
  TreeNode *n_2 = new TreeNode(6);
  TreeNode *n_3 = new TreeNode(2);
  TreeNode *n_4 = new TreeNode(4);
  TreeNode *n_5 = new TreeNode(1);

  n_0->left = n_1;
  n_0->right = n_2;

  n_1->left = n_3;
  n_1->right = n_4;

  n_3->left = n_5;

  int kthSmallest{0};

  kthSmallest = Solution_1::kthSmallest(n_0, 3);
  std::cout << "S1.TC1. kth smallest value on BST: " << kthSmallest << "\n";
  kthSmallest = Solution_2::kthSmallest(n_0, 3);
  std::cout << "S2.TC1. kth smallest value on BST: " << kthSmallest << "\n";

  delete n_0;
  delete n_1;
  delete n_2;
  delete n_3;
  delete n_4;
  delete n_5;

  n_0 = new TreeNode(3);
  n_1 = new TreeNode(1);
  n_2 = new TreeNode(4);
  n_3 = new TreeNode(2);

  n_0->left = n_1;
  n_0->right = n_2;
  n_1->right = n_3;

  kthSmallest = Solution_2::kthSmallest(n_0, 1);
  std::cout << "S1.TC2. kth smallest value on BST: " << kthSmallest << "\n";
  kthSmallest = Solution_2::kthSmallest(n_0, 1);
  std::cout << "S2.TC2. kth smallest value on BST: " << kthSmallest << "\n";

  return 0;
}

/*
lass Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;

        std::vector<int> inOrderTrav{};
        inOrder(root, inOrderTrav);

        return inOrderTrav.at(k-1);
    }

    void inOrder(TreeNode *root, std::vector<int> &tr) {
        if(root) {
            inOrder(root->left, tr);
            tr.push_back(root->val);
            inOrder(root->right, tr);
        }
    }
};
*/