/*********************************************************************************************/
/* Problem: Zig Zag Sequence (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an array of n distinct integers, transform the array into a zig zag sequence by permuting
  the array elements. A sequence will be called a zig zag sequence if the first k elements in
  the sequence are in increasing order and the last k elements are in decreasing order, where
  k = (n+1)/2. You need to find the lexicographically smallest zig zag sequence of the given array.

  > Example:
    a = [2, 3, 5, 1, 4]     ->    zig-zag sequence [1, 4, 5, 3, 2]

  > Input: int a[n] - input array containing n elements

  > Output: int a'[n] - modified array which represents the zig zag sequence

  > Constraints:
      1 <= t <= 20
      1 <= n <= 10000 (n is always odd)
      0 <= ai <= 10^9

--Reasoning:
  The first step is to sort the array to guarantee that the first k elements in the sequence are
  in increasing order. After that, swap the mid element and the last element and swap the remaining
  k elements so that they are postioned in decreasing order.

--Time complexity: O(n), where n is the size of the input array.

--Space complexity: O(1), no additional space dependent on the input size is needed.

*/

#include <iostream>
#include <vector>
#include <algorithm>

void findZigZagSequence(std::vector<int> a, int n)
{
  std::sort(a.begin(), a.end());

  int mid = ((n + 1) / 2) - 1; // edit here
  std::swap(a[mid], a[n - 1]);

  int st = mid + 1;
  int ed = n - 2;

  while (st <= ed)
  {
    std::swap(a[st], a[ed]);
    st = st + 1;
    ed = ed - 1;
  }

  for (int i = 0; i < n; i++)
  {
    if (i > 0)
      std::cout << " ";
    std::cout << a[i];
  }
  std::cout << std::endl;
}

int main()
{
  std::vector<int> arr{2, 3, 5, 1, 4};
  findZigZagSequence(arr, arr.size()); // Expected: 1 4 5 3 2

  arr = {1, 2, 3, 4, 5, 6, 7};
  findZigZagSequence(arr, arr.size()); // Expected: 1 2 3 7 6 5 4

  return 0;
}
