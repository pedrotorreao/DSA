/****************************************************************/
/*Trees - Heaps: Min Heap  ********/
/****************************************************************/
class minHeap {
  constructor() {
    this.heap = [];
  }
  // -----------------------------------------------------------<<
  // ------------ MIN HEAP: PEEK METHOD ------------------------>>
  peek() {
    return this.heap[1];
  }

  // -----------------------------------------------------------<<
  // ------------ MIN HEAP: INSERTION METHODS ------------------>>
  insert(value) {
    if(this.heap.length < 1) {
      //if heap is empty, set first array element to null and push value to the end:
      this.heap[0] = null;
      this.heap.push(value);
      return;
    }
    this.heap.push(value);

    this.heapifyBottomTopRecursively();
    //this.heapifyBottomTopIteratively();
  }
  heapifyBottomTopRecursively(index=this.heap.length-1) {
      let parentIndex = Math.floor(index/2);
      //in case we've reached the root of the heap, return:
      if(!this.heap[parentIndex]) return;

      //if parent value is greater than the newly added element, swap them and go up in the heap:
      if(this.heap[parentIndex] > this.heap[index]) {
        this.swapValues(index, parentIndex);
        index = parentIndex;
        this.heapifyBottomTopRecursively(index);
      }
      else { return; }
  }
  heapifyBottomTopIteratively() {
    let index = this.heap.length-1;
    let parentIndex;
    while(index >= 1){
      parentIndex = Math.floor(index/2);
      //in case we've reached the root of the heap, return:
      if(!this.heap[parentIndex]) return;

      //if parent value is greater than the newly added element, swap them and go up in the heap:
      if(this.heap[parentIndex] > this.heap[index]) {
        this.swapValues(index, parentIndex);
        index = parentIndex;
      }
      else { return; }
    }
  }

  // -----------------------------------------------------------<<
  // ------------ MIN HEAP: DELETION METHODS ------------------->>
  
  remove() {
    if(this.heap.length <= 1) { return; }//heap is empty.

    //Replaces top element by the last element in the heap:
    this.swapValues(this.heap.length-1,1);
    let largest = this.heap.pop();

    this.heapifyTopBottomIteratively();
    //this.heapifyTopBottomRecursively();
    return largest;
  }
  
  heapifyTopBottomIteratively() {
    let rootIndex, leftIndex, rightIndex;

    rootIndex = 1;
    leftIndex = 2*rootIndex;
    rightIndex = (2*rootIndex)+1;

    /*if there are no children, return. Reminder: as the heap must be a complete binary tree, all its levels are filled except possibly for the last, and in the last level, all the keys/values are aligned as left as possible, so if a node doesn't have a left child, it won't have a right child since the left subtree would be filled first:*/
    if(!this.heap[leftIndex]) { return; }

    while(this.heap[rootIndex] > this.heap[leftIndex] || this.heap[rootIndex] > this.heap[rightIndex]) {
      //if there's no right child or left child's value is less than right child's, swap subtrees' root and left child's values  and go down the heap:
      if(!this.heap[rightIndex] || this.heap[leftIndex] < this.heap[rightIndex]) {
        this.swapValues(rootIndex, leftIndex);
        rootIndex = leftIndex;
      }
      else {
        this.swapValues(rootIndex, rightIndex);
        rootIndex = rightIndex;
      }
      leftIndex = 2*rootIndex;
      rightIndex = (2*rootIndex)+1;

      if(this.heap[rootIndex] === undefined) return;
    }
  }

  heapifyTopBottomRecursively(rootIndex=1) {
    if(!this.heap[rootIndex]) { return; }

    let leftIndex, rightIndex;
    leftIndex = 2*rootIndex;
    rightIndex = (2*rootIndex)+1;

    /*if there are no children, return. Reminder: as the heap must be a complete binary tree, all its levels are filled except possibly for the last, and in the last level, all the keys/values are aligned as left as possible, so if a node doesn't have a left child, it won't have a right child since the left subtree would be filled first:*/
    if(!this.heap[leftIndex]) { return; }

    if(this.heap[rootIndex] > this.heap[leftIndex] || this.heap[rootIndex] > this.heap[rightIndex]) {
      //if there's no right child or left child's value is less than right child's, swap subtrees' root and left child's values  and go down the heap:
      if(!this.heap[rightIndex] || this.heap[leftIndex] < this.heap[rightIndex]) {
        this.swapValues(rootIndex, leftIndex);
        rootIndex = leftIndex;
      }
      else {
        this.swapValues(rootIndex, rightIndex);
        rootIndex = rightIndex;
      }
      this.heapifyTopBottomRecursively(rootIndex);
    }
  }
  
  // -----------------------------------------------------------<<
  // ---------------------- SUPPORT METHODS -------------------->>
  swapValues(child, parent) {
    let temp = this.heap[child];
    this.heap[child] = this.heap[parent];
    this.heap[parent] = temp;
  }
  getSize() {
    return this.heap.length-1;
  }
}
const Heap = new minHeap();

Heap.insert(10);
Heap.insert(15);
Heap.insert(9);
Heap.insert(23);
Heap.insert(34);
Heap.insert(55);
Heap.insert(67);
Heap.insert(1);

console.log('Min Heap size: ', Heap.getSize());
console.log('Min/Top element: ', Heap.peek());

Heap.remove();
Heap.remove();
Heap.remove();

console.log('Min Heap size: ', Heap.getSize());
console.log('Min/Top element: ', Heap.peek());

console.log(Heap);