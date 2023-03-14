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

/*
--Reasoning:
  We'll keep track of the current path which will be passed in as argument (by reference) to all the recursive function calls. At every new node visited, we'll add the current node to the current path and find the sums of all of the sub-paths
  which end at the current node. If the sum of any of the sub-paths adds up to the target sum, we have a match and increment the path count. Additionally, once we've finished recursing down a path, we need to remove the current node from the path to backtrack and go up in the recursive call stack.
--Time complexity:
  Worst case: O(N^2), where N is the total number of nodes in the tree, since we
  visit each node once, but for each node, we'll have to iterate the current path which, in the worst case, can have a lenght N (i.e. for a skewed tree/linked list).
  Best case: O(N*log(N)), for the scenario where the tree is balanced and the current path will be equal to the height of the tree.

--Space complexity:
  O(N), where N is the total number of nodes in the tree. This is due to the storage
  required for the recursion stack. In the worst case, the tree is completely skewed and has the structure of a linked list. Additionally, we also need O(N) space for storing the currentPath.
*/
class Solution_1 {
public:
  int countPaths_1(TreeNode *root, int target) {
    std::vector<int> currentPath;

    return countPaths_DFS_1(root, target, currentPath);
  }

private:
  int countPaths_DFS_1(TreeNode *node, int target, std::vector<int> &currPath) {
    if (node == nullptr)
      return 0;

    // let's add current node to the path:
    currPath.push_back(node->val);

    int pathCount{0}, // number of paths which satisfy the conditions
        pathSum{0};   // current path's sum

    // iterate backwards in the current path checking all of its sub-paths to
    // find out if any of them satisfy match the target sum we're looking for:
    for (auto itr = currPath.rbegin(); itr != currPath.rend(); ++itr) {
      pathSum += (*itr);

      // if a matching path is found, increment count and break out of the loop:
      if (pathSum == target) {
        ++pathCount;
        // break out of the loop to avoid repeated counts since all the other
        // paths that may exist before the current one will have been accounted
        // for in previous function calls:
        break;
      }
    }

    // traverse the left subtree:
    pathCount += countPaths_DFS_1(node->left, target, currPath);
    // traverse the right subtree:
    pathCount += countPaths_DFS_1(node->right, target, currPath);

    // once we've finished recursing down a path, we need to remove the current node
    // from the path to backtrack and go up in the recursive call stack:
    currPath.pop_back();

    return pathCount;
  }
};

class Solution_2 {
public:
  int countPaths_2(TreeNode *root, int target) {
    std::unordered_map<int, int> map; // store the prefix sum' frequency

    return countPaths_DFS_2(root, target, map, 0);
  }

private:
  int countPaths_DFS_2(TreeNode *node, int target, std::unordered_map<int, int> &map, int currPathSum) {
    if (node == nullptr)
      return 0;

    // number of pairs which add up to the target sum:
    int pathCount{0};

    // sum of all the node values from root to the current node, i.e. prefix sum:
    currPathSum += node->val;

    // if the current path sum matches the target sum, it means that there is a
    // path from the root to the current node that satisfies the requirement. Thus,
    // increment the path count:
    if (currPathSum == target)
      ++pathCount;

    // if within the path sum from root to the current node, i.e. 'currPathSum',
    // there is a valid solution, then there must be an 'prevPathSum' such that:
    //    currPathSum - prevPathSum = targetSum
    //    currPathSum - targetSum = prevPathSum
    // thus, we can search this 'prevPathSum' in the map from the key 'currPathSum - targetSum':
    if (map[currPathSum - target] > 0)
      pathCount += map[currPathSum - target];

    // store the frequency that prefix sum 'currPathSum' has occurred:
    ++map[currPathSum];

    // count paths on the left subtree:
    pathCount += countPaths_DFS_2(node->left, target, map, currPathSum);
    // count paths on the right subtree:
    pathCount += countPaths_DFS_2(node->right, target, map, currPathSum);

    // remove the current path sum from the map for backtracking, since
    // 'currPathSum' represents the prefix sum up to the current node; therefore,
    // when we go unwind the recursion stack (i.e., backtrack), the current node
    // is not part of the path anymore, thus, its prefix sum should be removed from
    // the map:
    --map[currPathSum];

    return pathCount;
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

  Solution_1 sol_1;
  Solution_2 sol_2;

  int target{0}, cntPaths{0};

  target = 12;
  cntPaths = sol_1.countPaths_1(root, target);
  std::cout << "Path count: " << cntPaths << "\n";
  cntPaths = sol_2.countPaths_2(root, target);
  std::cout << "Path count: " << cntPaths << "\n";

  root = nullptr;

  root = new TreeNode(12);
  root->right = new TreeNode(1);
  root->right->right = new TreeNode(5);
  root->right->left = new TreeNode(10);
  root->left = new TreeNode(7);
  root->left->right = new TreeNode(4);

  target = 11;
  cntPaths = sol_1.countPaths_1(root, target);
  std::cout << "Path count: " << cntPaths << "\n";
  cntPaths = sol_2.countPaths_2(root, target);
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
  cntPaths = sol_1.countPaths_1(root, target);
  std::cout << "Path count: " << cntPaths << "\n";
  cntPaths = sol_2.countPaths_2(root, target);
  std::cout << "Path count: " << cntPaths << "\n";

  return 0;
}