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
    Stack<int> *current_stack = all_stacks[this->stack_index];

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

    if (current_stack->getSize() > 0)
    {
      current_stack->pop();
    }

    if (current_stack->getSize() == 0)
    {
      all_stacks.erase(this->stack_index);

      --this->stack_index;
      --this->stack_count;
    }
  }

  int peek(void)
  {
    Stack<int> *current_stack = all_stacks[this->stack_index];

    return current_stack->peek();
  }

  int how_many_stacks(void)
  {
    return this->stack_count;
  }

  int stack_occupancy(void)
  {
    return this->all_stacks[this->stack_index]->getSize();
  }

  int which_stack(void)
  {
    return this->stack_index;
  }

  SetOfStacks(int capacity)
  {
    this->max_capacity = capacity; // total capacity for the stacks
    this->stack_index = 0;         // initial stack
    this->stack_count = 1;         // we begin with only 1 stack of size max_capacity

    all_stacks[this->stack_index] = new Stack<int>(); // add initial stack to the table
  }

  ~SetOfStacks()
  {
    auto it = all_stacks.begin();
    while (it != all_stacks.end())
    {
      auto stack_ptr = it->second;

      delete stack_ptr;
      stack_ptr = nullptr;
      ++it;
    }
  }
};

int main()
{
  SetOfStacks *st = new SetOfStacks(5);

  for (int i{0}; i < 12; ++i)
  {
    st->push(i);
  }
  // stack: [0 1 2 3 4] [5 6 7 8 9] [10 11]
  std::cout << "Num. of stacks: " << st->how_many_stacks() << "\n"
            << "Current stack: " << st->which_stack() << "\n"
            << "Stack occupancy: " << st->stack_occupancy() << "\n"
            << "Top: " << st->peek() << "\n-----\n";

  for (int i{0}; i < 6; ++i)
  {
    st->pop();
  }

  // stack: [0 1 2 3 4] [5]
  std::cout << "Num. of stacks: " << st->how_many_stacks() << "\n"
            << "Current stack: " << st->which_stack() << "\n"
            << "Stack occupancy: " << st->stack_occupancy() << "\n"
            << "Top: " << st->peek() << "\n-----\n";

  st->pop();

  // stack: [0 1 2 3 4]
  std::cout << "Num. of stacks: " << st->how_many_stacks() << "\n"
            << "Current stack: " << st->which_stack() << "\n"
            << "Stack occupancy: " << st->stack_occupancy() << "\n"
            << "Top: " << st->peek() << "\n-----\n";

  delete st;

  return 0;
}