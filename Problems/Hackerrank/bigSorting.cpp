/*********************************************************************************************/
/* Problem: Big Sorting (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Consider an array of numeric strings where each string is a positive number with anywhere from
  1 to 10^6 digits. Sort the array's elements in non-decreasing, or ascending order of their
  integer values and return the sorted array.
    > Example:
      a.) unsorted=["1","200","150","3"]
              --> return ["1","3","150","200"]
      b.) unsorted=["31415926535897932384626433832795","1","3","10","3","5"]
              --> return ["1","3","3","5","31415926535897932384626433832795"]

--Inputs:
  -string unsorted[n]: an unsorted array of integers as strings

--Outputs:
  -string[n]: the array sorted in numerical order

--Constraints:
  1<=n<=(2x10^5)
  Each string is guaranteed to represent a positive integer.
  There will be no leading zeros.
  The total number of digits across all strings in 'unsorted' is between 1 and 10^6 (inclusive).

--Reasoning: See comments below.

--Time complexity: O(N*Log(N)), where N is the size of the 'unsorted' array.

--Space complexity: O(1), no additional input-dependent space is allocated.

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool myComparator(std::string str_1, std::string str_2)
{
  // if the strings being compared have the same length,
  // place the numerically smaller element first:
  if (str_1.size() == str_2.size())
    return str_1 < str_2;

  // if the strings differ in length, place the smaller
  // sized one first:
  return str_1.size() < str_2.size();
}

std::vector<std::string> bigSorting(std::vector<std::string> unsorted)
{
  // use C++ sort() algorithm w/ a custom comparator function
  // in order to sort the string:
  std::sort(unsorted.begin(), unsorted.end(), myComparator);

  // 'unsorted' is now sorted, we can return it:
  return unsorted;
}

int main()
{
  std::vector<std::string> unsorted{"100", "2", "3335", "89", "3333", "29845643257629675", "1"};

  std::vector<std::string> sorted = bigSorting(unsorted);

  for (const auto &s : sorted)
  {
    std::cout << s << "   ";
  }
  std::cout << "\n";

  return 0;
}