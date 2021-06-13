/******************************************************************************
-- DS: Hash Table CPP - Using STL lists to handle collisions w/ chaining
*******************************************************************************/
#include <iostream>
#include <list>
#include <bits/stdc++.h>

class Hash
{
private:
  int buckets;           // amount of buckets available
  std::list<int> *table; // ptr to arr containing buckets
public:
  Hash(int b);             // constructor
  void insertKey(int key); // add new key to HT
  void deleteKey(int key); // delete key from HT
  int hashFun(int key)
  { // calc. hash
    return (key % buckets);
  }
  void displayHash(); // display HT
  ~Hash();
};

Hash::Hash(int b)
{
  this->buckets = b;
  table = new std::list<int>[buckets];
}

Hash::~Hash() {}

void Hash::insertKey(int key)
{
  int id = hashFun(key);
  table[id].push_back(key);
}

void Hash::deleteKey(int key)
{
  int id = hashFun(key);

  std::list<int>::iterator itr;

  for (itr = table[id].begin(); itr != table[id].end(); itr++)
  {
    if (*itr == key)
      break;
  }

  if (itr != table[id].end())
    table[id].erase(itr);
}

void Hash::displayHash()
{
  for (int i = 0; i < buckets; i++)
  {
    std::cout << i;
    for (auto x : table[i])
      std::cout << " --> " << x;
    std::cout << std::endl;
  }
}

int main()
{
  // array that contains keys to be mapped
  std::vector<int> keys{15, 11, 27, 8, 12};

  // insert the keys into the hash table
  Hash h(7); // 7 is count of buckets in
             // hash table
  for (unsigned int i = 0; i < keys.size(); i++)
  {
    h.insertKey(keys[i]);
  }
  // delete 12 from hash table
  //h.deleteKey(12);

  // display the Hash table
  h.displayHash();

  return 0;
}
