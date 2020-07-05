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
          if (currentNode.left === null) {return null;}
          return searchTree(currentNode.left);
        } 
        else if(value > currentNode.value) {
          if (currentNode.right === null) {return null;}
          return searchTree(currentNode.right);
        } 
        else {
          return null;
        }
      };
      return searchTree(currentNode);
    }
  }
  remove(value) {
    const removeNode = function(node, value) {
      //checks if tree is empty:
      if (node === null) {
        return null;
      }
      //if we found the value to be removed:
      if (value === node.value) {
        //checks if node has no children (leaf node):
        if ((node.left === null) && (node.right === null)) {
          return null;
        }
        //if node has no left child, it replaces it with its right child (it doesn't matter if it is null):
        if (node.left === null) {
          return node.right;
        }
        //if node has no right child, it replaces it with its left child (it doesn't matter if it is null):
        if (node.right === null) {
          return node.left;
        }
        //if the node has both children, then we must find its right node leftmost node:
        let tempNode = node.right;
        while(tempNode.left !== null) {
          tempNode = tempNode.left;
        }
        //copies leftmost node value and uses it to replace the node to be removed (we still have to remove leftmost.value from its original node and update the reference leading to it):
        node.value = tempNode.value;
        node.right = removeNode(node.right, tempNode.value);
        return node;
      }
      //if the value we want to remove is less than the current node value, go  left:
      else if(value < node.value) {
        node.left = removeNode(node.left,value);
        return node;
      }
      //if the value we want to remove is greater than the current node value, go right:
      else if(value > node.value) {
        node.right = removeNode(node.right,value);
        return node;
      }
    }
    //calling the recursive function by passing the root node and the value to be removed
    this.root = removeNode(this.root,value);
  }
  minValue() {
    let currentNode = this.root;
    while(currentNode.left !== null) {
      currentNode = currentNode.left;
    }
    return currentNode.value;
  }
  maxValue() {
    let currentNode = this.root;
    while (currentNode.right !== null) {
      currentNode = currentNode.right;
    }
    return currentNode.value;
  }
  minHeight(node = this.root) { //distance from the root node to the first node without two children
    if (node === null) {
      return -1;
    }
    let left = this.minHeight(node.left);
    let right = this.minHeight(node.right);
    if (left < right) {
      return (left + 1);
    } else {
      return (right + 1);
    }
  }
  maxHeight(node = this.root) { //distance from the root node to the bottommost node
    if (node === null) {
      return -1;
    }
    let left = this.maxHeight(node.left);
    let right = this.maxHeight(node.right);
    if (left > right) {
      return (left + 1);
    } else {
      return (right + 1);
    }
  }
  //a bst is balanced if the difference in height between the left and the right subtree differ at most by 1.
  isBalanced() {
    return (this.minHeight() >= this.maxHeight() - 1);
  }
  inOrderTraversal(node = this.root) {//Left Subtree --> Root --> Right Subtree
    if (node === null) {
      return;
    } else {
      this.inOrderTraversal(node.left);
      console.log(node.value);
      this.inOrderTraversal(node.right);
    }
  }
  preOrderTraversal(node = this.root) {//Root --> Left Subtree --> Right Subtree
    if (node === null) {
      return;
    } else {
      console.log(node.value);
      this.preOrderTraversal(node.left);
      this.preOrderTraversal(node.right);
    }
  }
  postOrderTraversal(node = this.root) {//Left Subtree --> Right Subtree --> Root
    if (node === null) {
      return;
    } else {
      this.postOrderTraversal(node.left);
      this.postOrderTraversal(node.right);
      console.log(node.value);
    }
  }
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
//tree.remove(9);
//console.log(tree.lookup(9));
console.log(tree);
console.log(tree.minValue());
console.log(tree.maxValue());

console.log(tree.minHeight());
console.log(tree.maxHeight());
console.log('The BST is balanced: ', tree.isBalanced());

console.log('inOrderTraversal():');
tree.inOrderTraversal(); //1 > 4 > 6 > 9 > 15 > 20 > 170
console.log('preOrderTraversal():');
tree.preOrderTraversal(); //9 > 4 > 1 > 6 > 20 > 15 > 170
console.log('postOrderTraversal():');
tree.postOrderTraversal();  //1 > 6 > 4 > 15 > 170 > 20 > 9