/****************************************************************/
/*Trees: Red-Black Tree  ********/
/****************************************************************/

class Node {
  constructor(value) {
    this.left = null;
    this.right = null;
    this.parent = null;
    this.value = value;
    this.color = 'RED';
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

    if (this.root === null) { //If tree is empty create new node as root node and color it black.
      node.color = 'BLACK';
      node.parent = null; 
      this.root = node;
      console.log('root node created - root.value: ', this.root.value);
      return;
    } 
    else {

      //doing this saved my life and got the rotations to work properly, just calling method is not enough, must assign.
      this.root = this.insertBST(this.root, node);
      this.rbHelper(node);
    }
  }

  insertBST (root, node) {
    //Regular BST insertion:
    if(root === null) { root = node; } 
    else if (node.value < root.value) {
      node.parent = root; 
      root.left = this.insertBST(root.left, node); 
    } 
    else if (node.value > root.value) { 
      node.parent = root; 
      root.right = this.insertBST(root.right, node);
    } 
    else { return null; } //Cannot have repeated nodes on BST

    return root;
  };

  rbHelper (node) {
    if (node === this.root || node === null) { return; } 
    if (node.parent !== null && node.parent.color === 'BLACK') { return; } //3

    let grandparent = node.parent.parent;

    let uncle = (node.parent === grandparent.left) ? grandparent.right : grandparent.left;

    if(uncle !== null && uncle.color === 'RED') { //4.b
      this.colorSwap(node.parent);
      this.colorSwap(uncle);
      this.colorSwap(grandparent);

      node = grandparent;

      this.rbHelper(node);
    } 
    else {//4.a
      if(node.parent === grandparent.left) {
      if(node === node.parent.right) {//LR case
        this.leftRotation(node.parent);
        this.rightRotation(grandparent); 
      } else {//LL case
        this.rightRotation(grandparent); 
        node = node.parent;
      }
      
        this.colorSwap(node);
        this.colorSwap(grandparent); 
        node = node.parent;  
      }
      else {
        if(node === node.parent.left) {//RL case
          this.rightRotation(node.parent);
          this.leftRotation(grandparent);
        } else {//RR case
          this.leftRotation(grandparent);
          node = node.parent;
        }
        
        this.colorSwap(node);
        this.colorSwap(grandparent); 
        node = node.parent; 
      }
      this.rbHelper(node);
    } 
    this.root.color = 'BLACK'; //change to point directly to this.root
  }

  colorSwap(node) {
    let tempNode = node;
    tempNode.color = (node.color === 'RED') ? 'BLACK' : 'RED';
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
rightRotation(node) {//LL condition --> Right Rotation
  let tempNode = node.left;
  node.left = tempNode.right;

  //Update parent reference in case of temp node having a right subtree:
  if(node.left !== null) { node.left.parent = node; }

  //Update temp node parent to be node's parent:
  tempNode.parent = node.parent;

  //Update parent references for rotated node:
  if(node.parent === null) { this.root = tempNode; }
  else if(node === node.parent.left) { node.parent.left = tempNode; }
  else { node.parent.right = tempNode; } 

  tempNode.right = node;
  node.parent = tempNode;

  //return tempNode;
}

leftRotation(node) {//RR condition --> Left Rotation
  let tempNode = node.right; 
  node.right = tempNode.left; 

  //Update parent reference in case of temp node having a left subtree:
  if(node.right !== null) { node.right.parent = node; }

  //Update temp node parent to be node's parent:
  tempNode.parent = node.parent; //console.log(`left rot. ${tempNode.parent}`);

  //Update parent references for rotated node:
  if(node.parent === null) { this.root = tempNode;} //seliga aqui, era so root
  else if(node === node.parent.left) { node.parent.left = tempNode; }
  else { node.parent.right = tempNode; }
  //console.log(`new root. ${this.root.value}`);
  tempNode.left = node;
  node.parent = tempNode;

  return tempNode;
}
  inOrderTraversal (node = this.root) {//Left Subtree --> Root --> Right Subtree
    //To be added
    if (node === null) { return null; }
    else {
      this.inOrderTraversal(node.left);
      console.log(`node.value: ${node.value} | node.color: ${node.color}`);
      this.inOrderTraversal(node.right);
    }
  }
  levelOrderTraversal() {//1st level --> 2nd level --> 3rd level ...
    let queue = [];
    if (this.root !== null) {
      queue.push(this.root);
      while (queue.length > 0) {
        let node = queue.shift();
        console.log(node.value);
        if (node.left !== null) {
          queue.push(node.left);
        }
        if (node.right !== null) {
          queue.push(node.right);
        }
      }
    } else {
      return null;
    }
  }
}
let rbTree = new redBlackTree();
//TC 1 - Case 4.a w/ LR rotation: ok
// rbTree.insert(10);
// rbTree.insert(18);
// rbTree.insert(7);
// rbTree.insert(3);
// rbTree.insert(5);

//TC 2- Case 4.a w/ RL rotation: ok 
// rbTree.insert(10);
// rbTree.insert(18);
// rbTree.insert(7);
// rbTree.insert(20);
// rbTree.insert(19);

//TC 3- Complete tree w/ all cases: 
rbTree.insert(10);
rbTree.insert(18);
rbTree.insert(7);
rbTree.insert(15);
rbTree.insert(16);
rbTree.insert(30);
rbTree.insert(25);
rbTree.insert(40); 
rbTree.insert(60);
rbTree.insert(2);
rbTree.insert(1);
rbTree.insert(70);


console.log(rbTree);

rbTree.inOrderTraversal();
rbTree.levelOrderTraversal();