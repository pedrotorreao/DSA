/****************************************************************/
/*Priority Queue - Min Heap ********/
/****************************************************************/
class minHeap {
  constructor() {
    this.heap = [];
  }

  // ------------ MIN HEAP: PEEK METHOD ------------------------>>
  peek() {
    return this.heap[1][0];
  }

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
  }
  heapifyBottomTopRecursively(index=this.heap.length-1) {
      let parentIndex = Math.floor(index/2);
      //in case we've reached the root of the heap, return:
      if(!this.heap[parentIndex]) return;

      //if parent value is greater than the newly added element, swap them and go up in the heap:
      if(this.heap[parentIndex][1] > this.heap[index][1]) {
        this.swapValues(index, parentIndex);
        index = parentIndex;
        this.heapifyBottomTopRecursively(index);
      }
      else { return; }
  }

  // ------------ MIN HEAP: DELETION METHODS ------------------->>
  remove() {
    if(this.heap.length <= 1) { return; }//heap is empty.

    //Replaces top element by the last element in the heap:
    this.swapValues(this.heap.length-1,1);
    let largest = this.heap.pop(); //stores the top element being deleted in case we need it for heap sort

    this.heapifyTopBottomRecursively();
    return largest;
  }

  heapifyTopBottomRecursively(rootIndex=1) {
    if(!this.heap[rootIndex]) { return; }

    let leftIndex, rightIndex;
    leftIndex = 2*rootIndex;
    rightIndex = (2*rootIndex)+1;

    /*if there are no children, return. Reminder: as the heap must be a complete binary tree, all its levels are filled except possibly for the last, and in the last level, all the keys/values are aligned as left as possible, so if a node doesn't have a left child, it won't have a right child since the left subtree would be filled first:*/
    if(!this.heap[leftIndex]) { return; }

    if(this.heap[rootIndex][1] > this.heap[leftIndex][1] || this.heap[rootIndex][1] > this.heap[rightIndex][1]) {
      //if there's no right child or left child's value is less than right child's, swap subtrees' root and left child's values  and go down the heap:
      if(!this.heap[rightIndex] || this.heap[leftIndex][1] < this.heap[rightIndex][1]) {
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
class priorityQueue extends minHeap{
  constructor() {
    super();
    this.priorityQ = new minHeap();
  }
}
const priorityQ = new priorityQueue();

priorityQ.insert(['Send report copies',10]);
priorityQ.insert(['Daily meeting',15]);
priorityQ.insert(['Answer email from RH',9]);
priorityQ.insert(['Discuss new app with team',23]);
priorityQ.insert(['Refactor createReport()',34]);
priorityQ.insert(['Grab coffee',55]);
priorityQ.insert(['Walk the dog',67]);
priorityQ.insert(['Finish feature #9283',1]);

console.log('Tasks for today: ', priorityQ.getSize());
console.log('Highest priority: ', priorityQ.peek());

priorityQ.remove();

console.log('Tasks for today: ', priorityQ.getSize());
console.log('Highest priority: ', priorityQ.peek());


console.log(priorityQ);