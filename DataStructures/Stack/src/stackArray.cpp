/******************************************************************************
DS: Stack using Arrays
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

class Stack {
private:
  std::vector<std::string> stack;

public:
  Stack() {}

  bool pop(void) {
    if (this->stack.empty())
      return false;

    this->stack.pop_back();
    return true;
  }

  bool push(std::string val) {
    if (val.empty())
      return false;

    this->stack.push_back(val);
    return true;
  }

  bool isEmpty(void) {
    return this->stack.empty();
  }

  std::string peek(void) {
    if (this->stack.empty())
      return "-- EMPTY STACK --";

    return this->stack.back();
  }

  int getSize(void) {
    return this->stack.size();
  }

  ~Stack() = default;
};

int main() {
  std::cout.setf(std::ios::boolalpha);

  Stack stack;
  bool success = false;

  // --test 1: try to pop from empty stack:
  // success = stack.pop(); //should throw exception

  // add elements:
  success = stack.push("work");
  success = stack.push("supermarket");
  success = stack.push("shower");
  success = stack.push("study");

  // --test 2: get top element:
  std::cout << "Stack top: " << stack.peek() << "\n"; // "study"
  std::cout << "---\n";

  // --test 3: get stack size:
  std::cout << "Stack size: " << stack.getSize() << "\n"; // 4
  std::cout << "---\n";

  // --test 4: pop top element:
  stack.pop();
  std::cout << "Stack top: " << stack.peek() << "\n";     // "shower"
  std::cout << "Stack size: " << stack.getSize() << "\n"; // 3
  std::cout << "---\n";

  // --test 5: check if stack is empty:
  std::cout << "The stack is empty: " << stack.isEmpty() << "\n"; // false
  std::cout << "---\n";

  // --test 6: pop all elements:
  success = stack.pop();
  success = stack.pop();
  success = stack.pop();
  std::cout << "Stack top: " << stack.peek() << "\n";             // "-- EMPTY STACK --"
  std::cout << "Stack size: " << stack.getSize() << "\n";         // 0
  std::cout << "The stack is empty: " << stack.isEmpty() << "\n"; // true
  std::cout << "---\n";

  return 0;
}