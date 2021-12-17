#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include <cassert>

template <typename T>
class DynamicArray
{
private:
  int size;
  int total_capacity;
  int growth_factor;
  // std::unique_ptr<T> ptr;
  T *arr;

public:
  /* ------------ Modifiers ------------ */
  // adds new element to the end of the array:
  void push(T value)
  {
    this->insert(value, this->get_size());
  }
  // pops element at the end of the array:
  void pop(void)
  {
    this->remove(this->get_size() - 1);
  }
  // insert new element at a given position:
  void insert(T value, int pos)
  {
    if (this->get_size() == this->total_capacity)
    {
      resize();
    }

    for (int i = this->size; i > pos; --i)
    {
      this->arr[i] == this->arr[i - 1];
    }

    this->size++;
    this->arr[pos] = value;
  }
  // removes element at a given position:
  void remove(int pos)
  {
    assert(pos >= 0 && pos < this->get_size());

    for (int i = pos; i < this->size; i++)
    {
      arr[i] = arr[i + 1];
    }

    this->size--;
  }
  // resizes array to actual size:
  void resize(void)
  {
    this->total_capacity *= this->growth_factor;

    T *temp = new T[this->total_capacity];

    std::copy(arr, arr + this->get_size(), temp);

    delete[] arr;

    arr = temp;
  }

  // Other methods that could be added: clear() and shrink()

  /* ------------ Getters ------------ */
  int get_size(void) const
  {
    return this->size;
  }

  int capacity(void) const
  {
    return this->total_capacity;
  }

  T front(void) const
  {
    assert(this->get_size() > 0);

    return arr[0];
  }

  T back(void) const
  {
    assert(this->get_size() > 0);

    return arr[this->size - 1];
  }

  bool isEmpty(void) const
  {
    return (this->get_size() == 0);
  }

  // overloaded operators:
  //    should overload [] and possibly <<
  T &operator[](int pos)
  {
    assert(pos < this->get_size() && pos >= 0);

    return arr[pos];
  }

  // display:
  void print(void)
  {
    if (this->isEmpty())
    {
      std::cout << "Array is currently empty.\n";
      return;
    }

    std::cout << "Array elements: ";
    for (int i{0}; i < this->get_size(); ++i)
    {
      std::cout << arr[i] << "   ";
    }
    std::cout << "\n";
  }

  /* ------------ Overloaded constructor ------------- */
  DynamicArray(int capacity = 5, int growth = 2)
  {
    this->size = 0;
    this->total_capacity = capacity;
    this->growth_factor = growth;

    arr = new T[total_capacity];
  }
  /* ------------ Destructor ------------- */
  ~DynamicArray()
  {
    delete[] arr;
  }
};