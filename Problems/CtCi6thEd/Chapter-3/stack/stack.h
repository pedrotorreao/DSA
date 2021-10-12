/******************************************************************************
- Data Structure: Stack
*******************************************************************************/
#pragma once
#include <vector>

template <typename T>
class Stack
{
private:
  T top;
  std::vector<T> stack;

public:
  void push(T new_element)
  {
    this->stack.push_back(new_element);
    this->top = new_element;
  }

  void pop(void)
  {
    if (this->stack.size() != 0)
    {
      this->stack.pop_back();
    }
    else
    {
      std::cout << "Stack is already Empty\n";
      exit(1);
    }

    if (this->stack.size() > 0)
    {
      this->top = this->stack.at(this->stack.size() - 1);
    }
  }

  T peek(void)
  {
    if (this->stack.size() != 0)
      return this->top;

    std::cout << "Stack is Empty" << std::endl;
    exit(1);
  }

  int getSize(void)
  {
    return this->stack.size();
  }

  bool isEmpty(void)
  {
    return (this->stack.size() == 0);
  }

  Stack() {}
  ~Stack() = default;
};
