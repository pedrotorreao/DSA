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
    //this.checkDB = false; //test
  }
  // ------------------- SEARCH/LOOKUP METHOD ------------------>>
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
  // -----------------------------------------------------------<<
  // ------------ RED BLACK: NODE INSERTION METHODS ------------>>
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
      this.fixDoubleRed(node);
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
  fixDoubleRed (node) {
    if (node === this.root || node === null) { return; } 
    if (node.parent !== null && node.parent.color === 'BLACK') { return; } //3

    let grandparent = node.parent.parent;

    let uncle = (node.parent === grandparent.left) ? grandparent.right : grandparent.left;

    if(uncle !== null && uncle.color === 'RED') { //4.b
      this.colorSwitch(node.parent);
      this.colorSwitch(uncle);
      this.colorSwitch(grandparent);

      node = grandparent;

      this.fixDoubleRed(node);
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
      
        this.colorSwitch(node);
        this.colorSwitch(grandparent); 
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
        
        this.colorSwitch(node);
        this.colorSwitch(grandparent); 
        node = node.parent; 
      }
      this.fixDoubleRed(node);
    } 
    this.root.color = 'BLACK'; //change to point directly to this.root
  }
  // -----------------------------------------------------------<<
  // ------------- RED BLACK: NODE REMOVAL METHODS ------------->>
  remove(value) {
    let node = new Node(value); 

    if (this.root === null) { console.log('Tree is currently empty bro!'); return; } 
    
    //this.root = this.removeBST(this.root, node); // TEEEEEEEEST
    this.removeBST(this.root, node);
  }
  removeBST (root, node) {//Binary Search Tree (BST) regular remove() method.
    if (root === null || node === null) { return null; } //Tree is either empty or node=null

    if (node.value === root.value) { //value to be removed was found
      if ((root.left === null) && (root.right === null)) { //node has no children @leaf node.
        if(root === this.root) { this.root = null; } //node is root, just remove it. <<< MODIFIED, MIGHT BE A PAIN LATER
        else if (root.color === 'RED') { //node is a leaf node and is RED, just remove it.
          root.parent.right = null; 
          root.parent = null;
        } 
        else {
          console.log(`>>>> The node being removed (${root.value}) is a BLACK node w/ no children. Calling fixDoubleBlack(...) <<<<`);
          this.fixDoubleBlack(root);
          // console.log(root)
          if (root === root.parent.right) { root.parent.right = null; root.parent = null; }
          else { root.parent.left = null; root.parent = null; }

          //this.levelOrderTraversal();
        }
      } 
      else if (root.left === null && root.right !== null) { //node has no left child, replace it w/ its right node.
        this.valueSwap(root, root.right);
        //root.right = this.removeBST(root.right, root.right); // replaced node by root.right since node had its value swapped
        this.removeBST(root.right, root.right);
      }
      else if (root.left !== null && root.right === null) { //node has no right child, replace it w/ its left node. ## FUNCTIONAL ##
        console.log(`>>>> The node being removed (${root.value}) only has its left child. <<<<`);

        this.valueSwap(root, root.left);
        //root.left = this.removeBST(root.left, root.left); 
        // prev.: root.left = this.removeBST(root.left, node) but replaced 'node' by 'root.left' since node had its value swapped
        this.removeBST(root.left, root.left);
      }
      else { //node has both children: replace its value with the value of its inorder predecessor. ## FUNCTIONAL ##
        console.log(`>>>> The node being removed (${root.value}) has both children. <<<<`);
        let successor = this.getSuccessor(root);
        this.valueSwap(root,successor);
        //root.left = this.removeBST (root.left, successor); //it may cause problems HERE <--<--<<<
        this.removeBST (root.left, successor); 
      }
    }
    else if (node.value < root.value) { this.removeBST(root.left, node); }//root.left = this.removeBST(root.left, node); }
    else if (node.value > root.value) { this.removeBST(root.right, node); }//root.right = this.removeBST(root.right, node); }
    
    //return root;
  }
  fixDoubleBlack(node) {//Double Black -> Single Black
    if(node === this.root) { return; } //we've reached the root node, remove DB.

    let sibling = this.getSibling(node);
    let parent = node.parent;

    if(!sibling) { this.fixDoubleBlack(parent); }//In case there is no sibling, move DB up.
    else {
      if(sibling.color === 'RED') {
        //If sibling node is RED, swap parent and sibling colors, rotate parent in DB's direction, and repeat analysis for node:
        this.colorSwap(parent,sibling);
        if(this.isLeftChild(sibling)) { this.rightRotation(parent); }
        else { this.leftRotation(parent); }
        this.fixDoubleBlack(node);
      }
      else {//As sibling is BLACK, we have three cases that can be applied:
        if(this.anyRedChild(sibling)){//1-: sibling has at least one RED child
          if(this.isLeftChild(sibling)){//sibling is left child
            if(sibling.left && sibling.left.color === 'RED'){//DB's far nephew is RED:
              //swap parent and sibling colors, rotate parent in DB's direction and color sibling's child black:
              console.log(`>>>> DBs is right child and far nephew (${sibling.left.value}) is RED <<<<`);
              
              this.colorSwap(parent,sibling); // ## FUNCTIONAL ##
              this.colorSwitch(sibling.left); // ## FUNCTIONAL ##
              this.rightRotation(parent); // ## FUNCTIONAL ##
              
              //this.levelOrderTraversal(); //testing
            }
            else {//DB's far nephew is either BLACK or NIL
              this.colorSwap(sibling,sibling.right);
              this.leftRotation(sibling);
              this.fixDoubleBlack(node);
            }
          }
          else {//sibling is right child
            if(sibling.right && sibling.right.color === 'RED'){
              this.colorSwap(parent,sibling);
              this.colorSwitch(sibling.right);
              this.leftRotation(parent);
            }
            else {
              this.colorSwap(sibling,sibling.left);
              this.rightRotation(sibling);
              this.fixDoubleBlack(node);
            }
          }
        } 
        else {//3-: sibling has only BLACK/NIL children
          console.log(`>>>> DB (${node.value}) sibling (${sibling.value}) is BLACK and doesn't have any children <<<<`);
          this.colorSwitch(sibling);//console.log(parent)
          if(parent.color === 'BLACK') { this.fixDoubleBlack(parent);}
          else { 
            parent.color = 'BLACK';
          }
          //console.log(parent)
          //parent.left = null; //node.parent = null;
        }
      }
    }
  }
  // -----------------------------------------------------------<<
  // ---------------------- SUPPORT METHODS -------------------->>
  colorSwitch(node){//inverts the color of the node, if it was RED, becomes BLACK
    let tempNode = node;
    tempNode.color = (node.color === 'RED') ? 'BLACK' : 'RED';
  }
  colorSwap(node1, node2){//swaps the colors of the passed nodes
    let temp = node1.color;
    node1.color = node2.color;
    node2.color = temp;
  }
  valueSwap(node1, node2){//swaps the values of the passed nodes
    let temp = node1.value;
    node1.value = node2.value;
    node2.value = temp;
  }
  getSuccessor(node){//gets the inorder predecessor of the node passed as argument
    let successor = node.left; 
    while (successor.right !== null) { successor = successor.right; }
    return successor;
  }
  getSibling(node){//gets the sibling of the node passed as argument
    let sibling = null;
    sibling = (node === node.parent.left) ? node.parent.right : node.parent.left;
    return sibling;
  }
  isLeftChild(node){//returns a boolean indicating if the node passed as argument is a left child
    return ((node === node.parent.left) ? true : false);
  }
  anyRedChild(node){//returns a boolean indicating if the node passed as argument has a RED child
    return ((node.left && node.left.color === 'RED') || (node.right && node.right.color === 'RED'));
  }
  // -----------------------------------------------------------<<
  // --------------------- ROTATION METHODS -------------------->> 
  rightRotation(node) {//LL condition --> Right Rotation
    console.log(`>>>> Right rotation on (${node.value}) <<<<`);

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
  // -----------------------------------------------------------<<
  // --------------------- TRAVERSAL METHODS ------------------->>
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
  // -----------------------------------------------------------<<
}
let rbTree = new redBlackTree();

rbTree.insert(42);
rbTree.insert(10);
rbTree.insert(64);
rbTree.insert(7);
rbTree.insert(29);
rbTree.insert(50);
rbTree.insert(83);
rbTree.insert(5); 
rbTree.insert(31);

console.log(rbTree);

rbTree.remove(42); //PASSED
rbTree.remove(29); //PASSED
rbTree.remove(7);  //PASSED
rbTree.remove(5);  //PASSED
rbTree.remove(83); //PASSED
rbTree.remove(10); //PASSED

rbTree.inOrderTraversal();
rbTree.levelOrderTraversal();

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
// rbTree.insert(10);
// rbTree.insert(18);
// rbTree.insert(7);
// rbTree.insert(15);
// rbTree.insert(16);
// rbTree.insert(30);
// rbTree.insert(25);
// rbTree.insert(40); 
// rbTree.insert(60);
// rbTree.insert(2);
// rbTree.insert(1);
// rbTree.insert(70);
