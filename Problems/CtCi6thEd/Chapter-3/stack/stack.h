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
    }

    if (this->stack.size() > 0)
    {
      this->top = this->stack.at(this->stack.size() - 1);
    }
    else
    {
      T emptyErr{};
      this->top = emptyErr;
    }
  }

  T peek(void)
  {
    if (this->stack.size() != 0)
      return this->top;

    T emptyErr{};
    std::cout << "Stack is Empty" << std::endl;
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
