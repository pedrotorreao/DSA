/******************************************************************************
Problem: Rearrange Array Elements by Sign.
*******************************************************************************/
/*
--Problem statement:
  You are given a 0-indexed integer array nums of even length consisting of an
  equal number of positive and negative integers.
  You should rearrange the elements of nums such that the modified array follows
  the given conditions:
    :: Every consecutive pair of integers have opposite signs.
    :: For all integers with the same sign, the order in which they were present
    in nums is preserved.
    :: The rearranged array begins with a positive integer.
  Return the modified array after rearranging the elements to satisfy the aforementioned
  conditions.

  > Example 1:
    Input: nums = [3,1,-2,-5,2,-4]
    Output: [3,-2,1,-5,2,-4]
    Explanation:
      The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
      The only possible way to rearrange them such that they satisfy all conditions
      is [3,-2,1,-5,2,-4]. Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4],
      [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.

  > Example 2:
    Input: nums = [-1,1]
    Output: [1,-1]
    Explanation:
      1 is the only positive integer and -1 the only negative integer in nums.
      So nums is rearranged to [1,-1].

--Inputs:
  int[]: integer array nums of even length

--Output:
  int[]: modified array after rearranging the elements

--Constraints:
    :: 2 <= nums.length <= 2 * 105
    :: nums.length is even
    :: 1 <= |nums[i]| <= 105
    :: nums consists of equal number of positive and negative integers.

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

// Approach #1 - Using two queues for positive and negative values.
//  - Time complexity: O(N)
//  - Space complexity: O(N), where N is the size of the original array
std::vector<int> rearrangeArray_1(std::vector<int> &nums) {
  const int N = nums.size();
  std::queue<int> pos{}, neg{};
  int i{0};

  for (auto &n : nums) {
    if (n > 0)
      pos.push(n);
    else
      neg.push(n);
  }

  while (!pos.empty() || !neg.empty()) {
    if ((i % 2 == 0) && !pos.empty()) {
      nums.at(i) = pos.front();
      pos.pop();
    } else {
      if (!neg.empty()) {
        nums.at(i) = neg.front();
        neg.pop();
      }
    }
    ++i;
  }

  return nums;
}

// Approach #2 - Two pointers approach. Relies on the fact that positive values
// will always be on even positions and negative values on odd position.
//  - Time complexity: O(N)
//  - Space complexity: O(N), where N is the size of the original array
std::vector<int> rearrangeArray_2(std::vector<int> &nums) {
  const int N = nums.size();
  int posID{0}, negID{1};
  std::vector<int> rearrangedArray(N, 0);

  for (auto &n : nums) {
    if (n > 0) {
      rearrangedArray.at(posID) = n;
      posID += 2;
    } else {
      rearrangedArray.at(negID) = n;
      negID += 2;
    }
  }

  return rearrangedArray;
}

int main() {
  std::vector<int> nums{};
  std::vector<int> resp{};

  nums = {3, 1, -2, -5, 2, -4};
  resp = rearrangeArray_1(nums);
  std::cout << "Result 1: ";
  display1D(nums);
  resp = rearrangeArray_2(nums);
  std::cout << "Result 2: ";
  display1D(nums);
  std::cout << "Expected: [3,-2,1,-5,2,-4]\n\n";

  nums = {-1, 1};
  resp = rearrangeArray_1(nums);
  std::cout << "Result 1: ";
  display1D(nums);
  resp = rearrangeArray_2(nums);
  std::cout << "Result 2: ";
  display1D(nums);
  std::cout << "Expected: [1,-1]\n\n";

  nums = {-3, -11, -6, 9, -15, 3, 7, 29};
  resp = rearrangeArray_1(nums);
  std::cout << "Result 1: ";
  display1D(nums);
  resp = rearrangeArray_2(nums);
  std::cout << "Result 2: ";
  display1D(nums);
  std::cout << "Expected: [9,-3,3,-11,7,-6,29,-15]\n\n";

  return 0;
}