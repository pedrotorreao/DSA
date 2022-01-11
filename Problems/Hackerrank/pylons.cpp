/*********************************************************************************************/
/* Problem: Pylons (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Goodland is a country with a number of evenly spaced cities along a line. The distance between
  adjacent cities is 1 unit. There is an energy infrastructure project planning meeting, and the
  government needs to know the fewest number of power plants needed to provide electricity to
  the entire list of cities. Determine that number. If it cannot be done, return -1. You are
  given a list of city data. Cities that may contain a power plant have been labeled 1. Others
  not suitable for building a plant are labeled 0. Given a distribution range of k, find the
  lowest number of plants that must be built such that all cities are served. The distribution
  range limits supply to cities where distance is less than k.
  > Examples:
    a.) arr = [0,1,1,1,0,0,0] and k = 3 --> return -1
    b.) arr = [0,1,1,1,1,0] and k = 2   --> return 2

--Inputs:
  -int k: the distribution range
  -int arr[n]: each city's suitability as a building site

--Outputs:
  -int: the minimum number of plants required or -1

--Reasoning:
  We begin by setting the 'coverage' to the furthest possible position that could have a tower capable
  to provide electricity to the range surrounding it, 'startSearch + range - 1', and we keep searching
  inside this range backwards 'coverage >= startSearch - range + 1'. In case we find a tower, we add 1
  to the result, set the new start of the search 'startSearch' to the current tower location and set
  the boolean that indicates that a tower capable to cover the current range was found. In case we
  don't find a tower inside the range 'startSearch - range + 1', this means that there are cities outside
  this range that are not being covered.

--Time complexity:
  O(N)?? The outer while loop is directly dependent on the input size; however, I'm not sure
  about the impact of the inner for loop to the running time.

--Space complexity: O(1), no additional input-dependent space allocation is needed.

*/
#include <iostream>
#include <vector>

int pylons(int k, std::vector<int> arr)
{
  int minNumOfPlants{0}, startSearch{0}, range{k};

  while (startSearch < arr.size())
  {
    bool towerExists{false};

    for (int coverage{startSearch + range - 1}; ((coverage >= startSearch - range + 1) && (coverage >= 0)); --coverage)
    {
      if (coverage < arr.size() && arr.at(coverage) == 1)
      {
        ++minNumOfPlants;
        startSearch = coverage + range;
        towerExists = true;
        break;
      }
    }

    if (!towerExists)
    {
      minNumOfPlants = -1;
      break;
    }
  }

  return minNumOfPlants;
}

int main()
{
  std::vector<int> t{0, 1, 1, 1, 1, 0};
  int k{2};
  int expec{2};
  int res = pylons(k, t);
  std::cout << "Min. number of plants needed: " << res << "  Expected: " << expec << ((expec == res) ? "\t--PASSED\n" : "\t--FAILED\n");

  t = {0, 1, 1, 1, 0, 0, 0};
  k = 3;
  expec = -1;
  res = pylons(k, t);
  std::cout << "Min. number of plants needed: " << res << "  Expected: " << expec << ((expec == res) ? "\t--PASSED\n" : "\t--FAILED\n");

  t = {0, 1, 0, 0, 0, 0, 0};
  k = 3;
  expec = -1;
  res = pylons(k, t);
  std::cout << "Min. number of plants needed: " << res << "  Expected: " << expec << ((expec == res) ? "\t--PASSED\n" : "\t--FAILED\n");

  t = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
  k = 2;
  expec = 7;
  res = pylons(k, t);
  std::cout << "Min. number of plants needed: " << res << "  Expected: " << expec << ((expec == res) ? "\t--PASSED\n" : "\t--FAILED\n");

  return 0;
}
