/*********************************************************************************************/
/* Problem: Missing Numbers (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given two arrays of integers, find which elements in the second array are missing from the
  first array.
  > Example:
    arr = [7,2,5,3,5,3]
    arr = [7,2,5,4,6,3,5,3]
    The 'brr' array is the orginal list. The numbers missing are [4,6].
  > Note:
    - If a number occurs multiple times in the lists, you must ensure that the frequency of that
    number in both lists is the same. If that is not the case, then it is also a missing number.
    - Return the missing numbers sorted ascending.
    - Only include a missing number once, even if it is missing multiple times.
    - The difference between the maximum and minimum numbers in the original list is less than
    or equal to 100.

--Inputs:
  - int arr[n]: the array with missing numbers
  - int brr[m]: the original array of numbers

--Outputs:
  - int[]: an array of integers

--Reasoning:
  Iterate over the larger array and add their elements to a hash map, mapping each element to
  the frequency it happens in the array. We are using a C++ STL map container which is a sorted
  associative container that contains key-value pairs w/ unique keys and these keys are sorted.
  Search, removal and insertion operations all have logarithmic time complexity because under
  the hood 'map' are implemented as Red-Black Trees. After we map all the elements from 'brr',
  we'll iterate over 'arr' and for each of its elements we decrement its frequency in the map.
  At the end, we iterate over the map and retrieve all the elements whose frequencies are greater
  than zero, which would mean that these elements are either missing from the 'arr' array or they
  happen less frequently.

--Time complexity: O(N), where N is the size of the largest array, 'brr'.

--Space complexity:
  O(N), since we allocate space to all the elements of the largest array in order to add them to
  our map<>. N is the size of the largest array, 'brr'.

*/

#include <iostream>
#include <map>
#include <vector>

void display(const std::vector<int> &vec);

std::vector<int> missingNumbers(std::vector<int> arr, std::vector<int> brr)
{
  std::vector<int> res;
  std::map<int, int> map;

  for (const auto &b : brr)
  {
    map[b]++;
  }

  for (const auto &a : arr)
  {
    map[a]--;
  }

  auto it = map.begin();

  while (it != map.end())
  {
    if (it->second > 0)
    {
      res.push_back((it->first));
    }

    ++it;
  }

  return res;
}

int main()
{
  std::vector<int> arr_a{203, 204, 205, 206, 207, 208, 203, 204, 205, 206};
  std::vector<int> arr_b{203, 204, 204, 205, 206, 207, 205, 208, 203, 206, 205, 206, 204};
  std::cout << "::Expected output: 204  205  206\t\t::Result: ";
  display(missingNumbers(arr_a, arr_b));

  arr_a = {11, 4, 11, 7, 13, 4, 12, 11, 10, 14};
  arr_b = {11, 4, 11, 7, 3, 7, 10, 13, 4, 8, 12, 11, 10, 14, 12};
  std::cout << "::Expected output: 3  7  8  10  12\t\t::Result: ";
  display(missingNumbers(arr_a, arr_b));

  return 0;
}

void display(const std::vector<int> &vec)
{
  for (const auto &v : vec)
  {
    std::cout << v << "  ";
  }
  std::cout << "\n";
}