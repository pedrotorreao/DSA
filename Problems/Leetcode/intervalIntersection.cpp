/***
Problem: LC 986. Interval List Intersections

--Problem statement:
  You are given two lists of closed intervals, 'firstList' and 'secondList', where firstList[i] = [starti, endi]
  and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

  Return the intersection of these two interval lists.

  A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

  The intersection of two closed intervals is a set of real numbers that are either empty or represented as
  a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

  > Example 1:
    Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
    Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

  > Example 2:
    Input: firstList = [[1,3],[5,9]], secondList = []
    Output: []

--Inputs:
  int[][]: first interval list
  int[][]: second interval list

--Output:
  int[][]: result list containing the intersection of these two interval lists.

--Constraints:
    :: 0 <= firstList.length, secondList.length <= 1000
    :: firstList.length + secondList.length >= 1
    :: 0 <= starti < endi <= 109
    :: endi < starti+1
    :: 0 <= startj < endj <= 109
    :: endj < startj+1

--Time complexity:
    O(N+M), since we only loop through each list once, where N and M are the number
    of intervals in each input list.

--Space complexity:
    O(1) if we ignore the result list. O(N),if we take into account the resulting list,
    where N is the length of the input interval list.

*/
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>> &firstList, std::vector<std::vector<int>> &secondList) {
    if (firstList.size() == 0 || secondList.size() == 0)
      return std::vector<std::vector<int>>();

    std::vector<std::vector<int>> intersections;

    std::vector<std::vector<int>>::iterator itr_l1 = firstList.begin();
    std::vector<std::vector<int>>::iterator itr_l2 = secondList.begin();

    // Iterate over both lists at once and check if any two intervals overlap.
    // If two intervals overlap, we will insert the overlapped portion of them
    // into the result list, 'intersections', and move to the next interval.
    while (itr_l1 != firstList.end() && itr_l2 != secondList.end()) {
      // No overlap:
      //   a. current firstList interval ends before secondList' one,
      // advance to the next interval in firstList:
      if ((*itr_l1).at(1) < (*itr_l2).at(0)) {
        ++itr_l1;
        continue;
      }
      //   b. current secondList interval ends before firstList' one,
      // advance to the next interval in secondList:
      if ((*itr_l2).at(1) < (*itr_l1).at(0)) {
        ++itr_l2;
        continue;
      }

      // Calculate the overlapping interval:
      int a = std::max((*itr_l1).at(0), (*itr_l2).at(0)); // highest start time
      int b = std::min((*itr_l1).at(1), (*itr_l2).at(1)); // lowest end time

      intersections.push_back({a, b}); // add overlapping interval to the result

      // For the interval list in which the current interval ends first,
      // advance to the next interval, or move both in case they end in
      // the same position:
      if ((*itr_l1).at(1) < (*itr_l2).at(1))
        ++itr_l1;
      else if ((*itr_l2).at(1) < (*itr_l1).at(1))
        ++itr_l2;
      else {
        ++itr_l1;
        ++itr_l2;
      }
    }

    return intersections;
  }

  void display2D(std::vector<std::vector<int>> intervals) {
    for (const auto &p : intervals)
      std::cout << "[" << p[0] << "," << p[1] << "]"
                << "  ";

    std::cout << "\n";
  }
};

int main() {
  Solution s;
  std::vector<std::vector<int>> l1;
  std::vector<std::vector<int>> l2;

  l1 = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
  l2 = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
  s.display2D(s.intervalIntersection(l1, l2));

  l1 = {{1, 3}, {5, 6}, {7, 9}};
  l2 = {{2, 3}, {5, 7}};
  s.display2D(s.intervalIntersection(l1, l2));

  return 0;
}