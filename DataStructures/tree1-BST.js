/****************************************************************/
/*Problem: Tree Exercise (BST)  ********/
/****************************************************************/
/*
-- Summary:
-- Input(s):
-- Expected output(s):
-- Constraints:
*/

class Node {
  constructor(value){
    this.left = null;
    this.right = null;
    this.value = value;
  }
}
class BinarySearchTree {
  constructor(){
    this.root = null;
  }
  insert(value){
    //Code here
    let node = new Node(value);

    if (this.root === null) {
      this.root = node;
    } else {
      let currentNode = this.root;
      while (currentNode) {
        if (node.value < currentNode.value) {
          if (!currentNode.left) {
            currentNode.left = node;
            return;
          }
          currentNode = currentNode.left;
        } else {
          if (!currentNode.rigth) {
            currentNode.rigth = node;
            return;
          }
          currentNode = currentNode.rigth;
        }
      }
      currentNode.left = node;
    }
  }
  lookup(value){
    //Code here
  }
  // remove
}

const tree = new BinarySearchTree();
tree.insert(9)
tree.insert(4)
tree.insert(6)
tree.insert(20)
tree.insert(170)
tree.insert(15)
tree.insert(1)
JSON.stringify(traverse(tree.root))
console.log(tree);
//     9
//  4     20
//1  6  15  170

function traverse(node) {
  const tree = { value: node.value };
  tree.left = node.left === null ? null : traverse(node.left);
  tree.right = node.right === null ? null : traverse(node.right);
  return tree;
}