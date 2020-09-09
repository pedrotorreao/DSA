/****************************************************************/
/*Trees: Red-Black Tree  ********/
/****************************************************************/

class Node {
  constructor(value) {
    this.left = null;
    this.right = null;
    this.value = value;
    this.color = null;
    this.height = 1;
  }
}
class redBlackTree {
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

        //Red Black checks and operations:


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
    const removeHelper = function (self, root, value) {
      if (root === null) { return null; } //Tree is empty bro
      if (value === root.value) { //value to be removed was found
        if ((root.left === null) && (root.right === null)) { return null; } //node has no children, just remove it (assigning null).
        if (root.left === null) { return root.right; } //node has no left child, replace it w/ its right node.
        if (root.right === null) { return root.left; } //node has no right child, replace it w/ its left node.
        //In case the node to be deleted has both children:
        let tempNode = root.right;
        while (tempNode.left !== null) { tempNode = tempNode.left; } //find node's right child leftmost node
        root.value = tempNode.value; //copies leftmost node value and uses it to replace the value to be removed
        root.right = removeHelper (self, root.right, tempNode.value); //we still have to remove leftmost.value from its original node
      }
      else if (value < root.value) {
        root.left = removeHelper(self, root.left, value);
      }
      else if (value > root.value) {
        root.right = removeHelper(self, root.right, value);
      }

      root.height = 1 + Math.max(self.getHeight(root.left),self.getHeight(root.right)); //Updates node height.

      //Red Black checks and operations:

      //AVL Tree operations:
      let balance = self.getBalance(root);

      if (balance > 1 && root.left !== null) { // Left subtree disbalanced
        //Left-Left case (1 rotation needed): do rightRotation on disbalanced node.
        if (self.getBalance(root.left) >= 0) { 
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
        if (self.getBalance(root.right) <= 0) {
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
    this.root = removeHelper(this, this.root, value);
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

  inOrderTraversal (node = this.root) {//Left Subtree --> Root --> Right Subtree
    //To be added
    if (node === null) { return null; }
    else {
      this.inOrderTraversal(node.left);
      console.log(node.value);
      this.inOrderTraversal(node.right);
    }
  }
}
let rbTree = new redBlackTree();

//Test cases - insert():
// rbTree.insert(10);
// rbTree.insert(20);
// rbTree.insert(30); //Right subtree disb. - Right-Right case: do leftRotation on disbalanced node
// rbTree.insert(40);
// rbTree.insert(50); //Right subtree disb. - Right-Right case: do leftRotation on disbalanced node
// rbTree.insert(25); //Right subtree disb. - Right-Left case: do rightRotation on node.right and leftRotation on disb. node
// rbTree.insert(5);
// rbTree.insert(4); //Left subtree disb. - Left-Left case: do rightRotation on disbalanced node.
// rbTree.insert(9); //Left subtree disb. - Left-Right case: do leftRotation on node.left and rightRotation on disb. node.

//Test cases - remove():
// --- step 1: original tree:
rbTree.insert(400);
rbTree.insert(1000);
rbTree.insert(100);
rbTree.insert(80);
rbTree.insert(200);
rbTree.insert(500);
rbTree.insert(2000);
rbTree.insert(70);
rbTree.insert(90);
rbTree.insert(300);
rbTree.insert(3000);
rbTree.insert(50);
// --- step 2: removals:
// rbTree.remove(90); //80 gets disb. - Left-Left case: do rightRotation on disbalanced node
// rbTree.remove(50); //tree remains balanced
// rbTree.remove(300);//tree remains balanced
// rbTree.remove(200);//100 gets disb. - Left-Right case: do leftRotation on disbNode.left and rightRotation on disbNode.
// rbTree.remove(500);//1000 gets disb. - Right-Right case: do leftRotation on disbalanced node
// rbTree.insert(2500);//tree remains balanced
// rbTree.remove(1000);//2000 gets disb. - Right-Left case: do rightRotation on disbNode.right and leftRotation on disbNode.

// console.log(rbTree);
rbTree.inOrderTraversal();