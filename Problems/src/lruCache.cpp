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