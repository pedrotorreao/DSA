/****************************************************************/
/*Problem: Maximum Depth of Binary Tree (HR)  ********/
/****************************************************************/
/*
-- Summary:
Given a binary tree, find its maximum depth. The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/*
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
  if (root === null) {
      return 0;
  } 
  let L = maxDepth(root.left);
  let R = maxDepth(root.right);
  if (L > R) {
      return (L+1);
  } else {
      return (R+1);
  }
};