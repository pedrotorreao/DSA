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

    while(Heap.getSize()) {
      sortedArray.push(Heap.remove());
    }

    return sortedArray;
  }
}
let array = [10,15,9,23,34,55,67,1];
let sortedArray = new HeapSort(array);

console.log(sortedArray);
