#pragma once

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