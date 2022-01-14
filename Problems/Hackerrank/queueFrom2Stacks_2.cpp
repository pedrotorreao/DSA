/*********************************************************************************************/
/* Problem: Queue using two Stacks - reading from input (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  A queue is an abstract data type that maintains the order in which elements were added to it,
  allowing the oldest elements to be removed from the front and new elements to be added to the
  rear. This is called a First-In-First-Out (FIFO) data structure because the first element added
  to the queue (i.e., the one that has been waiting the longest) is always the first one to be
  removed.
  A basic queue has the following operations:
    -Enqueue: add a new element to the end of the queue.
    -Dequeue: remove the element from the front of the queue and return it.
  In this challenge, you must first implement a queue using two stacks. Then process queries,
  where each query is one of the following 3 types:
    1. 1 x: Enqueue element 'x' into the end of the queue.
    2. 2: Dequeue the element at the front of the queue.
    3. 3: Print the element at the front of the queue.

--Inputs:
  The first line contains a single integer, q, denoting the number of queries. Each line of the
  subsequent lines contains a single query in the form described in the problem statement above.
  All three queries start with an integer denoting the query type, but only 1 query is followed by
  an additional space-separated value, x, denoting the value to be enqueued.

--Outputs:
  For each query of type 3, print the value of the element at the front of the queue on a new line.

--Constraints:
    1<=q<=10^5
    1<=type<=3
    1<=|x|<=10^9
    It is guaranteed that a valid answer always exists for each query of type 3.

--Reasoning:
  One of the stacks is used to keep the elements in the order as they are entered (st_1), so
  newest first, and the other is used to keep the older elements first (st_2). All push()
  operations are performed to st_1. Whenever we perform a peek() or dequeue() operation,
  in which the oldest element is needed, we check if st_2 is empty, if it is, we feed it
  st_1 elements and, since the elements are fed newest to oldest, st_2 will have the
  oldest element on top. Then, until st_2 is empty again, which will happen when all the
  elements in it are dequeued, there is no need to call feedQueue() again.

--Time complexity:
  O(n) for feedQueue() when st_2 is empty; otherwise, O(1).

--Space complexity:
  O(n'), where n' is the total number of elements.

*/

#include <iostream>
#include <stack>

void feedQueue(std::stack<int> &stack_1, std::stack<int> &stack_2)
{
  while (!stack_1.empty())
  {
    stack_2.push(stack_1.top());
    stack_1.pop();
  }
}

int main()
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n{0}, query_type{0};

  std::stack<int> st_1;
  std::stack<int> st_2;

  std::cin >> n;

  for (int i{0}; i < n; ++i)
  {
    std::cin >> query_type;
    switch (query_type)
    {
    case 1:
    {
      int val{0};
      std::cin >> val;
      // ...enqueue
      st_1.push(val);
      break;
    }
    case 2:
    {
      // ...dequeue
      if (st_2.empty())
      {
        feedQueue(st_1, st_2);
      }
      if (!st_2.empty())
        st_2.pop();
      break;
    }
    case 3:
    {
      // ...peek
      if (st_2.empty())
      {
        feedQueue(st_1, st_2);
      }
      std::cout << st_2.top() << "\n";
      break;
    }
    }
  }

  return 0;
}
