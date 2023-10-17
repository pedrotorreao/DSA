/***
Problem: LC 57. Insert Interval

--Problem statement:
  You are given an array of non-overlapping intervals 'intervals' where intervals[i] = [starti, endi]
  represent the start and the end of the ith interval and 'intervals' is sorted in ascending order by
  starti. You are also given an interval newInterval = [start, end] that represents the start and
  end of another interval.

  Insert 'newInterval' into 'intervals' such that 'intervals' is still sorted in ascending order by starti
  and 'intervals' still does not have any overlapping intervals (merge overlapping intervals if necessary).

  Return 'intervals' after the insertion.

  > Example 1:
  Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
  Output: [[1,5],[6,9]]

  > Example 2:
  Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
  Output: [[1,2],[3,10],[12,16]]
  Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

--Inputs:
  int[][]: array of intervals

--Output:
  int[][]: array of the non-overlapping intervals with new_interval inserted

--Constraints:
    :: 1 <= intervals.length <= 10^4
    :: intervals[i].length == 2
    :: 0 <= starti <= endi <= 10^5
    :: intervals is sorted by starti in ascending order.
    :: new_interval.length == 2
    :: 0 <= start <= end <= 10"5

--Time complexity:
    O(N), where N is the total number of intervals in the input array. Even though we have 3 for loops,
    we only go through the entire array of intervals once.

--Space complexity:
    O(1) if we ignore the result list. O(N),if we take into account the resulting list,
    where N is the length of the input interval list.

*/
#include <algorithm>
#include <iostream>
#include <vector>

void display2D(std::vector<std::vector<int>> &vec);

std::vector<std::vector<int>> insertInterval(std::vector<std::vector<int>> &intervals,
                                             std::vector<int> &new_interval) {
  if (intervals.size() == 0)
    return std::vector<std::vector<int>>({new_interval});
  if (new_interval.size() == 0)
    return intervals;

  std::vector<std::vector<int>> result;

  int i{0};

  // skip and add to result all intervals that come before the 'new_interval':
  for (; i < intervals.size() && intervals[i][1] < new_interval[0]; i++) {
    result.push_back(intervals[i]);
  }

  // merge all intervals that overlap with 'new_interval':
  //  a. we know intervals[i] ends after new_interval begin:
  //      intervals[i][1] >= new_interval[0]
  //  b. so, they either overlap (i.e. intervals[i][0] <= new_interval[1]) and
  //      we need to merge them (1.:), or they don't overlap at all and we just found the insertion
  //      point for new_interval (i.e. intervals[i][0] > new_interval[1]) in which case we
  //      just need to insert new_interval (skip 1. and go straight to 2.).

  // 1.:
  for (; i < intervals.size() && intervals[i][0] <= new_interval[1]; i++) {
    new_interval[0] = std::min(intervals[i][0], new_interval[0]);
    new_interval[1] = std::max(intervals[i][1], new_interval[1]);
  }

  // 2.:
  result.push_back(new_interval);

  for (; i < intervals.size(); i++) {
    result.push_back(intervals[i]);
  }

  return result;
}

int main() {
  std::vector<std::vector<int>> intervals, merged_intervals;
  std::vector<int> new_interval;

  intervals = {{1, 3}, {5, 7}, {8, 12}};
  new_interval = {4, 6};
  merged_intervals = insertInterval(intervals, new_interval);
  display2D(merged_intervals);

  intervals = {{1, 3}, {5, 7}, {8, 12}};
  new_interval = {4, 10};
  merged_intervals = insertInterval(intervals, new_interval);
  display2D(merged_intervals);

  intervals = {{2, 3}, {5, 7}};
  new_interval = {1, 4};
  merged_intervals = insertInterval(intervals, new_interval);
  display2D(merged_intervals);

  return 0;
}

void display2D(std::vector<std::vector<int>> &intervals) {
  for (const auto &p : intervals)
    std::cout << "[" << p[0] << "," << p[1] << "]"
              << "  ";

  std::cout << "\n";
}
