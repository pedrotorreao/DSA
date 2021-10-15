/*********************************************************************************************/
/* Problem: Sort Stack (CtCi 3.5) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Write a program to sort a stack such that the smallest items are on the top. You can use an
  additional temporary stack, but you may not copy the elements into any other data structure
  (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.

--Reasoning:
  Basically, we insert the elements of the original stack (st) into a temporary stack (temp_st)
  in ascending order. To do that, we take the top element of st, st.top and compare it to the top element
  of temp_st. If st.top < temp_st.top, we push temp_st.top to st and repeat this step until we
  find the right position in temp_st to insert st.top, which will be when st.top >= temp_st.top
  or temp_st is empty.

--Time complexity: O(N^2), for the worst case where the stack elements are arranged in reverse order.

--Space complexity: O(N), due to the temporary stack

*/

#include <iostream>
#include <vector>
#include "stack/stack.h"

void sortStack(Stack<int> *st)
{
  Stack<int> temp_st;

  while (!st->isEmpty())
  {
    int curr = st->peek();
    st->pop();

    while (!temp_st.isEmpty() && curr < temp_st.peek())
    {
      st->push(temp_st.peek());
      temp_st.pop();
    }
    temp_st.push(curr);
  }

  while (!temp_st.isEmpty())
  {
    st->push(temp_st.peek());
    temp_st.pop();
  }
}

void display_stack(Stack<int> st)
{
  std::cout << "All: ";
  while (!st.isEmpty())
  {
    std::cout << st.peek() << " ";

    st.pop();
  }
  std::cout << "\n";
}

int main()
{

  Stack<int> st;

  // test vector - stack elements:
  std::vector<int> vec{12, 3, -1, 7, 55};
  // fill stack:
  auto it = vec.begin();
  while (it != vec.end())
  {
    st.push(*it);
    ++it;
  }

  std::cout << "Top: " << st.peek() << "\n";
  std::cout << "Orig. stack: ";
  display_stack(st);
  std::cout << "\n";

  sortStack(&st);
  std::cout << "Top: " << st.peek() << "\n";
  std::cout << "Sorted stack: ";
  display_stack(st);
  std::cout << "\n";

  st.push(33);

  std::cout << "Top: " << st.peek() << "\n";
  std::cout << "Orig. stack: ";
  display_stack(st);
  std::cout << "\n";

  sortStack(&st);
  std::cout << "Top: " << st.peek() << "\n";
  std::cout << "Sorted stack: ";
  display_stack(st);
  std::cout << "\n";

  return 0;
}

/* step by step exec.:

1st iter.:
  curr: 55
  st: 7  -1  3  12
  while: FALSE (temp_st IS empty)
  temp_st: 55

2nd iter.:
  curr: 7
  st: -1  3  12
  while: TRUE (temp_st isn't empty AND curr < temp_st.top)
      st: 55 -1  3  12
      temp_st: empty --> while DONE
  temp_st: 7

3rd iter.:
  curr: 55
  st: -1  3  12
  while: FALSE (curr > temp_st.top)
  temp_st: 55  7

4th iter.:
  curr: -1
  st: 3  12
  while: TRUE (temp_st isn't empty AND curr < temp_st.top)
      st: 55  3  12
      temp_st: 7

      st: 7  55  3  12
      temp_st: empty --> while DONE
  temp_st: -1

5th iter.:
  curr: 7
  st: 55  3  12
  while: FALSE (curr > temp_st.top)
  temp_st: 7  -1

6th iter.:
  curr: 55
  st: 3  12
  while: FALSE (curr > temp_st.top)
  temp_st: 55  7  -1

7th iter.:
  curr: 3
  st: 12
  while: TRUE (temp_st isn't empty AND curr < temp_st.top)
      st: 55  12
      temp_st: 7  -1

      st: 7  55  12
      temp_st: -1 --> while DONE (curr > temp_st.top)
  temp_st: 3  -1

8th iter.:
  curr: 7
  st: 55  12
  while: FALSE (curr > temp_st.top)
  temp_st: 7  3  -1

9th iter.:
  curr: 55
  st: 12
  while: FALSE (curr > temp_st.top)
  temp_st: 55  7  3  -1

10th iter.:
  curr: 12
  st: empty
  while: TRUE (temp_st isn't empty AND curr < temp_st.top)
      st: 55
      temp_st: 7  3  -1 --> while DONE (curr > temp_st.top)
  temp_st: 12  7  3  -1

11th iter.:
  curr: 55
  st: empty
  while: FALSE (curr > temp_st.top)
  temp_st: 55  12  7  3  -1

while: FALSE (st IS empty)

iterate through temp_st:
  push top element back to st
  pop an element from temp_st

DONE: st now is ordered
*/