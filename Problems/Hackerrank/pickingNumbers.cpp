/*********************************************************************************************/
/* Problem: Picking Numbers (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an array of integers, find the longest subarray where the absolute difference between
  any two elements is less than or equal to 1.

  > Example:
      a = [1,1,2,2,4,4,5,5,5]
      There are two subarrays meeting the criterion: [1,1,2,2] and [4,4,5,5,5]. The maximum
      length subarray has 5 elements.

  > Input - int a[n]: an array of integers

  > Output - int: the length of the longest subarray that meets the criterion

  > Constraints:
      2<=n<=100
      0<=a[i]<100

--Reasoning:
  We begin by sorting the array in order to be able to easily compare adjacent elements. After
  that, we start the comparisons, if it satisfies the condition we increment the current counter
  'new_longest'. If it does not, we update the first value in the sequence, 'first', with the
  current, compare the current counter with the previous largest length, stored in 'prev_longest'
  and update its value if it's greater, and reset the value of the current counter, 'new_longest',
  to begin counting the number of elements in ther new subarray. After we're done iterating, we
  compare the 'new_longest' with the 'prev_longest' and return the greater value.

--Time complexity: O(n)

--Space complexity: O(1), there is no dependency on the input size.
*/

#include <iostream>
#include <algorithm>
#include <vector>

int pickingNumbers(std::vector<int> a)
{
  int new_longest{1}, prev_longest{1};

  std::sort(a.begin(), a.end());

  int first = a.at(0);

  for (size_t i{1}; i < a.size(); i++)
  {
    if (abs(a.at(i) - first) <= 1)
    {
      ++new_longest;
    }
    else
    {
      if (new_longest > prev_longest)
      {
        prev_longest = new_longest;
      }
      first = a.at(i);
      new_longest = 1;
    }
  }

  return std::max(prev_longest, new_longest);
}

int main()
{
  std::vector<int> vec{1, 1, 2, 2, 4, 4, 5, 5, 5};
  std::cout << "Longest subarray (Expected 5): " << pickingNumbers(vec) << "\n";

  vec = {98, 3, 99, 1, 97, 2};
  std::cout << "Longest subarray (Expected 2): " << pickingNumbers(vec) << "\n";

  vec = {4, 2, 3, 4, 4, 9, 98, 98, 3, 3, 3, 4, 2, 98, 1, 98, 98, 1, 1, 4, 98,
         2, 98, 3, 9, 9, 3, 1, 4, 1, 98, 9, 9, 2, 9, 4, 2, 2, 9, 98, 4, 98, 1,
         3, 4, 9, 1, 98, 98, 4, 2, 3, 98, 98, 1, 99, 9, 98, 98, 3, 98, 98, 4,
         98, 2, 98, 4, 2, 1, 1, 9, 2, 4};
  std::cout << "Longest subarray (Expected 22): " << pickingNumbers(vec) << "\n";

  vec = {84, 43, 11, 41, 2, 99, 31, 32, 56, 53, 42, 14, 98, 27, 64, 57, 16, 33,
         48, 21, 46, 61, 87, 90, 28, 12, 62, 49, 29, 77, 82, 70, 80, 89, 95, 52,
         13, 19, 9, 79, 35, 67, 51, 39, 7, 1, 66, 8, 17, 85, 71, 97, 34, 73, 75,
         6, 91, 40, 96, 65, 37, 74, 20, 68, 23, 47, 76, 55, 24, 3, 30, 22, 55, 5,
         69, 86, 54, 50, 10, 59, 15, 4, 36, 38, 83, 60, 72, 63, 78, 58, 88, 93,
         45, 18, 94, 44, 92, 81, 25, 26};
  std::cout << "Longest subarray (Expected 3): " << pickingNumbers(vec) << "\n";

  return 0;
}