/****************************************************************/
/*Problem: Search in a Binary Search Tree (LC)  ********/
/****************************************************************/
/*
-- Summary:
Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.
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
 * @param {number} val
 * @return {TreeNode}
 */
var searchBST = function(root, val) {
    let currentNode = root;
    while (currentNode){
        if (val === currentNode.val) {
            return currentNode;
        } else if (val < currentNode.val) {
            currentNode = currentNode.left;
        } else if (val > currentNode.val) {
            currentNode = currentNode.right;
        }
    }
    return null;
};