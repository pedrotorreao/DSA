/****************************************************************/
/* Problem: Binary Search Tree - BFS and DFS Traversal ********/
/****************************************************************/
/**
 * Summary:
 *    Complete the given BinarySearchTree class with the BFS and DFS
 *    traversal methods.
 */

/* * * * * * * * PROVIDED * * * * * * * */
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
    const newNode = new Node(value);
    if (this.root === null) {
      this.root = newNode;
    } else {
      let currentNode = this.root;
      while (true) {
        if (value < currentNode.value) {
          //Left
          if (!currentNode.left) {
            currentNode.left = newNode;
            return this;
          }
          currentNode = currentNode.left;
        } else {
          //Right
          if (!currentNode.right) {
            currentNode.right = newNode;
            return this;
          }
          currentNode = currentNode.right;
        }
      }
    }
  }
  lookup(value) {
    if (!this.root) {
      return false;
    }
    let currentNode = this.root;
    while (currentNode) {
      if (value < currentNode.value) {
        currentNode = currentNode.left;
      } else if (value > currentNode.value) {
        currentNode = currentNode.right;
      } else if (currentNode.value === value) {
        return currentNode;
      }
    }
    return null;
  }
  remove(value) {
    if (!this.root) {
      return false;
    }
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
        //We have a match, get to work!

        //Option 1: No right child:
        if (currentNode.right === null) {
          if (parentNode === null) {
            this.root = currentNode.left;
          } else {
            //if parent > current value, make current left child a child of parent
            if (currentNode.value < parentNode.value) {
              parentNode.left = currentNode.left;

              //if parent < current value, make left child a right child of parent
            } else if (currentNode.value > parentNode.value) {
              parentNode.right = currentNode.left;
            }
          }

          //Option 2: Right child which doesnt have a left child
        } else if (currentNode.right.left === null) {
          if (parentNode === null) {
            this.root = currentNode.left;
          } else {
            currentNode.right.left = currentNode.left;

            //if parent > current, make right child of the left the parent
            if (currentNode.value < parentNode.value) {
              parentNode.left = currentNode.right;

              //if parent < current, make right child a right child of the parent
            } else if (currentNode.value > parentNode.value) {
              parentNode.right = currentNode.right;
            }
          }

          //Option 3: Right child that has a left child
        } else {
          //find the Right child's left most child
          let leftmost = currentNode.right.left;
          let leftmostParent = currentNode.right;
          while (leftmost.left !== null) {
            leftmostParent = leftmost;
            leftmost = leftmost.left;
          }

          //Parent's left subtree is now leftmost's right subtree
          leftmostParent.left = leftmost.right;
          leftmost.left = currentNode.left;
          leftmost.right = currentNode.right;

          if (parentNode === null) {
            this.root = leftmost;
          } else {
            if (currentNode.value < parentNode.value) {
              parentNode.left = leftmost;
            } else if (currentNode.value > parentNode.value) {
              parentNode.right = leftmost;
            }
          }
        }
        return true;
      }
    }
  }
  /* * * * * * * * INSERT SOLUTION BELOW THIS LINE * * * * * * * */
  BreadthFirstSearch() {
    let currentNode = this.root;
    let list = [];
    let queue = [];
    queue.push(currentNode);

    while (queue.length > 0) {
      currentNode = queue.shift();
      list.push(currentNode.value);
      if (currentNode.left) {
        queue.push(currentNode.left);
      }
      if (currentNode.right) {
        queue.push(currentNode.right);
      }
    }
    return list;
  }

  BreadthFirstSearchRec(queue = [this.root], list = []) {
    if (!queue.length) {
      return list;
    }

    let currentNode = queue.shift();
    list.push(currentNode.value);

    if (currentNode.left) {
      queue.push(currentNode.left);
    }
    if (currentNode.right) {
      queue.push(currentNode.right);
    }

    return this.BreadthFirstSearchRec(queue, list);
  }

  DepthFirstSearchInOrder(currentNode = this.root, list = []) {
    if (!currentNode) {
      return list;
    }
    this.DepthFirstSearchInOrder(currentNode.left, list);
    list.push(currentNode.value);
    return this.DepthFirstSearchInOrder(currentNode.right, list);
  }

  DepthFirstSearchPreOrder(currentNode = this.root, list = []) {
    if (!currentNode) {
      return list;
    }
    list.push(currentNode.value);
    this.DepthFirstSearchPreOrder(currentNode.left, list);
    return this.DepthFirstSearchPreOrder(currentNode.right, list);
  }

  DepthFirstSearchPostOrder(currentNode = this.root, list = []) {
    const postOrder = function (currentNode, list) {
      if (!currentNode) {
        return list;
      }
      if (currentNode.left) postOrder(currentNode.left, list);
      if (currentNode.right) postOrder(currentNode.right, list);
      list.push(currentNode.value);
      return list;
    };
    return postOrder(currentNode, list);
  }
  /* * * * * * * * INSERT SOLUTION ABOVE THIS LINE * * * * * * * */
  isValidBST(currentNode = this.root, list = []) {
    const inOrder = this.DepthFirstSearchInOrder(currentNode);

    let temp = inOrder[0];
    for (let i = 1; i < inOrder.length; i++) {
      if (temp > inOrder[i]) {
        return false;
      }
      temp = inOrder[i];
    }
    return true;
  }
}

const tree = new BinarySearchTree();
tree.insert(9);
tree.insert(4);
tree.insert(6);
tree.insert(20);
tree.insert(170);
tree.insert(15);
tree.insert(1);
/* * * Tree * * *
     9
  4     20
1  6  15  170
* * * * * * * * /

/* * * * * * * * TEST CASES * * * * * * * */
/* (1) expected output: 9 4 20 1 6 15 170 */
console.log("BFS", tree.BreadthFirstSearch());

/* (2) expected output: 9 4 20 1 6 15 170 */
console.log("BFS Rec.", tree.BreadthFirstSearchRec());

/* (3) expected output: 1 4 6 9 15 20 170 */
console.log("DFS In-Order", tree.DepthFirstSearchInOrder());

/* (4) expected output: 9 4 1 6 20 15 170 */
console.log("DFS Pre-Order", tree.DepthFirstSearchPreOrder());

/* (5) expected output: 1 6 4 15 170 20 9 */
console.log("DFS Post-Order", tree.DepthFirstSearchPostOrder());

console.log(tree.isValidBST());
