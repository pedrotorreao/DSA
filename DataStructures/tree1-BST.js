/****************************************************************/
/*Problem: Tree Exercise (BST)  ********/
/****************************************************************/
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
      //currentNode.left = node;
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
  
    /*
  -- remove(value) method: We must preserve the BST relationship between nodes. The greates challenge is when the node you want to remove has a right child which has a left child, because it is then that you have to search for the leftmost node.
    a. if the node to be removed does not have a right child it can be removed directly, but remember to update the references.
    b. if the node to be removed has a right child which DOES NOT have a left child, it can also be removed directly, but remember to update the references.
    c. if the node to be removed has a right child which DOES have a left child, we have to find its leftmost node and use replace the node being removed with this node. The tricky part here is to update the references correctly.
  */
  remove(value) {
    if (this.root === null) {
      console.log(`Tree is empty.`);
      return;
    } else {
      let currentNode = this.root;
      let parentNode = null;
      while (currentNode) {
        if (value < currentNode.value) {
          parentNode = currentNode;
          currentNode = currentNode.left;
        } else if (value > currentNode.value) {
          parentNode = currentNode;
          currentNode = currentNode.right;
        } else if (currentNode.value === value) {
      
        //a. If the node being removed does not have a right child it can be removed directly:
          if (currentNode.right === null) {
            //If parentNode is still null, it means the node being deleted is the root and, as there is no right tree, replace it with its left node.
            if (parentNode === null) {
              this.root = currentNode.left;
            }
            else {
              //if the value being removed is at the left of its parent, update its parent left reference to point to the node's left child (it doesn't matter if there is a left child or if it is null).
              if (currentNode.value < parentNode.value) {
                parentNode.left = currentNode.left;
              }
              //if the value being removed is at the right of its parent, update its parent right reference to point to the node's left child (it doesn't matter if there is a left child or if it is null).
              else if (currentNode.value > parentNode.value) {
                parentNode.right = currentNode.left;
              }
            }
            return;
          } 
        //b. If the node being removed has a right child which DOES NOT have a left child, it can also be removed directly, but remember to update the references.
          else if (currentNode.right.left === null) {
            //since in this case "currentNode" will be replaced by "currentNode.right", the reference to "currentNode.left" must be updated to "currentNode.right.left" (it doesn't matter if there is a "currentNode.left" or if it is null), which is available.
            currentNode.right.left = currentNode.left;
            //If parentNode is still null, it means the node being deleted is the root and, as there is no right tree, replace it with its left node.
            if (parentNode === null) {
              this.root = currentNode.left;
            }
            else {
              //if the value being removed is at the left of its parent, update its parent left reference to point to the node's right child (it doesn't matter if there is a left child or if it is null).
              if (currentNode.value < parentNode.value) {
                parentNode.left = currentNode.right;
              }
              //if the value being removed is at the right of its parent, update its parent right reference to point to the node's right child (it doesn't matter if there is a left child or if it is null).
              else if (currentNode.value > parentNode.value) {
                parentNode.right = currentNode.right;
              }
            }
            return;
          }
        //c. If the node to be removed has a right child which DOES have a left child, we have to find its leftmost node and use replace the node being removed with this node. The tricky part here is to update the references correctly.
          else {
            //In this case, we need to keep track of the "currentNode.right" leftmost node, which will be used to replace the value being removed. Initially, this leftmost node is equal to "currentNode.right.left".
            let leftmost = currentNode.right.left;

            //As we'll need to update the references which point to the node that will be used to replace the node being removed, we also need to keep track of its parent node, which initially will be equal to "currentNode.right".
            let leftmostParent = currentNode.right;

            //Traverse the "currentNode.right" left tree until we find the leftmost node.
            while (leftmost.left !== null) {
              leftmostParent = leftmost;
              leftmost = leftmost.left;
            }

            //As we use the leftmost node value to replace the node being removed (currentNode), we still need to keep track of its right reference "leftmost.right" (it doesn't matter if there is a right child or if it is null). Therefore, we update the parent node left reference "leftmostParent.left" which now is free since we used "leftmost" to replace "currentNode" to point to "leftmost.right" so nothing is left out.
            leftmostParent.left = leftmost.right;

            //Now we can update the "leftmost" references to point to the "currentNode" references.
            leftmost.right = currentNode.right;
            leftmost.left = currentNode.left;

            //If parentNode is still null, it means the node being deleted is the root and, as there is no right tree, replace it with its left node.
            if (parentNode === null) {
              this.root = leftmost;
            }
            else {
              //if the value being removed is at the left of its parent, update its parent left reference to point to the node's left child.
              if (currentNode.value < parentNode.value) {
                parentNode.left = leftmost;
              }
              //if the value being removed is at the right of its parent, update its parent right reference to point to the node's left child.
              else if (currentNode.value > parentNode.value) {
                parentNode.right = leftmost;
              }
            }
            return;
          }
        }
      }
    }
    return `${value} is not in the tree.`;
  }
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

//Look for nodes:
console.log(tree.lookup(20));
//console.log(tree.lookup(1));
//console.log(tree.lookup(9));
//console.log(tree.lookup(170));
//console.log(tree.lookup(55));

//Remove nodes:
//--Testing case (a):
// tree.remove(170);
// console.log(tree.lookup(170));
// console.log(tree);

//--Testing case (b):
// tree.remove(20);
// console.log(tree.lookup(20));
// console.log(tree);

//--Testing case (c):
tree.remove(9);
console.log(tree.lookup(9));
console.log(tree);