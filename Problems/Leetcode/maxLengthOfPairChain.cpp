/***
Problem: LC 646. Maximum Length of Pair Chain
(https://leetcode.com/problems/maximum-length-of-pair-chain/description/)

--Problem statement:
  You are given an array of 'n' pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
  A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

  Return the length longest chain which can be formed.

  You do not need to use up all the given intervals. You can select pairs in any order.

  > Example 1:
    Input: pairs = [[1,2],[2,3],[3,4]]
    Output: 2
    Explanation: The longest chain is [1,2] -> [3,4].

  > Example 2:
    Input: pairs = [[1,2],[7,8],[4,5]]
    Output: 3
    Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].

--Inputs:
    int[][]: array of integer pairs.

--Output:
    int: length of the longest chain which satisfy the condition set.

--Constraints:
    :: n == pairs.length
    :: 1 <= n <= 1000
    :: -1000 <= lefti < righti <= 1000

--Time complexity:
  O(n*log(n)), where 'n' is the number of pairs in the input array, mainly due to the sorting of the input pairs.

--Space complexity:
  O(1), since no input-dependent space is allocated, but it may need O(log(n)) auxiliary space for the sorting.

*/

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  static int findLongestChain(std::vector<std::vector<int>> &pairs) {
    // in case the input array has only one pair, return it:
    if (pairs.size() < 2)
      return 1;

    // sort pairs in ascending order according to their ending values:
    std::sort(pairs.begin(),
              pairs.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                return a[1] < b[1];
              });

    int chainLength = 1, prevPairEnd = pairs.at(0).at(1);

    for (const auto &pair : pairs) {
      // if current pair begins after the previous one has ended, add it to the
      // chain and update the previous pair ending to be the current one's:
      if (pair.at(0) > prevPairEnd) {
        ++chainLength;
        prevPairEnd = pair.at(1);
      }
    }

    return chainLength;
  }
};

int main() {
  std::vector<std::vector<int>> nums{};

  nums = {{1, 2}, {2, 3}, {3, 4}};
  std::cout << "-- Longest pair chain: " << Solution::findLongestChain(nums) << "\n";

  nums = {{1, 2}, {7, 8}, {4, 5}};
  std::cout << "-- Longest pair chain: " << Solution::findLongestChain(nums) << "\n";

  nums = {{7, 8}, {5, 6}, {4, 5}, {1, 2}, {3, 5}, {2, 3}, {9, 11}};
  std::cout << "-- Longest pair chain: " << Solution::findLongestChain(nums) << "\n";
}
