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
  std::unique_ptr<T> ptr;

public:
  /* ------------ Modifiers ------------ */
  // adds new element to the end of the array:
  void push(T value)
  {
    if (this->get_size() == this->total_capacity)
    {
      this->resize();
    }
    ++this->size;
    this->ptr[size] = value;
  }
  // pops element at the end of the array:
  T pop(void)
  {
    --this->size;
    if (this->get_size() < (this->total_capacity / 2))
    {
      this->resize();
    }
  }
  // insert new element at a given position:
  void insert(T value, int pos)
  {
    if (pos == this->get_size() - 1)
    {
      this->push(value);
    }
    else
    {
      if (this->get_size() == this->total_capacity)
      {
        resize();
      }

      for (int i = this->size; i > pos; --i)
      {
        this->ptr[i] == this->ptr[i - 1];
      }

      this->ptr[pos] = value;
      this->size++;
    }
  }
  // removes element at a given position:
  void remove(int pos)
  {
    this->size--;
    for (int i = pos; i < this->size; i++)
    {
    }
  }
  // resizes array to actual size:
  void resize(void)
  {
  }

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

    return ptr[0];
  }

  T back(void) const
  {
    assert(this->get_size() > 0);

    return ptr[this->size - 1];
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

    return ptr[pos];
  }

  // display:
  void print(void);

  /* ------------ Overloaded constructor ------------- */
  DynamicArray(int capacity, int growth = 2)
  {
    this->size = 0;
    this->total_capacity = capacity;
    this->growth_factor = growth;

    ptr = new T[total_capacity];
  }
  /* ------------ Destructor ------------- */
  ~DynamicArray() = default;
};