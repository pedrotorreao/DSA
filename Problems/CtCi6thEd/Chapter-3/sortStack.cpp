/*********************************************************************************************/
/* Problem: Sort Stack (CtCi 3.5) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Write a program to sort a stack such that the smallest items are on the top. You can use an
  additional temporary stack, but you may not copy the elements into any other data structure
  (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.

--Reasoning:

--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <climits>
#include "stack/stack.h"

class SortedStack
{
private:
  Stack<int> st_values, st_min;

public:
  void push(int value)
  {
    if (min() >= value)
    {
      st_min.push(value);
    }
    else
    {
      st_values.push(value);
    }
  }

  void pop(void)
  {
    if (st_min.isEmpty())
    {
      fill_min_stack();
    }
    st_min.pop();
  }

  int peek(void)
  {
    if (st_min.isEmpty())
    {
      fill_min_stack();
    }

    return st_min.peek();
  }

  int min(void)
  {
    if (st_min.isEmpty())
    {
      return INT_MAX;
    }
    return st_min.peek();
  }

  bool isEmpty(void)
  {
    return (st_min.isEmpty() && st_values.isEmpty());
  }

  void fill_min_stack(void)
  {
    int count{0};
    Stack<int> temp;

    while (count < st_values.getSize())
    {
      temp.push(st_values.peek());
      st_values.pop();

      ++count;
    }
    count = 0;
    while (count < temp.getSize())
    {
      push(temp.peek());
      temp.pop();

      ++count;
    }
  }

  SortedStack() {}
  ~SortedStack() = default;
};