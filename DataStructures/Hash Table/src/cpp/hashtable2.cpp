/***************************************************************************************
-- DS: Hash Table CPP - Another example using STL lists to handle collisions w/ chaining
****************************************************************************************/

#include <iostream>
#include <vector>
#include <list>

class HashTable
{
private:
  int numOfBuckets;
  std::list<std::string> *hashTable;

public:
  int calculateHash(std::string key);
  void insertKey(std::string key);
  void deleteKey(std::string key);
  bool findKey(std::string key);
  void displayHashTable(void);

  HashTable(int hashTableSize);
  ~HashTable();
};

HashTable::HashTable(int hashTableSize)
{
  this->numOfBuckets = hashTableSize;
  this->hashTable = new std::list<std::string>[this->numOfBuckets];
}

HashTable::~HashTable() {}

int HashTable::calculateHash(std::string key)
{
  int hash{0};

  for (auto i{0}; i < key.size(); i++)
  {
    hash = (hash + int(key.at(i)) * i) % this->numOfBuckets;
  }

  return hash;
}

void HashTable::insertKey(std::string key)
{
  int id = calculateHash(key);

  this->hashTable[id].push_back(key);
}

void HashTable::deleteKey(std::string key)
{
  int id = calculateHash(key);

  auto itr = this->hashTable[id].begin();

  while (itr != this->hashTable[id].end())
  {
    if (*itr == key)
    {
      break;
    }
    ++itr;
  }

  if (itr != this->hashTable[id].end())
  {
    this->hashTable[id].erase(itr);
    return;
  }

  std::cout << key << " is not stored.\n";
}

bool HashTable::findKey(std::string key)
{
  int id = calculateHash(key);

  auto itr = this->hashTable[id].begin();

  while (itr != this->hashTable[id].end())
  {
    if (*itr == key)
    {
      break;
    }
    ++itr;
  }

  if (itr != this->hashTable[id].end())
  {
    std::cout << key << " is stored.\n";
    return true;
  }
  std::cout << key << " is not stored.\n";
  return false;
}

void HashTable::displayHashTable(void)
{
  for (int currentBucket = 0; currentBucket < this->numOfBuckets; currentBucket++)
  {
    std::cout << currentBucket;
    for (auto x : this->hashTable[currentBucket])
    {
      std::cout << " --> " << x;
    }
    std::cout << "\n";
  }
}

int main()
{
  std::vector<std::string> keys{"Kale", "Lu", "Pedro", "Leticia", "Carol", "Alice", "Alzira"};

  HashTable ht(4);

  // populate hash table:
  for (auto i{0}; i < keys.size(); i++)
  {
    ht.insertKey(keys[i]);
  }
  // check if all elements were inserted:
  ht.displayHashTable();

  // remove key "Leticia":
  ht.deleteKey("Leticia");

  // check if the removal was done correctly:
  ht.displayHashTable();

  return 0;
}