/****************************************************************/
/*Trees: AVL Tree  ********/
/****************************************************************/

class Node {
  constructor(value) {
    this.left = null;
    this.right = null;
    this.value = value;
  }
}
class avlTree {
  constructor () {
    this.root = null;
  }

  lookup(value) {
    let currentNode = this.root;
    if (this.root === null) {return null;}
    const searchTree = function(currentNode) {
        if (currentNode === null) {return null;}
        if (currentNode.value === value) {return currentNode;}
        if (value < currentNode.value){return searchTree(currentNode.left);}
        if (value > currentNode.value){return searchTree(currentNode.right);}
        return null;
    };
    return searchTree(currentNode);
  }
  insert(value, currentNode = this.root) {
    if (this.root === null) {
      this.root = new Node(value); return;
    }

    if (value < currentNode.value) {
      if (currentNode.left === null) {currentNode.left = new Node(value);} 
      else {this.insert(value, currentNode.left);}
    }
    else if (value > currentNode.value) {
      if (currentNode.right === null) {currentNode.right = new Node(value);}
      else {this.insert(value, currentNode.right);}
    }
    else {return null;}

    // AVL tree part:
    let balance = 0;
    balance = this.getBalance(currentNode);
    //balance = -2;

    if (balance > 1) {// Left subtree is disbalanced
        if (this.getBalance(currentNode.left) > 0) {
          currentNode = this.rightRotation(currentNode);
          
        }
        else { currentNode.left = this.leftRotation(currentNode.left); currentNode = this.rightRotation(currentNode);}
        this.root = currentNode;
    }
    else if (balance < -1) {//Right subtree is disbalanced
        if (this.getBalance(currentNode.right) > 0) { 
          currentNode = this.leftRotation(currentNode);
          
        }
        else { currentNode.right = this.rightRotation(currentNode.right); currentNode = this.leftRotation(currentNode); }
        this.root = currentNode;
    }

    return currentNode;
  }

  remove(value) {

  }
  getHeight(node = this.root) {
    if (node === null) {return 0;}
    return 1 + Math.max(((node.left!==null) ? this.getHeight(node.left) :-1),((node.right!==null) ? this.getHeight(node.right) :-1));
  }
  getBalance(node = this.root) {
    //it may be needed to add checks for empty nodes
    // if (node.left === null && node.right === null) {return 0;}
    // else if (node.left === null) {return -1 * (this.getHeight(node.right) + 1);}
    // else if (node.right === null) {return 1 + this.getHeight(node.left);}
    
    return (this.getHeight(node.left) - this.getHeight(node.right));
  }
  leftRotation(node = this.root) {
    let newRoot = node.right;
    node.right = node.right.left;
    newRoot.left = node;

    return newRoot;
    //may add height calc. later
  }
  rightRotation(node = this.root) {
    let newRoot = node.left;
    node.left = node.left.right;
    newRoot.right = node;

    return newRoot;
    //may add height calc. later
  }


  minHeight(node = this.root) {

  }
  maxHeight(node = this.root) {
    
  }

}
let seBalanceTree = new avlTree();

// Left-Left condition:
//Test 1:
// seBalanceTree.insert(9);
// seBalanceTree.insert(4);
// seBalanceTree.insert(20);
// seBalanceTree.insert(3);
// seBalanceTree.insert(7);
// seBalanceTree.insert(1);

// Left-Left condition:
//Test 2:
// seBalanceTree.insert(9);
// seBalanceTree.insert(4);
// seBalanceTree.insert(20);
// seBalanceTree.insert(3);
// seBalanceTree.insert(30);
// seBalanceTree.insert(15);
// seBalanceTree.insert(10);

seBalanceTree.insert(10);
seBalanceTree.insert(20);
seBalanceTree.insert(35);
seBalanceTree.insert(53);
// seBalanceTree.insert(30);
// seBalanceTree.insert(15);
// seBalanceTree.insert(10);

console.log(seBalanceTree);