/*********************************************************************************************/
/* Problem: Queue via Stacks (CtCi 3.4) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Implement a MyQueue class which implements a queue using two stacks.

--Reasoning:
  One of the stacks is used to keep the elements in the order as they are entered (stack_1), so
  newest first, and the other is used to keep the older elements first (stack_2). All push()
  operations are performed to stack_1. Whenever we perform a peek() or dequeue() operation,
  in which the oldest element is needed, we check if stack_2 is empty, if it is, we feed it
  stack_1 elements and, since the elements are fed newest to oldest, stack_2 will have the 
  oldest element on top. Then, until stack_2 is empty again, which will happen when all the
  elements in it are dequeued, there is no need to call feedQ().

--Time complexity: 
  O(n) for feedQ(), where n is the number of elements in stack_1. All other operations are O(1).
 
--Space complexity: 
  O(n'), where n' is the total number of elements.
  
*/

#include <iostream>
#include <iomanip>
#include "stack/stack.h"

class MyQueue
{
private:
  Stack<int> st_1;
  Stack<int> st_2;
  int front;
  int size;

public:
  void enqueue(int value)
  {
    st_1.push(value);

    ++this->size;
  }

  void dequeue(void)
  {
    if (st_2.isEmpty())
    {
      feedQ();
    }
    st_2.pop();

    --this->size;
  }

  int peek(void)
  {
    if (st_2.isEmpty())
    {
      feedQ();
    }
    this->front = st_2.peek();

    return this->front;
  }

  bool isEmpty(void)
  {
    return (this->size == 0);
  }

  int get_size(void)
  {
    return this->size;
  }

  void feedQ(void)
  {
    while (!st_1.isEmpty())
    {
      st_2.push(st_1.peek());
      st_1.pop();
    }
  }

  MyQueue()
  {
    this->size = 0;
  }
  ~MyQueue() = default;
};

int main()
{
  std::cout << std::boolalpha;

  MyQueue queue;

  // st_1: 1  3  9  27  81      st_2: empty
  for (unsigned int i{1}; i < 100; i *= 3)
  {
    queue.enqueue(i);
  }

  // st_1: empty      st_2: 81  27  9  3  1
  std::cout << "Queue Front: " << queue.peek() << "\n";                              // Expected: 1
  std::cout << "Queue Size: " << (queue.isEmpty() ? 0 : (queue.get_size())) << "\n"; // Expected: 5

  queue.dequeue(); // st_1: empty      st_2: 81  27  9  3

  std::cout << "Queue Front: " << queue.peek() << "\n";                              // Expected: 3
  std::cout << "Queue Size: " << (queue.isEmpty() ? 0 : (queue.get_size())) << "\n"; // Expected: 4

  // st_1: 100  175  250  325  400  475      st_2: 81  27  9  3
  for (unsigned int i{100}; i < 500; i += 75)
  {
    queue.enqueue(i);
  }

  std::cout << "Queue Size: " << (queue.isEmpty() ? 0 : (queue.get_size())) << "\n"; // Expected: 10

  // st_1: empty      st_2: 475  400  325  250  175
  for (unsigned int i{0}; i < 5; i++)
  {
    queue.dequeue();
  }

  std::cout << "Queue Front: " << queue.peek() << "\n";                              // Expected: 175
  std::cout << "Queue Size: " << (queue.isEmpty() ? 0 : (queue.get_size())) << "\n"; // Expected: 5

  return 0;
}