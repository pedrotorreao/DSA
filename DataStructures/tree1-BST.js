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
      //In case the tree is empty, add new node to the root.
      this.root = node;
    } else {
      //Create temp node so we can traverse the tree.
      let currentNode = this.root;
      while (currentNode) {
        //If new value is less than the root value, go left.
        if (node.value < currentNode.value) {
          if (!currentNode.left) {
            //If the left spot is empty, assign it the new node value.
            currentNode.left = node;
            return;
          }
          currentNode = currentNode.left;
        } else {//If new value is greater than the root value, go right.
          if (!currentNode.right) {
            //If the right spot is empty, assign it the new node value.
            currentNode.right = node;
            return;
          }
          currentNode = currentNode.right;
        }
      }
      currentNode.left = node;
    }
  }
  lookup(value){
    let currentNode = this.root;
    while (currentNode) {
      if (currentNode.value === value) {
        return currentNode;
      } else if (value < currentNode.value) {
        currentNode = currentNode.left;
      } else {
        currentNode = currentNode.right;
      }
    }
    return `${value} is not in the tree.`;
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