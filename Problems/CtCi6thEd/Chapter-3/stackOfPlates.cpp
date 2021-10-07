/*********************************************************************************************/
/* Problem: Stack of Plates (CtCi 3.3) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore,
  in real life, we would likely start a new stack when the previous stack exceeds some 
  threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be 
  composed of several stacks and should create a new stack once the previous one exceeds 
  capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single
  stack (that is, pop() should return the same values as it would if there were just a single
  stack).
  FOLLOW UP: Implement a function popAt(int index) which performs a pop operation on a specific
  sub-stack.

--Reasoning:

--Time complexity: 
 
--Space complexity: 
  
*/

#include <iostream>
#include <unordered_map>
#include "stack/stack.h"

class SetOfStacks
{
private:
  std::unordered_map<int, Stack<int> *> all_stacks;
  int max_capacity;
  int stack_index;
  int stack_count;

public:
  void push(int plate_number)
  {
    Stack<int> *current_stack = all_stacks[stack_index];
    if (current_stack->getSize() < this->max_capacity)
    {
      current_stack->push(plate_number);
      return;
    }

    ++this->stack_count;
    ++this->stack_index;

    Stack<int> *new_stack = new Stack<int>();
    new_stack->push(plate_number);

    all_stacks[stack_index] = new_stack;
  }

  void pop(void)
  {
    Stack<int> *current_stack = all_stacks[this->stack_index];

    current_stack->pop();
  }

  SetOfStacks(int capacity)
  {
    this->max_capacity = capacity; // total capacity for the stacks
    this->stack_index = 0;         // initial stack
    this->stack_count = 1;         // we begin with only 1 stack of size max_capacity

    Stack<int> *stack = new Stack<int>();
    all_stacks[stack_index] = stack;
  }
  ~SetOfStacks()
  {
    auto it = all_stacks.begin();
    while (it != all_stacks.end())
    {
      delete it->second;
    }
  }
};
