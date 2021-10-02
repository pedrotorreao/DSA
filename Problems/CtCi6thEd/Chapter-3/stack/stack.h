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

  T pop(void)
  {
    if (this->stack.size() != 0)
    {
      this->stack.pop_back();
      this->top = this->stack.at(this->stack.size() - 1);
    }

    T emptyErr{};
    std::cout << "Stack is Empty\n";
    return emptyErr;
  }

  T peek(void)
  {
    if (this->stack.size() != 0)
      return this->top;

    T emptyErr{};
    std::cout << "Stack is Empty\n";
    return emptyErr;
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
