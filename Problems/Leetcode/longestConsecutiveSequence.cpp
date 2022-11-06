/******************************************************************************
Problem: 128. Longest Consecutive Sequence
*******************************************************************************/
/*
--Problem statement:
  Given an unsorted array of integers 'nums', return the length of the longest
  consecutive elements sequence.
  You must write an algorithm that runs in O(n) time.

  > Example 1:
      Input: nums = [100,4,200,1,3,2]
      Output: 4
      Explanation:
        The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its
        length is 4.

  > Example 2:
      Input: nums = [0,3,7,2,5,8,4,6,0,1]
      Output: 9

--Inputs:
  int[]: unsorted array of integers

--Output:
  int: longest consecutive elements sequence

--Constraints:
    :: 0 <= nums.length <= 105
    :: -109 <= nums[i] <= 109
*/

#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

/*
  # Approach 1 - Using C++ set (ordered set):
    --Reasoning:
      First, we add all the elements in the input array to a C++ ordered set (std::set<int>).
      Since the elements in the set are then ordered by value, we iterate over the set checking
      for each value 'num[i]' if 'num[i]+1' is present on the set. If it is, we increment the
      'count'; otherwise, we reset the 'count'. The longest consecutive sequence will be the
      max value between the current longest sequence and the best.

    --Time Complexity: O(N*log(N))

    --Space Complexity: O(N)
*/
int longestConsecutive_1(std::vector<int> &nums) {
  if (!nums.size())
    return 0;

  std::set<int> n_set(nums.begin(), nums.end()); // O(N*log(N))

  auto it = n_set.begin();

  int prev = *it, count = 1, longest = 1;
  ++it;

  while (it != n_set.end()) {
    if (*it == prev + 1)
      ++count;
    else
      count = 1;

    prev = *it;
    longest = std::max(longest, count);

    ++it;
  }

  return longest;
}

/*
  # Approach 2 - Using C++ unordered set:
    --Reasoning:
      First, we add all the elements in the input array to a C++ unordered set
      (std::unordered_set<int>). Then, we iterate over the input array, 'nums[]',
      checking for each 'nums[i]' if 'prev=nums[i]-1' is present in the hash set,
      which would indicate that 'nums[i]' has already been accounted for in other
      subsequence. In case it is not, we then check if 'next=nums[i]+1' is present in
      the hash set, which indicates that we've got a subsequence going on; if so,
      we proceed checking for the next numbers in the sequence by incrementing
      'next'. When we encounter a value which is not present in the hash set,
      it means the the current subsequence has reached its end. The length of the
      current subsequence will then be 'next-nums[i]' and the longest subsequence
      will be the max value between the best value so far and the length of the
      current subsequence.

    --Time Complexity: O(N)

    --Space Complexity: O(N)
*/
int longestConsecutive_2(std::vector<int> &nums) {
  if (!nums.size())
    return 0;

  const int SIZE = nums.size();
  int longest = 1;

  std::unordered_set<int> hs(nums.begin(), nums.end()); // O(N)

  for (int i{0}; i < SIZE; ++i) {
    int prev = nums.at(i) - 1;

    if (!hs.count(prev)) {
      int next = nums.at(i) + 1;
      while (hs.count(next))
        ++next;

      longest = std::max(longest, next - nums.at(i));
    }
  }

  return longest;
}

int main() {
  std::vector<int> nums{};
  int longest{0};

  nums = {100, 4, 200, 1, 3, 2};
  longest = longestConsecutive_1(nums);
  std::cout << "Longest consecutive sequence: " << longest << "\n";
  longest = longestConsecutive_2(nums);
  std::cout << "Longest consecutive sequence: " << longest << "\n\n";

  nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  longest = longestConsecutive_1(nums);
  std::cout << "Longest consecutive sequence: " << longest << "\n";
  longest = longestConsecutive_2(nums);
  std::cout << "Longest consecutive sequence: " << longest << "\n\n";

  nums = {1, 0, -1};
  longest = longestConsecutive_1(nums);
  std::cout << "Longest consecutive sequence: " << longest << "\n";
  longest = longestConsecutive_2(nums);
  std::cout << "Longest consecutive sequence: " << longest << "\n\n";

  return 0;
}