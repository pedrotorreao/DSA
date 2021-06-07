/****************************************************************/
/*Problem: Binary Search Tree w/ arrays  ********/
/****************************************************************/

//Left child: cell[2x]
//Right child: cell[2x + 1]
class BinarySearchTree {
  constructor(size){
    this.treeArr = new Array(size+1);
    this.lastIndex = 0;
    this.treeLength = 0;
  }
  insert(value){
    if (this.treeArr[this.treeArr.length - 1] !== undefined) {
      return null;
    } 
    if (this.treeArr[1] === undefined) {
      this.treeArr[1] = value;
      this.lastIndex = 1;
      return;
    } else {
      const searchTree = function(current, arr) {
        if (value < arr[current]) {
          if (arr[2*current] === undefined) {
            arr[2*current] = value;
            return;
          }
          return searchTree(current*2,arr);
        } else if (value > arr[current]) {
          if (arr[2*current + 1] === undefined) {
            arr[2*current + 1] = value;
            return;
          }
          searchTree(2*current+1,arr);
        }
        else {
          return null;
        }
      };
      return searchTree(this.lastIndex,this.treeArr);
    }
  }
  lookup(value){
    for (let i = 0; i < this.treeArr.length; i++) {
      if (this.treeArr[i] === value) {
        console.log(`Value ${value} is in position ${i}`);
        return;
      }
    }
    console.log(`${value} is not on the tree.`);
  }
  //remove method:
  remove(value) {
    const removeNode = function(arr,current,value) {
      if (arr[current] === null) {//tree is empty
        return null;
      }
      if (arr[current] === value) {
        if ((arr[2*current] === undefined) && (arr[2*current + 1] === undefined)) {//no child
          arr[current] = null;
          return;
        }
        if ((arr[2*current] === undefined)) { //no left child
          arr[current] = arr[2*current + 1];

          while(arr[(2*current + 1)] !== undefined) {
            arr[2*current + 1] = arr[2*(2*current + 1)+1];
            current++;
          }
          return;
        }
        if ((arr[2*current + 1] === undefined)) { //no right child
          arr[current] = arr[2*current];

          while(arr[(2*current)] !== undefined) {
            arr[2*current] = arr[2*(2*current)];
            current++;
          }
          return;
        }
        //both childs:
        let temp = 2*current + 1; //go to the right child's position 
        while(arr[temp*2] !== undefined) {//from the right child's position, go to its leftmost child
          temp = temp*2;
        }
        arr[current] = arr[temp];//replace node being removed by its right child leftmost node

        while(arr[temp] !== undefined) {//reorganize the tree to avoid duplicate elements
          arr[temp] = arr[temp*2];
          temp*2;
        }
      }
      else if (value < arr[current]) {//go left if value we want to remove is less than the current value
        return removeNode(arr,current*2,value);
      }
      else if (value > arr[current]) {//go right if value we want to remove is greater than the current value
        return removeNode(arr,(current*2 + 1),value);
      }
      else {//in case the value is not on the tree
        console.log(`${value} is not on the tree.`);
        return null;
      }
    }
    return removeNode(this.treeArr,this.lastIndex,value);
  }
}
/*       9
      /     \
    4       20
  /  \     /  \
1     6  15  170
*/
const tree = new BinarySearchTree(8);
tree.insert(9);
tree.insert(4);
tree.insert(20);
tree.insert(1);
tree.insert(15);
tree.insert(6);
tree.insert(170);
tree.insert(0);
console.log(tree);
tree.lookup(15);
tree.lookup(4);
tree.lookup(55);
tree.remove(9);
console.log(tree);