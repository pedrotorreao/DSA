/*********************************************************************************************/
/* Problem: Closest Numbers (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Sorting is useful as the first step in many different tasks. The most common task is to make
  finding things easier, but there are other uses as well. In this case, it will make it easier
  to determine which pair or pairs of elements have the smallest absolute difference between
  them.

  > Example:
    arr = [5,2,3,4,1]
    Sorted, arr' = [1,2,3,4,5]. Several pairs have the minimum difference of 1: [(1,2),(2,3),
    (3,4),(4,5)]. Return the array [1,2,2,3,3,4,4,5].
    Note: As shown in the example, pairs may overlap.

  Given a list of unsorted integers, arr, find the pair of elements that have the smallest
  absolute difference between them. If there are multiple pairs, find them all.

--Reasoning:
  Solution #1: Begin by sorting the input array. After that, iterate over the array calculating
  the absolute difference between the pair of adjacent elements. If the current difference,
  'currDiff', is less than or equal to the minimum difference so far, 'minDiff', map this difference
  and its pair to the hashmap and update the value of 'minDiff'. At the end, just iterate over
  the array mapped for the minimum difference adding its values to the result.
  Solution #2: Same idea, but a little cleaner using the output array itself to hold the temporary
  values instead of using a hashmap.

--Time complexity:
  O(N*logN), due to the sorting, where N is the size of the input array.

--Space complexity:
  O(N), due to the hashmap and output array.
*/

#include <iostream>
#include <climits>
#include <unordered_map>
#include <vector>
#include <algorithm>

// Solution #1:
std::vector<int> closestNumbers_1(std::vector<int> arr)
{
  std::vector<int> res;
  std::unordered_map<int, std::vector<std::pair<int, int>>> pairs;
  int minDiff = INT_MAX;

  // sort input array:
  std::sort(arr.begin(), arr.end());

  // create and map the pairs:
  for (int i{1}; i < arr.size(); i++)
  {
    int currDiff = abs(arr.at(i) - arr.at(i - 1));

    if (currDiff <= minDiff)
    {
      // pairs[minDiff] = std::make_pair(arr.at(i-1), arr.at(i));
      pairs[currDiff].push_back(std::make_pair(arr.at(i - 1), arr.at(i)));
      minDiff = currDiff;
    }
  }

  auto it = pairs[minDiff].begin();
  while (it != pairs[minDiff].end())
  {
    res.push_back(it->first);
    res.push_back(it->second);
    ++it;
  }

  return res;
}

// Solution #2 - Cleaner:
std::vector<int> closestNumbers_2(std::vector<int> arr)
{
  std::vector<int> res;
  int minDiff = INT_MAX;

  // sort input array:
  std::sort(arr.begin(), arr.end());

  for (int i{1}; i < arr.size(); i++)
  {
    int currDiff = abs(arr.at(i) - arr.at(i - 1));

    if (currDiff <= minDiff)
    {
      if (currDiff < minDiff)
      {
        res.clear();
        minDiff = currDiff;
      }

      res.push_back(arr.at(i - 1));
      res.push_back(arr.at(i));
    }
  }

  return res;
}

void display(const std::vector<int> &vec);

int main()
{
  std::vector<int> arr{-20, -3916237, -357920, -3620601, 7374819, -7330761, 30, 6246457, -6461594, 266854};
  std::vector<int> res = closestNumbers_1(arr);
  display(res); // Expects: -20   30

  res = closestNumbers_2(arr);
  display(res); // Expects: -20   30

  arr = {-5, 15, 25, 71, 63};
  res = closestNumbers_1(arr);
  display(res); // Expects: 63   71

  res = closestNumbers_2(arr);
  display(res); // Expects: 63   71

  return 0;
}

void display(const std::vector<int> &vec)
{
  for (const auto &v : vec)
  {
    std::cout << v << "\t";
  }

  std::cout << "\n";
}
