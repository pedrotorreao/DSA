/******************************************************************************
-- DS: Hash Set C++
*******************************************************************************/

#include <iostream>
#include <list>

class MyHashSet {
private:
  std::list<unsigned int> *table;
  int capacity;

public:
  MyHashSet() {
    this->capacity = 1024;
    this->table = new std::list<unsigned int>[this->capacity];
  }

  void add(int key) {
    if (!contains(key)) {
      int hashID = hashF(key);
      this->table[hashID].push_back(key);
    }
  }

  void remove(int key) {
    int hashID = hashF(key);
    std::list<unsigned int>::iterator itr;

    for (itr = table[hashID].begin(); itr != table[hashID].end(); itr++) {
      if (*itr == key)
        break;
    }

    if (itr != table[hashID].end())
      table[hashID].erase(itr);
  }

  bool contains(int key) {
    int hashID = hashF(key);
    std::list<unsigned int>::iterator itr;

    for (itr = table[hashID].begin(); itr != table[hashID].end(); itr++) {
      if (*itr == key)
        break;
    }

    if (itr != table[hashID].end())
      return true;

    return false;
  }

  int hashF(unsigned int k) {
    return (k % this->capacity);
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */