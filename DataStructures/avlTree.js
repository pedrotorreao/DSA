class Node {
  constructor(value) {
    this.left = null;
    this.right = null;
    this.value = value;
    this.height = 1;
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
  insert(value) {
    let node = new Node(value);

    if (this.root === null) { 
      this.root = node; 
      return;
    } else {
      const insertHelper = function(self, root, node) {
        //Regular BST insertion:
        if(root === null) { root = node; } 
        else if (node.value < root.value) { root.left = insertHelper(self, root.left, node); } 
        else if (node.value > root.value) { root.right = insertHelper(self, root.right, node); } 
        else { return null; } //Cannot have repeated nodes on BST

        root.height = 1 + Math.max(self.getHeight(root.left),self.getHeight(root.right)); //Updates node height.

        //AVL Tree operations:
        let balance = self.getBalance(root);

        if (balance > 1 && root.left !== null) { // Left subtree disbalanced
          //Left-Left case (1 rotation needed): do rightRotation on disbalanced node.
          if (node.value < root.left.value) { 
            return self.rightRotation(root);
          }
          //Left-Right case (2 rotations needed): do leftRotation on disb. node left subtree and rightRotation on disb. node.
          else {
            root.left = self.leftRotation(root.left);
            return self.rightRotation(root);
          }
        }
        if (balance < -1 && root.right !== null) { // Right subtree disbalanced
          //Right-Right case (1 rotation needed): do leftRotation on disbalanced node.
          if (node.value > root.right.value) {
            return self.leftRotation(root);
          }
          //Right-Left case (2 rotations needed): do rightRotation on disb. node right subtree and leftRotation on disb. node.
          else {
            root.right = self.rightRotation(root.right);
            return self.leftRotation(root);
          }
        }
        return root;
      };
      //doing this saved my life and got the rotations to work properly, just calling method is not enough, must assign.
      this.root = insertHelper(this, this.root, node); 
    }
  }

  remove(value) {
    //to be implemented
  }
  getHeight(node = this.root) {
    if (node === null) {
      return 0;
    } else {
      return node.height;
    }
  }
  getBalance(node = this.root) {
    if (node === null) {
      return 0;
    }
    return (this.getHeight(node.left) - this.getHeight(node.right));
  }
  
  rightRotation(node) {//LL condition --> Right Rotation
    let tempNode = node.left;
    node.left = tempNode.right;
    tempNode.right = node;

    node.height = 1 + Math.max(this.getHeight(node.left),this.getHeight(node.right));
    tempNode.height = 1 + Math.max(this.getHeight(tempNode.left),this.getHeight(tempNode.right));

    return tempNode;
  }

  leftRotation(node) {//RR condition --> Left Rotation
    let tempNode = node.right;
    node.right = tempNode.left;
    tempNode.left = node;

    node.height = 1 + Math.max(this.getHeight(node.left),this.getHeight(node.right));
    tempNode.height = 1 + Math.max(this.getHeight(tempNode.left),this.getHeight(tempNode.right));

    return tempNode;
  }
}
let seBalanceTree = new avlTree();

//Test cases:
seBalanceTree.insert(10);
seBalanceTree.insert(20);
seBalanceTree.insert(30); //Right subtree disb. - Right-Right case: do leftRotation in disbalanced node
seBalanceTree.insert(40);
seBalanceTree.insert(50); //Right subtree disb. - Right-Right case: do leftRotation in disbalanced node
seBalanceTree.insert(25); //Right subtree disb. - Right-Left case: do rightRotation in node.right and leftRotation on disb. node
seBalanceTree.insert(5);
seBalanceTree.insert(4); //Left subtree disb. - Left-Left case: do rightRotation in disbalanced node.
seBalanceTree.insert(9); //Left subtree disb. - Left-Right case: do leftRotation in node.left and rightRotation on disb. node.

console.log(seBalanceTree);