/******************************************************************************
DS: Stack using Arrays
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class Stack
{
private:
  std::string top;
  std::vector<std::string> stack;

public:
  Stack();
  void pop(void);
  void push(std::string d);
  bool isEmpty(void);
  std::string peek(void);
  int getSize(void);
  ~Stack();
};

Stack::Stack()
{
  this->top = "";
  this->stack = {};
}

void Stack::pop(void)
{
  if (this->top != "")
  {
    this->stack.pop_back();
    this->top = this->stack.size() ? this->stack.at(this->stack.size() - 1) : "";
    return;
  }
  throw std::length_error("stack is empty!");
}

void Stack::push(std::string d)
{
  if (d.size() > 0)
  {
    this->stack.push_back(d);
    this->top = this->stack.at(this->stack.size() - 1);
    return;
  }
  throw std::invalid_argument("invalid argument!");
}

bool Stack::isEmpty(void)
{
  return (this->stack.size() == 0);
}

std::string Stack::peek(void)
{
  if (this->top != "")
  {
    return this->top;
  }
  throw std::length_error("stack is empty!");
}

int Stack::getSize(void)
{
  return this->stack.size();
}

Stack::~Stack() {}

int main()
{
  std::cout.setf(std::ios::boolalpha);

  Stack stack;

  // --test 1: try to pop from empty stack:
  // stack.pop(); //should throw exception

  // add elements:
  stack.push("work");
  stack.push("supermarket");
  stack.push("shower");
  stack.push("study");

  // --test 2: get top element:
  std::cout << "Stack top: " << stack.peek() << "\n"; //should output "study session"
  std::cout << "---\n";

  // --test 3: get stack size:
  std::cout << "Stack size: " << stack.getSize() << "\n"; // should output 4
  std::cout << "---\n";

  // --test 4: pop top element:
  stack.pop();
  std::cout << "Stack top: " << stack.peek() << "\n";     //should output "shower"
  std::cout << "Stack size: " << stack.getSize() << "\n"; // should output 3
  std::cout << "---\n";

  // --test 5: check if stack is empty:
  std::cout << "The stack is empty: " << stack.isEmpty() << "\n"; // should output false
  std::cout << "---\n";

  // --test 6: pop all elements:
  stack.pop();
  stack.pop();
  stack.pop();
  //std::cout << "Stack top: " << stack.peek() << "\n";             //should throw exception
  std::cout << "Stack size: " << stack.getSize() << "\n";         // should output 0
  std::cout << "The stack is empty: " << stack.isEmpty() << "\n"; // should output true
  std::cout << "---\n";

  return 0;
}