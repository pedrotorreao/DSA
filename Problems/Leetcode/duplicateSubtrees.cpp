/*********************************************************************************************/
/* Problem: Find Duplicate Subtrees (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given the root of a binary tree, return all duplicate subtrees. For each kind of duplicate
  subtrees, you only need to return the root node of any one of them.
  Two trees are duplicate if they have the same structure with the same node values.

  > Example 1:
      Input: root = [1,2,3,4,null,2,4,null,null,4] -- level order
      Output: [[2,4],[4]]

  > Example 2:
      Input: root = [2,1,1] -- level order
      Output: [[1]]

  > Example 3:
      Input: root = [2,2,2,3,null,3,null] -- level order
      Output: [[2,3],[3]]

--Inputs:
  - TreeNode*: root of a binary tree

--Output:
  - vector<TreeNode*>: root nodes for the subtrees found

--Constraints:
  The number of the nodes in the tree will be in the range [1, 10^4]
  -200 <= Node.val <= 200


--Reasoning: See comments below.

--Time complexity:
  O(N), since we traverse all the nodes of the tree in order to serialize them.

--Space complexity:
  O(N), since we store the serialization in a N-sized string.

*/
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

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function that performs the serialization of the tree and maps each subtree to its root node.
// This way, repeated subtrees will have more than 1 root node mapped to them in the hash map:
std::string serializeTree(TreeNode *node, std::unordered_map<std::string, std::vector<TreeNode *>> &map) {
  if (node == nullptr)
    return "#";
  // serialize:
  std::string ser = "(" + serializeTree(node->left, map) + std::to_string(node->val) + serializeTree(node->right, map) + ")";
  // map subtree:root
  map[ser].push_back(node);

  return ser;
}

std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
  std::unordered_map<std::string, std::vector<TreeNode *>> serialized_map;
  std::vector<TreeNode *> duplicates;

  // perform the serialization of the tree:
  serializeTree(root, serialized_map);

  auto itr = serialized_map.begin();
  while (itr != serialized_map.end()) {
    // there are duplicates:
    if ((itr->second).size() > 1)
      duplicates.push_back((itr->second).at(0));

    ++itr;
  }

  return duplicates;
}

int main() {
  // test ..

  return 0;
}