/****************************************************************/
/* Trees - Binary Search Tree (BST): Using recursion  ********/
/****************************************************************/

class Node {
  constructor(value) {
    this.left = null;
    this.right = null;
    this.value = value;
  }
}
class BinarySearchTree {
  constructor() {
    this.root = null;
  }
  insert(value) {
    let node = new Node(value);
    const currentNode = this.root;

    if (this.root === null) {
      this.root = new Node(value);
      return;
    } 
    else {
      const searchTree = function(currentNode) {
        if(value < currentNode.value) {
          if(currentNode.left === null) {
            currentNode.left = node;
            return;
          } 
          return searchTree(currentNode.left);
        } 
        else if(value > currentNode.value) {
          if(currentNode.right === null) {
            currentNode.right = node;
            return;
          }
          return searchTree(currentNode.right);
        } 
        else {
          return null;
        }
      };
      return searchTree(currentNode);
    }
  }
  lookup(value) {
    const currentNode = this.root;
    if (this.root === null) {
      return null;
    } 
    else {
      const searchTree = function(currentNode) {
        if(currentNode.value === value) {
          return currentNode;
        }
        else if(value < currentNode.value) {
          return searchTree(currentNode.left);
        } 
        else if(value > currentNode.value) {
          return searchTree(currentNode.right);
        } 
        else {
          return null;
        }
      };
      return searchTree(currentNode);
    }
  }
  // remove(value) {

  // }
  // isBalanced() {

  // }
  // minHeight() {

  // }
  // maxHeight() {

  // }
  // inOrderTraversal() {

  // }
  // preOrderTraversal() {

  // }
  // postOrderTraversal() {

  // }
  // levelOrderTraversal() {

  // }
}
//     9
//  4     20
//1  6  15  170
const tree = new BinarySearchTree();
//Create tree above:
tree.insert(9);
tree.insert(4);
tree.insert(6);
tree.insert(20);
tree.insert(170);
tree.insert(15);
tree.insert(1);
console.log(tree);
console.log(tree.lookup(9));