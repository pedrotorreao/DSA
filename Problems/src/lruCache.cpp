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
#include <stdexcept>
#include <unordered_map>
#include <string>
#include <list>

class Cache
{
private:
  // hashmap: key (int), value (iterator to a list containing key pair values):
  std::unordered_map<int, std::list<std::pair<int, std::string>>::iterator> cacheMap;
  // list containing key pair values:
  std::list<std::pair<int, std::string>> cacheKeys;
  int cacheSize;

public:
  std::string get(int key);
  void put(int key, std::string value);

  // helper methods:
  void addToCache(int key, std::string value);
  void updateCache(std::list<std::pair<int, std::string>>::iterator it, int key, std::string new_value);
  void evictFromCache(void);
  int cacheOccupancy(void);
  void displayCacheElements(void);

  // constructors/destructors:
  Cache(int size);
  ~Cache() {}
};

Cache::Cache(int size)
{
  this->cacheSize = size;
}

std::string Cache::get(int key)
{
  // look for key on the hashmap:
  auto it = this->cacheMap.find(key);

  // if key is not present on cache (cache miss), throw error:
  if (it == this->cacheMap.end())
  {
    throw std::invalid_argument(" >> Key NOT present on cache! << ");
  }

  //  if key is on cache (cache hit), update cache and return value:
  updateCache(it->second, it->second->first, it->second->second);

  return it->second->second;
}

void Cache::put(int key, std::string value)
{
  // look for key on the hashmap:
  auto it = this->cacheMap.find(key);

  // if key is not yet present on cache (cache miss):
  if (it == this->cacheMap.end())
  {
    // check if the new addition exceeds cache capacity,
    // if it does, evict least recently used (lru) pair:
    if ((this->cacheMap.size() + 1) > this->cacheSize)
    {
      evictFromCache();
    }

    // add new pair to the cache:
    addToCache(key, value);
    return;
  }

  // if key is already present on cache (cache hit),
  // update its value and move it to the front of the cache:
  updateCache(it->second, key, value);
}

void Cache::addToCache(int key, std::string value)
{

  std::pair<int, std::string> new_pair = std::make_pair(key, value);

  this->cacheKeys.push_front(new_pair);
  this->cacheMap[key] = this->cacheKeys.begin();
}

void Cache::updateCache(std::list<std::pair<int, std::string>>::iterator it, int key, std::string new_value)
{
  // update key value:
  it->second = new_value;

  // store pair into a temp variable:
  std::pair<int, std::string> temp_pair = *it;

  // remove pair from original location:
  this->cacheKeys.erase(it);

  // add updated pair to the front:
  this->cacheKeys.push_front(temp_pair);

  // update hashmap:
  this->cacheMap[key] = this->cacheKeys.begin();
}

void Cache::evictFromCache(void)
{
  // get iterator to last cache element, the last element of the list:
  auto leastUsedElement = this->cacheKeys.rbegin();

  // remove the key from the hashmap:
  this->cacheMap.erase(leastUsedElement->first);

  // evict least recently used element from cache:
  this->cacheKeys.pop_back();
}

int Cache::cacheOccupancy(void)
{
  return this->cacheMap.size();
}

void Cache::displayCacheElements(void)
{
  auto it = this->cacheKeys.begin();
  std::cout << "\n-----\n";
  while (it != this->cacheKeys.end())
  {
    std::cout << "Time: " << it->first << "   Task: " << it->second << "\n";
    it++;
  }
}

int main()
{
  Cache lrucache(5);

  lrucache.put(800, "work");
  lrucache.put(900, "daily");
  lrucache.put(1230, "lunch");
  lrucache.put(1600, "coffee");
  lrucache.put(1748, "finish");

  lrucache.displayCacheElements();

  std::cout << "\nSchedule 09:00AM: " << lrucache.get(900) << "\n";
  lrucache.displayCacheElements();

  std::cout << "\nSchedule 04:00PM: " << lrucache.get(1600) << "\n";
  lrucache.displayCacheElements();

  lrucache.put(1600, "break");
  lrucache.displayCacheElements();

  std::cout << "\nSchedule 04:00PM: " << lrucache.get(1600) << "\n";

  lrucache.put(1800, "dinner");
  std::cout << "\nSchedule 05:48PM: " << lrucache.get(1748) << "\n";

  lrucache.displayCacheElements();

  return 0;
}