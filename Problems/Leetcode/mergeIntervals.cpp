/***
Problem: LC 56. Merge Intervals

--Problem statement:
  Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
  and return an array of the non-overlapping intervals that cover all the intervals in the input.

  Example 1:
    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

  Example 2:
    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.

--Inputs:
  int[][]: array of intervals

--Output:
  int[][]: array of the non-overlapping intervals

--Constraints:
    :: 1 <= intervals.length <= 104
    :: intervals[i].length == 2
    :: 0 <= starti <= endi <= 104

--Time complexity:
    O(N*log(N)), where N is the total number of intervals in the input array, due to the sorting of the intervals.

--Space complexity: O(N), where N is the length of the output interval list.

*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

void display2D(std::vector<std::vector<int>> &vec);

bool myComparator(std::vector<int> i1, std::vector<int> i2) {
  return i1.at(0) <= i2.at(0);
}

std::vector<std::vector<int>> mergeIntervals(std::vector<std::vector<int>> &intervals) {
  if (!intervals.size())
    return std::vector<std::vector<int>>();
  if (intervals.size() == 1)
    return intervals;

  std::vector<std::vector<int>> result;

  // std::sort(intervals.begin(), intervals.end(), myComparator);
  std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &i1, const std::vector<int> &i2) {
    return i1[0] < i2[0];
  });

  std::vector<int> previous = intervals[0];
  std::vector<int> current{};

  for (int i{1}; i < intervals.size(); ++i) {
    current = intervals.at(i);

    // 1. previous and current do not overlap; add previous to result:
    if (current.at(0) > previous.at(1)) {
      result.push_back(previous);
      previous = current;
    }
    // 2. previous and current overlap and current ends after previous;
    // update previous ending to current':
    else if (current.at(1) >= previous.at(1)) {
      previous.at(1) = current.at(1);
    }

    if (i == intervals.size() - 1)
      result.push_back(previous);
  }

  return result;
}

int main() {
  std::vector<std::vector<int>> intervals, merged_intervals;

  intervals = {{1, 4}, {2, 5}, {7, 9}};
  merged_intervals = mergeIntervals(intervals);
  display2D(merged_intervals);

  intervals = {{6, 7}, {2, 4}, {5, 9}};
  merged_intervals = mergeIntervals(intervals);
  display2D(merged_intervals);

  intervals = {{1, 4}, {2, 6}, {3, 5}};
  merged_intervals = mergeIntervals(intervals);
  display2D(merged_intervals);

  return 0;
}

void display2D(std::vector<std::vector<int>> &intervals) {
  for (const auto &p : intervals)
    std::cout << "[" << p[0] << "," << p[1] << "]"
              << "  ";

  std::cout << "\n";
}