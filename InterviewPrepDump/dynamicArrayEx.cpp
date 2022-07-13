#include <cassert>
#include <iomanip>
#include <iostream>

template <typename T>
class DynamicArray {
private:
  int cur_size;      // number of elements currently in the array
  int cur_capacity;  // total number of elements that the array can accomodate
  int growth_factor; // factor by which the array will grow

  T *arr; // T pointer to the first array element
public:
  /**
   * @brief Initialize attributes and Construct a new Dynamic Array object
   *
   * @param init_capacity
   * @param grow_by_this_factor
   */
  DynamicArray(int init_capacity, int grow_by_this_factor) { // constructor
    // initialize attributes:
    this->cur_size = 0;                        // the array is initially empty
    this->cur_capacity = init_capacity;        // current max. capacity
    this->growth_factor = grow_by_this_factor; // factor by which cur_capacity will grow

    arr = new T[this->cur_capacity]; // alocate space for 'cur_capacity' elements in the heap
  }

  /**
   * @brief Destroy the Dynamic Array object
   *
   */
  ~DynamicArray() {
    delete[] arr; // free the allocated memory
  }

  /**
   * @brief Add a new element to the end of the array.
   *
   * @param new_element
   */
  void push(T new_element) {
    this->insert(new_element, this->cur_size);
  }

  /**
   * @brief Remove last element in the array.
   *
   */
  void pop(void) {
    if (this->is_empty()) {
      std::cout << "Array is currently empty."
                << "\n";
      return;
    }

    --this->cur_size;

    if (this->cur_size < (this->cur_capacity / this->growth_factor))
      this->shrink();
  }

  /**
   * @brief Insert new element at a give position.
   *
   * @param new_element
   * @param position
   */
  void insert(T new_element, int position) {
    // if array has reached its current max. capacity, resize it:
    if (this->cur_size == this->cur_capacity) {
      this->resize();
    }

    // shift (copy) elements to the right of the given position in order to
    // accomodate the new element:
    for (int i = this->cur_size; i > position; --i) {
      this->arr[i] = this->arr[i - 1];
    }

    // insert new element:
    this->arr[position] = new_element;

    // update current array size:
    ++this->cur_size;
  }

  /**
   * @brief Remove element at a given position.
   *
   * @param position
   */
  void remove(int position) {
    assert((this->cur_size > 0) && (position >= 0) && (position < this->cur_size));

    for (int i = position; i < this->cur_size; i++) {
      this->arr[i] = this->arr[i + 1];
    }

    --this->cur_size;

    if (this->cur_size < (this->cur_capacity / this->growth_factor))
      this->shrink();
  }

  /**
   * @brief Resize array by the growth factor given.
   *
   */
  void resize(void) {
    this->cur_capacity *= this->growth_factor;

    T *temp = new T[this->cur_capacity];

    std::copy(arr, arr + this->cur_size, temp);

    delete[] arr;

    arr = temp;
  }

  /**
   * @brief Shrink array dimensions to save memory.
   *
   */
  void shrink(void) {
    this->cur_capacity /= growth_factor;

    T *temp = new T[this->cur_capacity];

    std::copy(arr, arr + this->cur_size, temp);

    delete[] arr;

    arr = temp;
  }

  /**
   * @brief Get the last array element.
   *
   * @return T
   */
  T back(void) {
    assert(this->cur_size > 0);

    return arr[this->cur_size - 1];
  }

  /**
   * @brief Get the first array element.
   *
   * @return T
   */
  T front(void) {
    assert(this->cur_size > 0);

    return arr[0];
  }

  /**
   * @brief Get the size of the array object.
   *
   * @return int
   */
  int get_size(void) {
    return this->cur_size;
  }

  /**
   * @brief Get the max capacity of the array  object.
   *
   * @return int
   */
  int get_max_capacity(void) {
    return this->cur_capacity;
  }

  /**
   * @brief Return whether the array is empty or not.
   *
   * @return true
   * @return false
   */
  bool is_empty(void) {
    return this->cur_size == 0;
  }

  /**
   * @brief Overload operator []
   *
   * @param position
   * @return T&
   */
  T &operator[](int position) {
    assert((this->cur_size > 0) && (position >= 0) && (position < this->cur_size));

    return arr[position];
  }

  /**
   * @brief Print array elements.
   *
   */
  void print(void) {
    if (this->is_empty()) {
      std::cout << "Array is currently empty.\n";
      return;
    }

    std::cout << "Array elements: ";
    for (int i{0}; i < this->cur_size; ++i) {
      std::cout << arr[i] << "   ";
    }
    std::cout << "\n";
  }
};

int main() {
  std::cout << std::boolalpha;

  DynamicArray<int> dynArr{2, 2};

  std::cout << "Array is empty: " << dynArr.is_empty() << "\n"; // TRUE
  std::cout << "Array size: " << dynArr.get_size() << "\n";     // 0
  std::cout << "\n";

  dynArr.push(5);
  dynArr.push(6);
  std::cout << "Array is empty: " << dynArr.is_empty() << "\n";         // FALSE
  std::cout << "Array size: " << dynArr.get_size() << "\n";             // 2
  std::cout << "Array capacity: " << dynArr.get_max_capacity() << "\n"; // 2
  std::cout << "\n";

  dynArr.push(7);
  std::cout << "Array size: " << dynArr.get_size() << "\n";             // 3
  std::cout << "Array capacity: " << dynArr.get_max_capacity() << "\n"; // 4
  std::cout << "\n";

  dynArr.insert(1, 0);
  dynArr.print();
  std::cout << "Array size: " << dynArr.get_size() << "\n";             // 4
  std::cout << "Array capacity: " << dynArr.get_max_capacity() << "\n"; // 4
  std::cout << "\n";

  dynArr.push(8);
  dynArr.print();
  std::cout << "Array size: " << dynArr.get_size() << "\n";             // 5
  std::cout << "Array capacity: " << dynArr.get_max_capacity() << "\n"; // 8
  std::cout << "\n";

  dynArr.pop();
  dynArr.print();
  std::cout << "Array size: " << dynArr.get_size() << "\n";             // 4
  std::cout << "Array capacity: " << dynArr.get_max_capacity() << "\n"; // 8
  std::cout << "\n";

  dynArr.remove(1);
  dynArr.print();
  std::cout << "Array size: " << dynArr.get_size() << "\n";             // 3
  std::cout << "Array capacity: " << dynArr.get_max_capacity() << "\n"; // 4
  std::cout << "\n";

  dynArr.pop();
  dynArr.pop();
  dynArr.pop();
  dynArr.print();
  dynArr.pop();
  std::cout << "Array size: " << dynArr.get_size() << "\n"; // 0
  std::cout << "\n";

  dynArr.push(3);
  dynArr.push(6);
  dynArr.push(9);
  dynArr.push(12);
  dynArr.push(15);
  dynArr.print();
  std::cout << "Array size: " << dynArr.get_size() << "\n";             // 5
  std::cout << "Array capacity: " << dynArr.get_max_capacity() << "\n"; // 8
  std::cout << "Array element at position 3: " << dynArr[3] << "\n";
  std::cout << "\n";

  std::cout << "Front element: " << dynArr.front() << "\n";
  std::cout << "Back element: " << dynArr.back() << '\n';
  std::cout << "\n";

  dynArr.pop();
  dynArr.pop();
  dynArr.pop();
  std::cout << "Array size: " << dynArr.get_size() << "\n";             // 2
  std::cout << "Array capacity: " << dynArr.get_max_capacity() << "\n"; // 4
  dynArr.print();
  std::cout << "\n";

  return 0;
}