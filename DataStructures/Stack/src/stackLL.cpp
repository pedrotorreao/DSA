/******************************************************************************
DS: Stack using Singly Linked List (SLL)
*******************************************************************************/
#include <iostream>
#include <string>
#include <stdexcept>

class StackItem
{
public:
  std::string data;
  StackItem *next;

  StackItem(std::string d)
  {
    this->data = d;
    this->next = nullptr;
  }
};

class Stack
{
private:
  StackItem *top;
  int size;

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
  this->top = nullptr;
  this->size = 0;
}

void Stack::pop(void)
{
  if (this->top != nullptr)
  {
    this->top = this->top->next;
    --this->size;
    return;
  }
  throw std::length_error("stack is empty!");
}

void Stack::push(std::string d)
{
  if (d.size() > 0)
  {
    StackItem *new_top = new StackItem(d);
    new_top->next = this->top;
    this->top = new_top;
    ++this->size;
    return;
  }
  throw std::invalid_argument("invalid argument!");
}

bool Stack::isEmpty(void)
{
  return (this->top == nullptr);
}

std::string Stack::peek(void)
{
  if (this->top != nullptr)
  {
    return this->top->data;
  }
  throw std::length_error("stack is empty!");
}

int Stack::getSize(void)
{
  return this->size;
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
  stack.push("study session");

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