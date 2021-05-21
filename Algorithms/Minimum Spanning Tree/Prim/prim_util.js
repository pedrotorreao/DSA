/****************************************************************/
/* Utility functions for the Prim Algorithm ********/
/****************************************************************/

/****************************************************************/
/************************** Min Heap ****************************/
class minHeap {
  constructor() {
    this.heap = [];
  }

  peek() {
    let top = this.heap[1] ? this.heap[1][0] : null;

    return top;
  }

  insert(value) {
    if (this.heap.length < 1) {
      //if heap is empty, set first array element to null and push value to the end:
      this.heap[0] = null;
      this.heap.push(value);
      return;
    }
    this.heap.push(value);

    this.heapifyBottomTopRecursively();
  }

  heapifyBottomTopRecursively(index = this.heap.length - 1) {
    let parentIndex = Math.floor(index / 2);
    //in case we've reached the root of the heap, return:
    if (!this.heap[parentIndex]) return;

    //if parent value is greater than the newly added element, swap them and go up in the heap:
    if (this.heap[parentIndex][1] > this.heap[index][1]) {
      this.swapValues(index, parentIndex);
      index = parentIndex;
      this.heapifyBottomTopRecursively(index);
    } else {
      return;
    }
  }

  // ------------ MIN HEAP: DELETION METHODS ------------------->>
  remove() {
    if (this.heap.length <= 1) {
      return null;
    } //heap is empty.

    //Replaces top element by the last element in the heap:
    if (this.heap.length - 1 > 1) {
      //??
      this.swapValues(this.heap.length - 1, 1);
    }
    let smallest = this.heap.pop(); //stores the top element being deleted in case we need it for heap sort

    //this.heap[this.heap.length - 1] = null; //so we don't have to deal with undefined values when heapifying

    this.heapifyTopBottomRecursively();
    return smallest;
  }

  heapifyTopBottomRecursively(rootIndex = 1) {
    if (!this.heap[rootIndex]) {
      return;
    }

    let leftIndex, rightIndex;
    leftIndex = 2 * rootIndex;
    rightIndex = 2 * rootIndex + 1;

    /*if there are no children, return. Reminder: as the heap must be a complete binary tree, all its levels are filled except possibly for the last, and in the last level, all the keys/values are aligned as left as possible, so if a node doesn't have a left child, it won't have a right child since the left subtree would be filled first:*/
    if (!this.heap[leftIndex]) {
      return;
    }

    if (
      (this.heap[leftIndex] &&
        this.heap[rootIndex][1] > this.heap[leftIndex][1]) ||
      (this.heap[rightIndex] &&
        this.heap[rootIndex][1] > this.heap[rightIndex][1])
    ) {
      //if there's no right child or left child's value is less than right child's, swap subtrees' root and left child's values  and go down the heap:
      if (
        !this.heap[rightIndex] ||
        this.heap[leftIndex][1] < this.heap[rightIndex][1]
      ) {
        this.swapValues(rootIndex, leftIndex);
        rootIndex = leftIndex;
      } else {
        this.swapValues(rootIndex, rightIndex);
        rootIndex = rightIndex;
      }
      this.heapifyTopBottomRecursively(rootIndex);
    }
  }

  swapValues(child, parent) {
    let temp = this.heap[child];
    this.heap[child] = this.heap[parent];
    this.heap[parent] = temp;
  }
  getSize() {
    return this.heap.length - 1;
  }
}

/****************************************************************/
/*********************** Priority Queue *************************/
class priorityQueue extends minHeap {
  constructor() {
    super();
    this.priorityQ = new minHeap();
  }
}

// export modules for Piority Queue:
module.exports.priorityQueue = priorityQueue;
