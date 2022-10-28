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
  a map, to keep the elements ordered by key in descending order, to get the
  frequencies mapped to their elements and extract the k most frequent elements.

--Time complexity: O(N*log(N) + k)

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
  // [key, value]: [nums[i], frequency of nums[i]]
  std::unordered_map<int, int> num_to_freq;
  // [key, value]: [frequency, elements nums[i] w/ that frequency]
  std::map<int, std::vector<int>, std::greater<int>> freq_to_nums;

  // map frequencies:
  for (auto &n : nums)
    ++num_to_freq[n];

  // group elements by frequency:
  for (auto &f : num_to_freq)
    freq_to_nums[f.second].push_back(f.first);

  std::vector<int> kMostFrequent;
  auto freq_iter = freq_to_nums.begin();

  // iterate over the map 'freq_to_nums' adding the top k elements to
  // the answer:
  while (k > 0) {
    for (auto it = freq_iter->second.begin(); it != freq_iter->second.end() && k > 0; ++it) {
      kMostFrequent.push_back(*it);
      --k;
    }
    ++freq_iter;
  }

  return kMostFrequent;
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