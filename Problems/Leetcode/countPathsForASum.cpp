#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
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

class Solution {
public:
  int countPaths_2(TreeNode *root, int target) {
    std::vector<int> currentPath;

    return countPaths_DFS_2(root, target, currentPath);
  }

  int countPaths_3(TreeNode *root, int target) {
    std::unordered_map<int, int> map;

    return countPaths_DFS_3(root, target, map, 0);
  }

private:
  int countPaths_DFS_2(TreeNode *node, int target, std::vector<int> &currPath) {
    if (node == nullptr)
      return 0;

    currPath.push_back(node->val);

    int pathCount{0}, pathSum{0};

    for (auto itr = currPath.rbegin(); itr != currPath.rend(); ++itr) {
      pathSum += (*itr);

      if (pathSum == target) {
        ++pathCount;
        break;
      }
    }

    pathCount += countPaths_DFS_2(node->left, target, currPath);
    pathCount += countPaths_DFS_2(node->right, target, currPath);

    currPath.pop_back();

    return pathCount;
  }

  int countPaths_DFS_3(TreeNode *node, int target, std::unordered_map<int, int> &map, int currPathSum) {
    if (node == nullptr)
      return 0;

    int pathCount{0};

    currPathSum += node->val;

    if (currPathSum == target)
      ++pathCount;

    if (map[currPathSum - target] > 0)
      pathCount += map[currPathSum - target];

    ++map[currPathSum];

    pathCount += countPaths_DFS_3(node->left, target, map, currPathSum);
    pathCount += countPaths_DFS_3(node->right, target, map, currPathSum);

    --map[currPathSum];

    return pathCount;
  }
  // check if a given node is a leaf node:
  bool isLeaf(TreeNode *node) {
    return (node->left == nullptr && node->right == nullptr);
  }
};

int main() {
  TreeNode *root = nullptr;

  root = new TreeNode(1);
  root->right = new TreeNode(9);
  root->right->right = new TreeNode(3);
  root->right->left = new TreeNode(2);
  root->left = new TreeNode(7);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(5);

  Solution sol;
  int target{0}, cntPaths{0};

  target = 12;
  cntPaths = sol.countPaths_2(root, target);
  std::cout << "Path count: " << cntPaths << "\n";
  cntPaths = sol.countPaths_3(root, target);
  std::cout << "Path count: " << cntPaths << "\n";

  root = nullptr;

  root = new TreeNode(12);
  root->right = new TreeNode(1);
  root->right->right = new TreeNode(5);
  root->right->left = new TreeNode(10);
  root->left = new TreeNode(7);
  root->left->right = new TreeNode(4);

  target = 11;
  cntPaths = sol.countPaths_2(root, target);
  std::cout << "Path count: " << cntPaths << "\n";
  cntPaths = sol.countPaths_3(root, target);
  std::cout << "Path count: " << cntPaths << "\n";

  root = nullptr;

  root = new TreeNode(9);
  root->right = new TreeNode(15);
  root->right->right = new TreeNode(10);
  root->right->left = new TreeNode(13);
  root->right->left->right = new TreeNode(6);
  root->left = new TreeNode(2);
  root->left->right = new TreeNode(32);
  root->left->right->right = new TreeNode(19);
  root->left->left = new TreeNode(0);
  root->left->left->left = new TreeNode(11);
  root->left->left->right = new TreeNode(23);

  target = 34;
  cntPaths = sol.countPaths_2(root, target);
  std::cout << "Path count: " << cntPaths << "\n";
  cntPaths = sol.countPaths_3(root, target);
  std::cout << "Path count: " << cntPaths << "\n";

  return 0;
}