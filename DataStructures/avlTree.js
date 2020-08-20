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
    let node = new Node(value);

    if (this.root === null) { this.root = node; }
    else if (node.value < currentNode.value) {
      if (currentNode.left === null) {currentNode.left = node;} 
      else { this.insert(value, currentNode.left); }
    }
    else if (node.value > currentNode.value) {
      if (currentNode.right === null) {currentNode.right = node;}
      else { this.insert(value, currentNode.right); }
    }
    else {return this.root;}

    //AVL tree part:
    if (this.root.left !== null && this.getBalance(this.root) > 1) {// Left subtree is disbalanced
      if (node.value > this.root.left.value) {
        this.root = this.rotationLL(this.root);
      }
      else { this.root = this.rotationLR(this.root);}
    }
    else if (this.root.right !== null && this.getBalance(this.root) < -1) {//Right subtree is disbalanced
      if (node.value > this.root.right.value) { 
        this.root = this.rotationRR(this.root);
      }
      else { this.root = this.rotationRL(this.root);}
    }
    // if (currentNode.left !== null && this.getBalance(currentNode) > 1) {// Left subtree is disbalanced
    //     if (this.getBalance(currentNode.left) > 0) {
    //       currentNode = this.rightRotation(currentNode);
    //     }
    //     else { currentNode.left = this.leftRotation(currentNode.left); currentNode = this.rightRotation(currentNode);}
    //     this.root = currentNode;
    // }
    // else if (currentNode.right !== null && this.getBalance(currentNode) < -1) {//Right subtree is disbalanced
    //     if (this.getBalance(currentNode.right) > 0) { 
    //       currentNode = this.leftRotation(currentNode);
    //     }
    //     else { currentNode.right = this.rightRotation(currentNode.right); currentNode = this.leftRotation(currentNode); }
    //     this.root = currentNode;
    // }

    return this.root;
  }

  remove(value) {

  }
  getHeight(node = this.root) {
    let nodeHeight = 0;
    if (node === null) { nodeHeight = -1;}
    else { nodeHeight = Math.max(this.getHeight(node.left),this.getHeight(node.right)) + 1;}
  //return 1 + Math.max(((node.left!==null) ? this.getHeight(node.left) :-1),((node.right!==null) ? this.getHeight(node.right) :-1));
    return nodeHeight;
  }
  getBalance(node = this.root) {
    return (this.getHeight(node.left) - this.getHeight(node.right));
  }
  
  rotationLL(node) {//LL condition --> Right Rotation
    let newRoot = node.left;
    node.left = newRoot.right;
    newRoot.right = node;

    return newRoot;
  }

  rotationRR(node) {//RR condition --> Left Rotation
    let newRoot = node.right;
    node.right = newRoot.left;
    newRoot.left = node;

    return newRoot;
  }

  rotationLR(node) {
    node.left = this.rotationRR(node.left);
    return this.rotationLL(node);
  }

  rotationRL(node) {
    node.right = this.rotationLL(node.right);
    return this.rotationRR(node);
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
seBalanceTree.insert(9);
seBalanceTree.insert(4);
seBalanceTree.insert(20);
seBalanceTree.insert(2);
seBalanceTree.insert(30);
seBalanceTree.insert(15);
seBalanceTree.insert(10);
seBalanceTree.insert(13);

// seBalanceTree.insert(10);
// seBalanceTree.insert(20);
// seBalanceTree.insert(35);
//seBalanceTree.insert(53);
// seBalanceTree.insert(30);
// seBalanceTree.insert(15);
// seBalanceTree.insert(10);

console.log(seBalanceTree);