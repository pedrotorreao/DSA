/****************************************************************/
/*Trees - Heaps: Max Heap  ********/
/****************************************************************/
class maxHeap {
  constructor() {
    this.heap = [];
  }
  // -----------------------------------------------------------<<
  // ------------ MAX HEAP: PEEK METHOD ------------------------>>
  peek() {
    return this.heap[1];
  }

  // -----------------------------------------------------------<<
  // ------------ MAX HEAP: INSERTION METHODS ------------------>>
  insert(value) {
    if(this.heap.length < 1) {
      this.heap[0] = null;
      this.heap.push(value);
      return;
    }
    this.heap.push(value);
    this.fixInsertRecursively();
    // this.fixInsertIteratively();
  }
  fixInsertRecursively(index=this.heap.length-1) {
      let parentIndex = Math.floor(index/2);
      if(!this.heap[parentIndex]) return;

      if(this.heap[parentIndex] < this.heap[index]) {
        this.swapValues(index, parentIndex);
        index = parentIndex;
        this.fixInsertRecursively(index);
      }
      else { return; }
  }
  fixInsertIteratively() {
    let index = this.heap.length-1;
    let parentIndex;
    while(index >= 1){
      parentIndex = Math.floor(index/2);
      if(!this.heap[parentIndex]) return;
      if(this.heap[parentIndex] < this.heap[index]) {
        this.swapValues(index, parentIndex);
        index = parentIndex;
      }
      else { return; }
    }
  }

  // -----------------------------------------------------------<<
  // ------------ MAX HEAP: DELETION METHODS ------------------->>
  
  remove() {
    if(this.heap.length <= 1) { return; }

    this.swapValues(this.heap.length-1,1); //Replaces top element by the last element in the heap
    this.heap.pop();

    // this.fixRemoveIteratively();
    this.fixRemoveRecursively();
  }
  
  fixRemoveIteratively() {
    let rootIndex, leftIndex, rightIndex;

    rootIndex = 1;
    leftIndex = 2*rootIndex;
    rightIndex = (2*rootIndex)+1;

    while(this.heap[rootIndex] < this.heap[leftIndex] || this.heap[rootIndex] < this.heap[rightIndex]) {
      if(this.heap[leftIndex] > this.heap[rightIndex]) {
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

  fixRemoveRecursively(rootIndex=1) {
    if(!this.heap[rootIndex]) { return; }

    let leftIndex, rightIndex;

    leftIndex = 2*rootIndex;
    rightIndex = (2*rootIndex)+1;

    if(this.heap[rootIndex] < this.heap[leftIndex] || this.heap[rootIndex] < this.heap[rightIndex]) {
      if(this.heap[leftIndex] > this.heap[rightIndex]) {
        this.swapValues(rootIndex, leftIndex);
        rootIndex = leftIndex;
      }
      else {
        this.swapValues(rootIndex, rightIndex);
        rootIndex = rightIndex;
      }
      this.fixRemoveRecursively(rootIndex);
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
const Heap = new maxHeap();

Heap.insert(10);
Heap.insert(15);
Heap.insert(9);
Heap.insert(23);
Heap.insert(34);
Heap.insert(55);
Heap.insert(67);
Heap.insert(1);

console.log('Max Heap size: ', Heap.getSize());
console.log('Max/Top element: ', Heap.peek());

Heap.remove();

console.log('Max Heap size: ', Heap.getSize());
console.log('Max/Top element: ', Heap.peek());

console.log(Heap);