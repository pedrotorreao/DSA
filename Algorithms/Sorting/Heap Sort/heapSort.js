/****************************************************************/
/*Heap Sort - Increasing order (Min heap)  ********/
/****************************************************************/
//Note: it uses minHeap class on '../../../DataStructures/Heaps/minHeap.js'.
class HeapSort {
  constructor(unsortedArray) {
    let sortedArray = [];
    const Heap = new minHeap();

    unsortedArray.forEach((element) => {
      Heap.insert(element);
    });

    /* 
    When removing an element in a heap, we always remove the top element. As in this case we have a min heap, the top element is always the smallest element in the heap. If every time we remove an element from the heap, we return the deleted value and add it to an array, in the end we'll have created a sorted array in incresing order.
    */
    while(Heap.getSize()) {
      sortedArray.push(Heap.remove());
    }

    return sortedArray;
  }
}
let array = [10,15,9,23,34,55,67,1];
let sortedArray = new HeapSort(array);

console.log(sortedArray);
