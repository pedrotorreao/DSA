/*********************************************************************************************/
/* Problem: Balanced Sums (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Watson gives Sherlock an array of integers. His challenge is to find an element of the array
  such that the sum of all elements to the left is equal to the sum of all elements to the right.
  > Example:
    arr = [5,6,8,11]
    Ans.: 8 is between two subarrays that sum to 11.

    arr = [1]
    Ans.: 1, since left and right sums are 0.

--Inputs:
  - int arr[n]: an array of integers.

--Outputs:
  - string: either YES or NO.

--Constraints:
  1<=n<=10^5
  1<=arr[i]<=(2x10^4)
  0<=i<n

--Reasoning:
  Solution commented below. It passes all test cases, but it's complex, can be improved.

--Time complexity: O(N), where N is the size of the array.

--Space complexity: O(1), no additional space required.

*/

#include <iostream>
#include <string>
#include <vector>

std::string balancedSums(std::vector<int> arr)
{
  // If the array has only 1 element, its left and right sums are already balanced:
  if (arr.size() == 1)
  {
    return "YES";
  }
  // Keep two "pointers", one beginning at the start of 'arr', and one at the end:
  int left = 0, right = arr.size() - 1;
  // Keep track of the current sums for both sides:
  int sum_l = 0, sum_r = 0;

  // Iterate while 'left' pointer does not overcome 'right' pointer:
  while (left <= right)
  {
    // At each iteration, check if which side has accumulated the largest sum in the
    // previous step and move the opposite pointer, accounting for its sum:
    if (sum_l > sum_r)
    {
      sum_r += arr.at(right);
      --right;
    }
    else if (sum_l < sum_r)
    {
      sum_l += arr.at(left);
      ++left;
    }
    else
    {
      // If the values for the sums are equal, check if the sums are still '0', if so,
      // check which side has the next larger element and move the pointer for the opposite
      // side, accounting for its sum. If the sums are equal but different from '0', move
      // both pointers, accounting for the sums.
      if ((sum_l == 0) && (sum_r == 0))
      {
        if (arr.at(left) > arr.at(right))
        {
          sum_r += arr.at(right);
          --right;
        }
        else if (arr.at(left) < arr.at(right))
        {
          sum_l += arr.at(left);
          ++left;
        }
        else
        {
          sum_l += arr.at(left);
          sum_r += arr.at(right);

          ++left;
          --right;

          if (left >= right)
          {
            return "YES";
          }
        }
      }
      else
      {
        sum_l += arr.at(left);
        sum_r += arr.at(right);

        ++left;
        --right;

        if (left >= right)
        {
          return "YES";
        }
      }
    }
  }

  return "NO";
}

int main()
{
  std::vector<int> arr = {1, 2}; // NO
  std::cout << "Array has balanced sums: " << balancedSums(arr) << "\n";

  arr = {5, 6, 8, 11}; // YES - {5+6} 8 {11}
  std::cout << "Array has balanced sums: " << balancedSums(arr) << "\n";

  arr = {1}; // YES - {0} 1 {0}
  std::cout << "Array has balanced sums: " << balancedSums(arr) << "\n";

  arr = {1, 2, 3}; // NO
  std::cout << "Array has balanced sums: " << balancedSums(arr) << "\n";

  arr = {1, 2, 3, 3}; // YES - {1+2} 3 {3}
  std::cout << "Array has balanced sums: " << balancedSums(arr) << "\n";

  arr = {1, 1, 4, 1, 1}; // YES - {1+1} 4 {1+1}
  std::cout << "Array has balanced sums: " << balancedSums(arr) << "\n";

  arr = {2, 0, 0, 0}; // YES - {0} 2 {0+0+0}
  std::cout << "Array has balanced sums: " << balancedSums(arr) << "\n";

  arr = {0, 0, 2, 0}; // YES - {0+0} 2 {0}
  std::cout << "Array has balanced sums: " << balancedSums(arr) << "\n";

  arr = {0, 0, 0, 0}; // YES - {0+0} 0 {0}, {0} 0 {0+0}
  std::cout << "Array has balanced sums: " << balancedSums(arr) << "\n";

  return 0;
}
