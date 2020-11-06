/****************************************************************/
/*Trees - Heaps: Min Heap  ********/
/****************************************************************/
class minHeap {
  constructor() {
    this.heap = [];
  }
  lookup(value) {

  }
  insert(value) {
    if(this.heap.length < 1) {
      this.heap[0] = null;
      this.heap.push(value); return;
    }
    this.heap.push(value);

    let index = this.heap.length-1;

    this.fixHeapRecursively(index);
    //this.fixHeapIteratively();
  }
  remove(value) {

  }
  fixHeapRecursively(index) {
      let parentIndex = Math.floor(index/2);
      if(this.heap[parentIndex] > this.heap[index]) {
        this.swapValues(index, parentIndex);
        index = parentIndex;
        this.fixHeapRecursively(index);
      }
      else { return; }
  }
  fixHeapIteratively() {
    let index = this.heap.length-1;
    let parentIndex;
    while(index >= 1){
      parentIndex = Math.floor(index/2);
      if(this.heap[parentIndex] > this.heap[index]) {
        this.swapValues(index, parentIndex);
        index = parentIndex;
      }
      else { return; }
    }
  }
  
  
  traverse() {

  }
  // -----------------------------------------------------------<<
  // ---------------------- SUPPORT METHODS -------------------->>
  swapValues(child, parent) {
    let temp = this.heap[child];
    this.heap[child] = this.heap[parent];
    this.heap[parent] = temp;
  }
  getSize() {
    return this.heap.length;
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
console.log(Heap.getSize());

console.log(Heap);