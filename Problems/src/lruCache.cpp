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
  std::unordered_map<int, std::string> cacheMap;
  std::list<int> cacheKeys;
  int cacheSize;
  int cacheCount;

public:
  std::string get(int key);
  void put(int key, std::string value);
  void updateKeyList(int key);
  void evictFromCache(int key);
  int cacheOccupancy(void);
  void displayCacheElements(void);

  Cache(int size);
  ~Cache() {}
};

Cache::Cache(int size)
{
  this->cacheSize = size;
  this->cacheCount = 0;
}

std::string Cache::get(int key)
{
  if (this->cacheMap.count(key))
  {
    updateKeyList(key);
    return this->cacheMap[key];
  }
  return "Key does not exist!";
}

void Cache::put(int key, std::string value)
{
  if ((this->cacheCount + 1 > this->cacheSize) && !this->cacheMap.count(key))
  {
    evictFromCache(key);
  }

  updateKeyList(key);
  this->cacheMap[key] = value;

  cacheCount++;
}

void Cache::updateKeyList(int key)
{
  // in case it's just a get operation, remove repeated:
  if (this->cacheMap.count(key))
  {
    this->cacheKeys.remove(key);
  }

  // push key to the front:
  this->cacheKeys.push_front(key);
}

void Cache::evictFromCache(int key)
{
  if (!this->cacheMap.count(key))
  {
    int keyToEvict = this->cacheKeys.back();
    auto it = this->cacheMap.begin();

    while (it != cacheMap.end())
    {
      if (it->first == keyToEvict)
      {
        break;
      }
      it++;
    }
    this->cacheMap.erase(it);
  }

  this->cacheKeys.pop_back();
  this->cacheCount--;
}

int Cache::cacheOccupancy(void)
{
  return this->cacheCount;
}

void Cache::displayCacheElements(void)
{
  auto it = this->cacheMap.begin();
  while (it != this->cacheMap.end())
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

  std::cout << "Schedule 09:00AM: " << lrucache.get(900) << "\n";
  std::cout << "Schedule 04:00PM: " << lrucache.get(1600) << "\n";

  lrucache.put(1600, "break");
  std::cout << "Schedule 04:00PM: " << lrucache.get(1600) << "\n";

  lrucache.put(1800, "dinner");
  std::cout << "Schedule 05:48PM: " << lrucache.get(1800) << "\n";

  lrucache.displayCacheElements();

  return 0;
}

/*
--Input:
["LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"]

[,,,,,,,,,,]

--Output:
[,,,,,,,,,,,]

--Expected:
[,,,,,,,,,,,,,,,,,,,,]

--
"LRUCache":[10]
"put":[10,13]
"put":[3,17]
"put":[6,11]
"put":[10,5]
"put":[9,10]

"get":[13]  Output: -1    Expected: -1

"put":[2,19]

"get":[2]   Output: 19    Expected: 19
"get":[3]   Output: 17    Expected: 17

"put":[5,25]

"get":[8]   Output: -1    Expected: -1

"put":[9,22]
"put":[5,5]
"put":[1,30]

"get":[11]    Output: -1  Expected: -1

"put":[9,12]

"get":[7]     Output: -1    Expected: -1
"get":[5]     Output: 5     Expected: 5
"get":[8]     Output: -1    Expected: -1
"get":[9]     Output: 12    Expected: 12

"put":[4,30]
"put":[9,3]

"get":[9]     Output: 3     Expected: 3
"get":[10]    Output: 5     Expected: 5
"get":[10]    Output: 5     Expected: 5

"put":[6,14]
"put":[3,1]

"get":[3]     Output: 1     Expected: 1

"put":[10,11]

"get":[8]     Output: -1    Expected: -1

"put":[2,14]

"get":[1]     Output: -1    Expected: 30
"get":[5]     Output: 5     Expected: 5
"get":[4]     Output: 30    Expected: 30

"put":[11,4]
"put":[12,24]
"put":[5,18]

"get":[13]    Output: -1    Expected: -1

"put":[7,23]

"get":[8]     Output: -1    Expected: -1
"get":[12]    Output: 24    Expected: 24

"put":[3,27]
"put":[2,12]

"get":[5]     Output: 18    Expected: 18

"put":[2,9]
"put":[13,4]
"put":[8,18]
"put":[1,7]

"get":[6]     Output: -1    Expected: -1

"put":[9,29]
"put":[8,21]

"get":[5]     Output: 18    Expected: 18

"put":[6,30]
"put":[1,12]

"get":[10]    Output: -1    Expected: -1

"put":[4,15]
"put":[7,22]
"put":[11,26]
"put":[8,17]
"put":[9,29]

"get":[5]     Output: -1    Expected: 18

"put":[3,4]
"put":[11,30]

"get":[12]    Output: -1    Expected: -1

"put":[4,29]

"get":[3]      Output: 4     Expected: 4
"get":[9]      Output: 29    Expected: 29
"get":[6]      Output: -1    Expected: 30

"put":[3,4]

"get":[1]      Output: 12    Expected: 12
"get":[10]     Output: -1    Expected: -1

"put":[3,29]
"put":[10,28]
"put":[1,20]
"put":[11,13]

"get":[3]     Output: 29    Expected: 29

"put":[3,12]
"put":[3,8]
"put":[10,9]
"put":[3,26]

"get":[8]     Output: 17    Expected: 17
"get":[7]     Output: -1    Expected: 22
"get":[5]     Output: -1    Expected: 18

"put":[13,17]
"put":[2,27]
"put":[11,15]

"get":[12]    Output: -1    Expected: -1

"put":[9,19]
"put":[2,15]
"put":[3,16]

"get":[1]     Output: -1    Expected: 20

"put":[12,17]
"put":[9,1]
"put":[6,19]

"get":[4]     Output: -1    Expected: -1
"get":[5]     Output: -1    Expected: 18
"get":[5]     Output: -1    Expected: 18

"put":[8,1]
"put":[11,7]
"put":[5,2]
"put":[9,28]

"get":[1]     Output: -1    Expected: 20

"put":[2,2]
"put":[7,4]
"put":[4,22]
"put":[7,24]
"put":[9,26]
"put":[13,28]
"put":[11,26]
*/