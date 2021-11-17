/*********************************************************************************************/
/* Problem: Migratory Birds (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an array of bird sightings where every element represents a bird type id, determine the
  id of the most frequently sighted type. If more than 1 type has been spotted that maximum
  amount, return the smallest of their ids.
  > Example:
    arr = [1,1,2,2,3]
    There are two each of types 1 and 2, and one sighting of type 3. Pick the lower of the two
    types seen twice: type 1.

  > Input:
    int arr[n]: the types of birds sighted

  > Output: int: the lowest type id of the most frequently sighted birds

  > Constraints:
      5 <= n <= 2*10^5
      It is guaranteed that each type is 1, 2, 3, 4 or 5.

--Reasoning:
  Iterate over the input array and map the ids frequency.
  > Solution 1: we use a hash table to map each id frequency. After that, we iterate over the
  hash table to get the id with the highest frequency or the smallest id w/ the hightest frequency
  in case the highest frequency.

  > Solution 2: in this example we leverage the knowledge we have that the ids are in the [1,5]
  range and use an array to map each id with its frequency. Also, in the same for loop we check
  to see if the current id being mapped/updated has the highest/same frequency and, if so, store
  the applicable id in a separate variable 'bird_id'.

--Time complexity:
  Both solutions have the same time complexity, which is linear O(n), so both solutions carry a
  linear dependency on the input size. We could argue that solution 2 is better since it only uses
  one for loop; however, it also has to perform more operations per iteration than solution 1.
  Additionally, Solution 1 could also have been written using a single for loop.

--Space complexity:
  O(5) ~ O(1). Both solutions need to allocate space for mapping the ids' frequencies. However,
  they always need the same storage space, since ids are always in the range [1,5], so the
  memory allocated does not depend on the input size and reamains the same for any input, 5.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

// Solution 1:
int migratoryBirds_1(const std::vector<int> &arr)
{
  std::unordered_map<int, int> id_map;
  int bird_id{0};

  for (const auto &id : arr)
  {
    id_map[id]++;
  }

  auto it = id_map.begin();
  while (it != id_map.end())
  {
    if (it->second > id_map[bird_id])
    {
      bird_id = it->first;
    }
    else if (it->second == id_map[bird_id])
    {
      bird_id = (it->first > bird_id) ? bird_id : it->first;
    }

    ++it;
  }

  return bird_id;
}

// Solution 2:
int migratoryBirds_2(const std::vector<int> &arr)
{
  std::vector<int> id_map(6, 0);
  int bird_id{0};

  for (const auto &id : arr)
  {
    id_map[id]++;
    if (id_map[id] > id_map[bird_id])
    {
      bird_id = id;
    }
    else if (id_map[id] == id_map[bird_id])
    {
      bird_id = (id > bird_id) ? bird_id : id;
    }
  }

  return bird_id;
}

int main()
{
  std::vector<int> arr{1, 4, 4, 4, 5, 3};
  std::cout << "Migratory bird - Solution 1: " << migratoryBirds_1(arr) << "\n"; // Expected: 4
  std::cout << "Migratory bird - Solution 2: " << migratoryBirds_2(arr) << "\n"; // Expected: 4

  arr = {2, 4, 3, 2, 3, 1, 2, 1, 3, 3};
  std::cout << "Migratory bird - Solution 1: " << migratoryBirds_1(arr) << "\n"; // Expected: 3
  std::cout << "Migratory bird - Solution 2: " << migratoryBirds_2(arr) << "\n"; // Expected: 3

  arr = {1, 2, 3, 4, 5, 4, 3, 2, 1, 3, 4};
  std::cout << "Migratory bird - Solution 1: " << migratoryBirds_1(arr) << "\n"; // Expected: 3
  std::cout << "Migratory bird - Solution 2: " << migratoryBirds_2(arr) << "\n"; // Expected: 3

  return 0;
}
