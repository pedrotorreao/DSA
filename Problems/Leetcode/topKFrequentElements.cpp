/******************************************************************************
Problem: LC 347. Top K Frequent Elements
*******************************************************************************/
/*
--Problem statement:
  Given an integer array nums and an integer k, return the k most frequent elements.
  You may return the answer in any order.

  > Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

  > Example 2:
    Input: nums = [1], k = 1
    Output: [1]

--Inputs:
  int[]: array of integers
  int: k

--Output:
  int[]: array containing the k most frequent elements.

--Constraints:
    :: 1 <= nums.length <= 105
    :: -104 <= nums[i] <= 104
    :: k is in the range [1, the number of unique elements in the array].
    :: It is guaranteed that the answer is unique.

--Reasoning:
  Map the elements to their frequencies with an unordered_map. After that, use
  a map to get the frequencies mapped to their elements and extract the k most
  frequent elements.

--Time complexity: O(N + k)

--Space complexity: O(N), since we allocate

*/

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

void display1D(const std::vector<int> &arr) {
  std::cout << "[ ";
  for (const auto &a : arr)
    std::cout << a << " ";

  std::cout << "]\n\n";
}

std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
  std::unordered_map<int, int> num_to_freq;
  std::map<int, std::vector<int>, std::greater<int>> freq_to_num;

  for (auto &n : nums)
    ++num_to_freq[n];

  for (auto &nf : num_to_freq) {
    freq_to_num[nf.second].push_back(nf.first);
  }

  std::vector<int> ans;
  bool done{false};
  for (auto &fn : freq_to_num) {
    for (auto &f : fn.second) {
      ans.push_back(f);
      if (ans.size() == k) {
        done = true;
        break;
      }
    }
    if (done)
      break;
  }

  return ans;
}

int main() {
  std::vector<int> nums, res;
  int k{};

  nums = {1, 1, 1, 2, 2, 3};
  k = 2;
  res = topKFrequent(nums, k);
  display1D(res);

  k = 1;
  res = topKFrequent(nums, k);
  display1D(res);

  nums = {9, 0, -1, 2, 2, -1, -1, 1, 9, 5, 9, -1};
  k = 2;
  res = topKFrequent(nums, k);
  display1D(res);

  return 0;
}