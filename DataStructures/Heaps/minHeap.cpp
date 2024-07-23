/****************************************************************/
/*Trees - Heaps: Min Heap C++ ********/
/****************************************************************/
#include <iostream>
#include <limits.h>
#include <math.h>
#include <vector>

class MinHeap {
private:
  std::vector<int> minHeap;

public:
  int peek(void);

  void insertElement(int value);
  void heapifyBottomTop(void);

  void removeMin(void);
  void heapifyTopBottom(int parentIndex = 1);

  void swapValues(int indexNew, int indexParent);
  int heapSize(void);

  MinHeap() {
    // element at position heap[0] does not count:
    minHeap.push_back(0);
  }
  ~MinHeap() {}
};

int MinHeap::peek(void) {
  return minHeap.at(1);
}

void MinHeap::insertElement(int value) {
  // add new element to the first empty node at the bottommost leftmost /// empty position (aka the end of the array):
  this->minHeap.push_back(value);

  // check if the newly added element is violating the heap properties,
  // if it is, bubble it up:
  heapifyBottomTop();
}

void MinHeap::heapifyBottomTop(void) {
  int newElementIndex = this->minHeap.size() - 1; // last element
  int parentIndex;

  while (newElementIndex >= 1) // if we get to the root, we're done.
  {
    parentIndex = floor(newElementIndex / 2);

    if (!this->minHeap.at(parentIndex) || parentIndex == 0)
      return;

    // if parent.value > child.value: swap them and update the index
    // of the node being bubbled down to the parent swapped:
    if (this->minHeap.at(parentIndex) > this->minHeap.at(newElementIndex)) {
      swapValues(newElementIndex, parentIndex);
      newElementIndex = parentIndex;
    }
    // there is no violation, i.e. parent.value < child.value:
    else {
      return;
    }
  }
}

void MinHeap::removeMin(void) {
  if (minHeap.size() < 2) // heap is empty
    return;

  // replace top element being removed by the last element in the heap:
  swapValues(minHeap.size() - 1, 1);

  // remove top element from the heap:
  minHeap.pop_back();

  // check if the swapped element is violating the heap properties,
  // if it is, bubble it down:
  heapifyTopBottom();
}

void MinHeap::heapifyTopBottom(int parentIndex) {
  if (!minHeap.at(parentIndex) || parentIndex == 0)
    return;

  int leftChildIndex = 2 * parentIndex;
  int rightChildIndex = (2 * parentIndex) + 1;

  // verify if the calculated index for the left child is not
  // exceeding the heap dimensions, if it is, there is no left
  // child and subsequently no right child since the heap is
  // filled from left to right:
  if (leftChildIndex >= minHeap.size()) {
    return;
  }

  // compares swapped parent with its children to see if the heap
  // properties are being violated; if so, swap parent with its smaller child,
  // update parent's index and keep checking:
  if (minHeap.at(parentIndex) > minHeap.at(leftChildIndex) || minHeap.at(parentIndex) > minHeap.at(rightChildIndex)) {
    // if the right child does not exist or left < right, swap root and left:
    if (!minHeap.at(rightChildIndex) || minHeap.at(leftChildIndex) < minHeap.at(rightChildIndex)) {
      swapValues(leftChildIndex, parentIndex);
      parentIndex = leftChildIndex;
    }
    // otherwise, swap root and right:
    else {
      swapValues(rightChildIndex, parentIndex);
      parentIndex = rightChildIndex;
    }
    heapifyTopBottom(parentIndex);
  }
}

void MinHeap::swapValues(int indexNew, int indexParent) {
  int temp = this->minHeap.at(indexNew);

  this->minHeap.at(indexNew) = this->minHeap.at(indexParent);
  this->minHeap.at(indexParent) = temp;
}

int MinHeap::heapSize(void) {
  return minHeap.size() - 1; // element at position heap[0] does not count.
}

int main() {
  MinHeap minheap;

  minheap.insertElement(16);
  minheap.insertElement(10);
  minheap.insertElement(8);
  minheap.insertElement(5);
  minheap.insertElement(7);
  minheap.insertElement(19);
  minheap.insertElement(20);
  std::cout << "Min heap root: " << minheap.peek() << "\n";

  minheap.removeMin();
  std::cout << "Min heap root: " << minheap.peek() << "\n";

  minheap.insertElement(1);
  std::cout << "Min heap root: " << minheap.peek() << "\n";

  return 0;
}