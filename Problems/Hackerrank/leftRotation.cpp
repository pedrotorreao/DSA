/*********************************************************************************************/
/* Problem: Left Rotation (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  A left rotation operation on an array of size n shifts each of the array's elements 1 unit to
  the left. Given an integer, d, rotate the array that many steps left and return the result.

  > Example:
      d = 2
      arr = [1,2,3,4,5]
      After 2 rotations, arr' = [3,4,5,1,2]

  > Input:
      int d: the amount to rotate by
      int arr[n]: the array to rotate

  > Output - int[n]: the rotated array

  > Constraints:
      1<=n<=10^5
      1<=d<=n
      1<=a[i]<=10^6

--Reasoning:
  Perform 'd' iterations on the array adding all elements which would be rotated to the back of the
  array. After that, remove these 'd' elements from their original positions. What will be left is
  the rotated array.

--Time complexity: O(d), where 'd' is the number of rotations.

--Space complexity: O(1), there is no dependency on the input size.
*/

#include <iostream>
#include <vector>

void displayArray(const std::vector<int> &arr);

void rotateLeft(int d, std::vector<int> &arr)
{
  for (int i{0}; i < d; i++)
  {
    arr.push_back(arr.at(i));
  }

  arr.erase(arr.begin(), arr.begin() + d);
}

int main()
{
  std::vector<int> vec{1, 2, 3, 4, 5};
  int d = 4;
  rotateLeft(d, vec);
  displayArray(vec); // Expected: 5 1 2 3 4

  vec = {41, 73, 89, 7, 10, 1, 59, 58, 84, 77, 77, 97, 58, 1, 86, 58, 26, 10, 86, 51};
  d = 10;
  rotateLeft(d, vec);
  displayArray(vec); // Expected: 77 97 58 1 86 58 26 10 86 51 41 73 89 7 10 1 59 58 84 77

  return 0;
}

void displayArray(const std::vector<int> &arr)
{
  for (const auto &a : arr)
  {
    std::cout << a << "  ";
  }
  std::cout << "\n";
}