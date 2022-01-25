/******************************************************************************
/-- DS: Circular Queue using Arrays
*******************************************************************************/

#include <iomanip>
#include <iostream>
#include <vector>

class MyCircularQueue {
  // std::vector to hold all the data:
  std::vector<int> queue;
  // pointers to the beginning and ending of the queue:
  int start;
  int end;
  // queue's max capacity:
  int max_capacity;
  // queue's current size:
  int current_size;

public:
  MyCircularQueue(int k) {
    max_capacity = k;
    queue.assign(max_capacity, -1);
    start = 0;
    end = -1;
    current_size = 0;
  }

  bool enQueue(int value) {
    if (current_size == max_capacity) // queue is full
      return false;

    if (end + 1 == max_capacity) // queue doesn't any vacation left at the end
      end = 0;
    else // queue has room to grow towards the "end" of the vector
      ++end;

    queue.at(end) = value; // add new value at the 'end' position
    ++current_size;        // update 'current_size' to account for the newly added value

    return true;
  }

  bool deQueue() {
    if (current_size == 0) // queue is empty
      return false;

    queue.at(start) = -1; // set current 'start' position to -1

    if (start + 1 == max_capacity) // all elements towards the end were already dequeued
      start = 0;
    else
      ++start;

    --current_size; // update 'current_size' to account for the removed value

    return true;
  }

  int Front() {
    if (isEmpty())
      return -1;

    return queue.at(start);
  }

  int Rear() {
    if (isEmpty())
      return -1;

    return queue.at(end);
  }

  bool isEmpty() {
    return (current_size == 0);
  }

  bool isFull() {
    return (current_size == max_capacity);
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
  std::cout << std::boolalpha;

  MyCircularQueue cq(5);
  bool successful{false};

  std::cout << "Queue is empty: " << cq.isEmpty() << "\n"; // Expected: TRUE
  std::cout << "Front element: " << cq.Front() << "\n";    // Expected: -1 (queue is currently empty)
  std::cout << "Rear element: " << cq.Rear() << "\n";      // Expected: -1 (queue is currently empty)

  successful = cq.enQueue(3);                                      // cq [3  -1  -1  -1  -1]
  std::cout << "enQueue() was successful: " << successful << "\n"; // Expected: TRUE

  successful = cq.enQueue(2); // cq [3  2  -1  -1  -1]
  successful = cq.enQueue(9); // cq [3  2  9  -1  -1]
  successful = cq.enQueue(4); // cq [3  2  9  4  -1]

  std::cout << "Queue is empty: " << cq.isEmpty() << "\n"; // Expected: FALSE
  std::cout << "Front element: " << cq.Front() << "\n";    // Expected: 3
  std::cout << "Rear element: " << cq.Rear() << "\n";      // Expected: 4
  std::cout << "Queue is full: " << cq.isFull() << "\n";   // Expected: FALSE

  successful = cq.enQueue(7);                            // cq [3  2  9  4  7]
  std::cout << "Rear element: " << cq.Rear() << "\n";    // Expected: 7
  std::cout << "Queue is full: " << cq.isFull() << "\n"; // Expected: TRUE

  successful = cq.enQueue(1);                                      // cq [3  2  9  4  -1] --> FULL - Expected: FALSE
  std::cout << "enQueue() was successful: " << successful << "\n"; // Expected: FALSE
  std::cout << "Rear element: " << cq.Rear() << "\n";              // Expected: 7

  successful = cq.deQueue();                            // cq [-1  2  9  4  7]
  successful = cq.deQueue();                            // cq [-1  -1  9  4  7]
  std::cout << "Front element: " << cq.Front() << "\n"; // Expected: 9
  std::cout << "Rear element: " << cq.Rear() << "\n";   // Expected: 7

  successful = cq.enQueue(1);                         // cq [1  -1  9  4  7]
  std::cout << "Rear element: " << cq.Rear() << "\n"; // Expected: 1

  successful = cq.deQueue();                            // cq [1  -1  -1  4  7]
  successful = cq.deQueue();                            // cq [1  -1  -1  -1   7]
  successful = cq.deQueue();                            // cq [1  -1  -1  -1   -1]
  std::cout << "Front element: " << cq.Front() << "\n"; // Expected: 1
  std::cout << "Rear element: " << cq.Rear() << "\n";   // Expected: 1

  successful = cq.deQueue();
  std::cout << "Queue is empty: " << cq.isEmpty() << "\n"; // Expected: TRUE

  return 0;
}