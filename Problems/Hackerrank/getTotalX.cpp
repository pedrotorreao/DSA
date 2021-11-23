/*********************************************************************************************/
/* Problem: Between Two Sets (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:

  > Example:

  > Input:

  > Output:

  > Constraints:

--Reasoning:

--Time complexity:

--Space complexity:
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

int getTotalX(std::vector<int> a, std::vector<int> b)
{
  std::unordered_map<int, int> map;
  int count{0};

  // sort arrays:
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  int step = a.at(a.size() - 1);

  for (int inbtwn = step; inbtwn <= b.at(0); inbtwn += step)
  {
    for (int ia = 0; ia < a.size(); ia++)
    {
      if (((inbtwn % a.at(ia)) == 0) && (map[inbtwn] != -1))
      {
        map[inbtwn] = 1;
      }
      else
      {
        map[inbtwn] = -1;
      }
    }
    for (int ib = 0; ib < b.size(); ib++)
    {
      if (((b.at(ib) % inbtwn) == 0) && (map[inbtwn] != -1))
      {
        map[inbtwn] = 1;
      }
      else
      {
        map[inbtwn] = -1;
      }
    }
  }

  auto it = map.begin();

  while (it != map.end())
  {
    if (it->second == 1)
    {
      count++;
    }
    ++it;
  }

  return count;
}

int main()
{
  std::vector<int> vec_a{2, 4};
  std::vector<int> vec_b{16, 24, 32};

  std::cout << "Elements between two sets: " << getTotalX(vec_a, vec_b) << "\n";

  return 0;
}