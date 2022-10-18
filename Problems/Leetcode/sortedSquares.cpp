/******************************************************************************
Problem: Squares of a Sorted Array
*******************************************************************************/
/*
--Problem statement:
  Given an integer array nums sorted in non-decreasing order, return an array of
  the squares of each number sorted in non-decreasing order.

  > Example 1:
  Input: nums = [-4,-1,0,3,10]
  Output: [0,1,9,16,100]
  Explanation: After squaring, the array becomes [16,1,0,9,100].
  After sorting, it becomes [0,1,9,16,100].

  > Example 2:
  Input: nums = [-7,-3,2,3,11]
  Output: [4,9,9,49,121]

--Inputs:
  int[]: integer array nums 

--Output:
  int[]: array of the squares of each number sorted in non-decreasing order

--Constraints:
    :: 1 <= nums.length <= 104
    :: -104 <= nums[i] <= 104
    :: nums is sorted in non-decreasing order.

--Reasoning: See comments below.

--Time complexity: O(N)

--Space complexity: O(N)

*/

#include <iostream>
#include <vector>

template <typename T>
void display1D(std::vector<T> &vec) {
  std::cout << "[";
  for (auto &v : vec)
    std::cout << v << " ";
  std::cout << "]\n";
}

// Approach #1: Redundant solution, unnecessary square calculations:
std::vector<int> sortedSquares_1(std::vector<int> &nums) {
  const int N = nums.size();
  std::vector<int> ans(N, 0);
  int l{0}, r{N - 1}, i{N - 1};

  int l_squared = nums.at(l) * nums.at(l);
  int r_squared = nums.at(r) * nums.at(r);

  while (i >= 0) {
    if (l_squared > r_squared) {
      ans.at(i) = l_squared;

      if (++l < N)
        l_squared = nums.at(l) * nums.at(l);
    } else {
      ans.at(i) = r_squared;

      if (--r >= 0)
        r_squared = nums.at(r) * nums.at(r);
    }
    --i;
  }

  return ans;
}

// Approach #2: Clean solution, "Two pointer" approach:
std::vector<int> sortedSquares_2(std::vector<int> &nums) {
  const int N = nums.size();
  std::vector<int> ans(N, 0);
  int l{0}, r{N - 1}, i{N - 1};

  while (i >= 0) {
    if (std::abs(nums.at(l)) > std::abs(nums.at(r))) {
      ans.at(i) = nums.at(l) * nums.at(l);
      ++l;
    } else {
      ans.at(i) = nums.at(r) * nums.at(r);
      --r;
    }
    --i;
  }

  return ans;
}

int main() {
  std::vector<int> nums{}, res{};

  nums = {-4, -1, 0, 3, 10};
  res = sortedSquares_1(nums);
  display1D(res); // [16,1,0,9,100] --> [0,1,9,16,100]
  res = sortedSquares_2(nums);
  display1D(res); // [16,1,0,9,100] --> [0,1,9,16,100]

  nums = {-7, -3, 2, 3, 11};
  res = sortedSquares_1(nums);
  display1D(res); // [49,9,4,9,121] --> [4,9,9,49,121]
  res = sortedSquares_2(nums);
  display1D(res);

  nums = {1};
  res = sortedSquares_1(nums);
  display1D(res); // [1]
  res = sortedSquares_2(nums);
  display1D(res);

  return 0;
}