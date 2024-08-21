/***
Problem: LC 1851. Minimum Interval to Include Each Query
(https://leetcode.com/problems/minimum-interval-to-include-each-query/description/)

--Problem statement:
You are given a 2D integer array 'intervals', where intervals[i] = [lefti, righti] describes the
ith interval starting at 'lefti' and ending at 'righti' (inclusive). The size of an interval is defined
as the number of integers it contains, or more formally righti - lefti + 1.

You are also given an integer array 'queries'. The answer to the jth query is the size of the smallest
interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.

Return an array containing the answers to the queries.

  > Example 1:
    Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
    Output: [3,3,1,4]
    Explanation: The queries are processed as follows:
    - Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
    - Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
    - Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
    - Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.

  > Example 2:
    Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
    Output: [2,-1,4,6]
    Explanation: The queries are processed as follows:
    - Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
    - Query = 19: None of the intervals contain 19. The answer is -1.
    - Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
    - Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.

--Inputs:
  - int[][]: integer array 'intervals'
  - int[]: integer array 'queries'

--Output:
  - int: smallest interval i such that lefti <= queries[j] <= righti

--Constraints:
    :: 1 <= intervals.length <= 10^5
    :: 1 <= queries.length <= 10^5
    :: intervals[i].length == 2
    :: 1 <= lefti <= righti <= 10^7
    :: 1 <= queries[j] <= 10^7

--Reasoning: see comments below.

--Time complexity: O(n*log(n) + q*log(q)), where 'n' and 'q' are the sizes of the 'intervals' and 'queries' arrays respectively.

--Space complexity: O(n + q), due to the additional space used for the priority queue and the hashmap.

*/

#include <bits/stdc++.h>

typedef std::pair<int, int> pii;

class Solution {
public:
  static std::vector<int> minInterval(std::vector<std::vector<int>> &intervals, std::vector<int> &queries) {
    std::vector<int> responses{}, sortedQs{queries};

    // key: val --> queries[i]: interval size
    std::unordered_map<int, int> hm;

    std::sort(intervals.begin(), intervals.end()); // n*log(n)
    std::sort(sortedQs.begin(), sortedQs.end());   // q*log(q)

    // val1, val2 --> interval size, interval ending
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    int intervalIdx = 0;
    for (int queryIdx = 0; queryIdx < sortedQs.size(); ++queryIdx) {
      int currentQuery = sortedQs.at(queryIdx);

      // first, add all the intervals which start before or at the same time as the
      // current query to the priority queue:
      while (intervalIdx < intervals.size() && intervals.at(intervalIdx).at(0) <= currentQuery) { // O(n)
        int left = intervals.at(intervalIdx).at(0),                                               // current interval start
            right = intervals.at(intervalIdx).at(1);                                              // current interval end

        pq.push({right - left + 1, right}); // current interval length:
                                            // right - left + 1

        ++intervalIdx;
      }

      // remove/pop invalid intervals from the priority queue, i.e. intervals
      // that are in the past or end before current query:
      while (!pq.empty() && pq.top().second < currentQuery) // O(n)
        pq.pop();

      // map current query to its interval size:
      hm[currentQuery] = (!pq.empty()) ? pq.top().first : -1;
    }

    // build the output array:
    for (int queryIdx = 0; queryIdx < queries.size(); ++queryIdx) { // O(q)
      responses.push_back(hm[queries.at(queryIdx)]);
    }

    return responses;
  }

  static bool test(const std::vector<int> &a, const std::vector<int> &b) {
    if (a.size() != b.size())
      return false;

    int n = a.size(), i = 0;

    while (i < n) {
      if (a.at(i) != b.at(i))
        return false;

      ++i;
    }

    return true;
  }
};

int main() {
  std::vector<std::vector<int>> intervals{};
  std::vector<int> queries{}, expected{}, result{};

  intervals = {{1, 4}, {2, 4}, {3, 6}, {4, 4}};
  queries = {2, 3, 4, 5};
  expected = {3, 3, 1, 4};
  result = Solution::minInterval(intervals, queries);
  std::cout << "... testing" << (Solution::test(expected, result) ? "\tPASSED" : "\tFAILED") << "\n";

  intervals = {{2, 3}, {2, 5}, {1, 8}, {20, 25}};
  queries = {2, 19, 5, 22};
  expected = {2, -1, 4, 6};
  result = Solution::minInterval(intervals, queries);
  std::cout << "... testing" << (Solution::test(expected, result) ? "\tPASSED" : "\tFAILED") << "\n";

  return 0;
}