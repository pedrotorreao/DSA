/*********************************************************************************************/
/* Problem: Smallest Positive Integer (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Write a function that, given an array A of N integers, returns the smallest positive integer
  (greater than 0) that does not occur in A.
  > Example:
    - A = [1, 3, 6, 4, 1, 2], the function should return 5.
    - A = [1, 2, 3], the function should return 4.
    - A = [−1, −3], the function should return 1.

--Input:
  int[]: array of N integers.

--Output:
  int: smallest positive integer

--Constraints:
    - N is an integer within the range [1..100,000];
    - each element of array A is an integer within the range [−1,000,000..1,000,000].

--Reasoning: See comments below.

--Time complexity: O(N), where N is the size of the input array.

--Space complexity:
  O(N), in the worst case in which all the array elements are positive and unique.

*/
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int smallestPositiveInteger(std::vector<int> &A) {
  // Create a set to store only positive unique integers:
  std::set<int> intSet;
  // Iterate through the input filling the set:
  for (const auto &a : A) {
    if (a > 0) {
      intSet.insert(a);
    }
  }
  // If the set is empty, it means all elements were negative
  // so return the the smallest positive integer, 1. Also return
  // 1 if it is not present in the set:
  if (intSet.empty() || (intSet.count(1) == 0))
    return 1;

  int minPositiveInt = 1;
  // Iterate through the set checking if 'minPositiveInt' is present.
  // If it is, check the next positive integer; if not, then this is the
  // integer that is missing, return it:
  while (intSet.count(minPositiveInt)) {
    ++minPositiveInt;
  }

  return minPositiveInt;
}

int main() {
  std::vector<int> num{1, 3, 6, 4, 1, 2};
  int res = smallestPositiveInteger(num);
  int expected = 5;
  std::cout << "Smallest positive integer for [1,3,6,4,1,2]: " << res
            << "\t" << (res == expected ? "--PASSED\n" : "--FAILED\n");

  num = {1, 2, 3};
  res = smallestPositiveInteger(num);
  expected = 4;
  std::cout << "Smallest positive integer for [1,2,3]: " << res
            << "\t" << (res == expected ? "--PASSED\n" : "--FAILED\n");

  num = {-1, -3};
  res = smallestPositiveInteger(num);
  expected = 1;
  std::cout << "Smallest positive integer for [-1,-3]: " << res
            << "\t" << (res == expected ? "--PASSED\n" : "--FAILED\n");

  num = {-1000000, -999995, -1, 0, 1, 2, 3, 4, 5, 999, 1000000};
  res = smallestPositiveInteger(num);
  expected = 6;
  std::cout << "Smallest positive integer for [-1000000,-999995,-1,0,1,2,3,4,5,999,1000000]: " << res
            << "\t" << (res == expected ? "--PASSED\n" : "--FAILED\n");

  num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  res = smallestPositiveInteger(num);
  expected = 10;
  std::cout << "Smallest positive integer for [1,2,3,4,5,6,7,8,9]: " << res
            << "\t" << (res == expected ? "--PASSED\n" : "--FAILED\n");

  return 0;
}