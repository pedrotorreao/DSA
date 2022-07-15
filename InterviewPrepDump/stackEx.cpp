#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

template <typename T>
class Stack {
private:
  std::vector<T> st;
  T top;
  int max_capacity;

public:
  /**
   * @brief Construct a new Stack object with a fixed max. capacity.
   *
   * @param max_size
   */
  Stack(int max_size) {
    this->st = {};
    this->max_capacity = max_size;
  }
  /**
   * @brief Construct a new Stack object. Default constructor, no max capacity set.
   *
   */
  Stack() {
    this->st = {};
    this->max_capacity = std::numeric_limits<int>::max();
  }
  /**
   * @brief Destroy the Stack object.
   *
   */
  ~Stack() = default;

  /**
   * @brief Insert new element at the top of the stack.
   *
   * @param value
   */
  void push(T value) {
    if (this->get_size() == this->max_capacity) {
      std::cout << "** Max. capacity reached, remove an element or increase capacity **\n";
      return;
    }

    this->top = value;
    this->st.push_back(value);
  }

  /**
   * @brief Remove top element from the top of the stack.
   *
   */
  void pop(void) {
    if (!this->get_size()) {
      std::cout << "** Stack is empty **\n";
      return;
    }

    this->st.pop_back();
    this->top = this->st.back();
  }

  /**
   * @brief Get the top element from the stack.
   *
   * @return T
   */
  T peek(void) {
    if (!this->get_size()) {
      T err{};
      std::cout << "** Stack is empty **";
      return err;
    }

    return this->top;
  }

  /**
   * @brief Get the number of elements on the stack.
   *
   * @return int
   */
  int get_size(void) {
    return st.size();
  }

  /**
   * @brief Check whether the stack is empty or not.
   *
   * @return true
   * @return false
   */
  bool is_empty(void) {
    return st.size() == 0;
  }

  /**
   * @brief Increase max stack capacity in case the overloaded constructor has been used to set an initial max capacity.
   *
   */
  void grow_capacity(void) {
    if (this->max_capacity == std::numeric_limits<int>::max()) {
      std::cout << "** This stack is dynamic by default **\n";
      return;
    }
    this->max_capacity *= 2;
  }
};

int main() {
  Stack<std::string> st_1(3);

  std::cout << "Stack size: " << st_1.get_size() << "\n";
  std::cout << "Stack top: " << st_1.peek() << "\n";
  st_1.pop();
  std::cout << "\n";

  st_1.push("Oslo");
  st_1.push("Lima");
  st_1.push("Rome");
  st_1.push("Kingston");
  std::cout << "Stack size: " << st_1.get_size() << "\n";
  std::cout << "Stack top: " << st_1.peek() << "\n";
  std::cout << "\n";

  st_1.pop();
  std::cout << "Stack top: " << st_1.peek() << "\n";
  std::cout << "\n";

  st_1.grow_capacity();
  st_1.push("Sidney");
  st_1.push("Pequim");
  std::cout << "Stack size: " << st_1.get_size() << "\n";
  std::cout << "Stack top: " << st_1.peek() << "\n";
  std::cout << "\n";

  Stack<int> st_2;

  st_2.push(1);
  st_2.push(3);
  st_2.push(5);
  st_2.push(9);
  st_2.push(11);
  std::cout << "Stack size: " << st_2.get_size() << "\n";
  std::cout << "Stack top: " << st_2.peek() << "\n";
  std::cout << "\n";

  return 0;
}
