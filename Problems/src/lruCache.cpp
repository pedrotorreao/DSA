/****************************************************************/
/*Problem: Cache LRU   ********/
/****************************************************************/
/*
-- Problem statement:
Implement a cache with two methods:
- get(key): it returns a value mapped to the key passed as argument;
  Inputs:
    key: integer
  Output:
    value: string
- put(key, value): it adds a new value to the cache mapped to the given key. 
If a repeated key is entered, update its value.
In case the cache is full, evict the least recently used value (newly added
values count as recently accessed.)
  Inputs:
    key: integer
    value: string
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <list>

class Cache
{
private:
  std::unordered_map<int, std::string> cacheMap;
  std::list<int> cacheKeys;
  int cacheSize;
  int cacheCount;

public:
  std::string get(int key);
  void put(int key, std::string value);

  Cache(int size);
  ~Cache() {}
};

Cache::Cache(int size)
{
  this->cacheSize = size;
  this->cacheCount = 0;
}

std::string Cache::get(int key) {}

void Cache::put(int key, std::string value) {}

int main()
{

  Cache lrucache(100);

  return 0;
}