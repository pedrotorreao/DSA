/* * * * * * * * * * * * * * * * * *
Problem: LC 88. Merge Sorted Array

--Problem statement:
You are given two integer arrays 'nums1' and 'nums2', sorted in non-decreasing order, and two integers m and n,
representing the number of elements in 'nums1' and 'nums2' respectively. Merge 'nums1' and 'nums2' into a single
array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array 'nums1'.
To accommodate this, 'nums1' has a length of m + n, where the first m elements denote the elements that should
be merged, and the last n elements are set to 0 and should be ignored. 'nums2' has a length of n.

  >  Example 1:
      Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
      Output: [1,2,2,3,5,6]
      Explanation: The arrays we are merging are [1,2,3] and [2,5,6]. The result of the merge is [1,2,2,3,5,6]
    with the underlined elements coming from nums1.

  >  Example 2:
      Input: nums1 = [1], m = 1, nums2 = [], n = 0
      Output: [1]
      Explanation: The arrays we are merging are [1] and []. The result of the merge is [1].

  >  Example 3:
      Input: nums1 = [0], m = 0, nums2 = [1], n = 1
      Output: [1]
      Explanation: The arrays we are merging are [] and [1]. The result of the merge is [1]. Note that because m = 0,
    there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

--Constraints:
    :: nums1.length == m + n
    :: nums2.length == n
    :: 0 <= m, n <= 200
    :: 1 <= m + n <= 200
    :: -10^9 <= nums1[i], nums2[j] <= 10^9


--Inputs:
  - int[]: integer arrays 'nums1' and 'nums2'.

--Outputs:
  - int[]: not returned, 'nums1' is passed by reference.

--Reasoning: Simple iterative approach beginning from the ends of the arrays.

--Time complexity:
    :: O(n+m), where n and m are the sizes of arrays 'nums1' and 'nums2' respectively.

--Space complexity:
    :: O(1), since no additional input-dependent space is allocated.

* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <vector>

void display1D(const std::vector<int> &vec);

class Solution {
public:
  static void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    if (nums2.size() == 0)
      return;

    int i1 = m - 1, i2 = n - 1, ir = m + n - 1;

    while (i2 >= 0) {
      if (i1 >= 0 && nums1.at(i1) > nums2.at(i2)) {
        nums1.at(ir) = nums1.at(i1);

        --i1;
      } else {
        nums1.at(ir) = nums2.at(i2);

        --i2;
      }
      --ir;
    }
  }
};

int main() {
  std::vector<int> n1{}, n2{};
  int m{}, n{};

  n1 = {1, 2, 3, 0, 0, 0};
  m = 3;
  n2 = {2, 5, 6};
  n = 3;

  std::cout << "nums1: ";
  display1D(n1);
  std::cout << "nums2: ";
  display1D(n2);
  std::cout << "merge result: ";
  Solution::merge(n1, m, n2, n);
  display1D(n1);
}

void display1D(const std::vector<int> &vec) {
  std::cout << "[ ";
  for (const auto &num : vec) {
    std::cout << num << " ";
  }
  std::cout << "]\n";
}