/***
Problem: LC 1423. Maximum Points You Can Obtain from Cards
(https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/)

--Problem statement:
There are several cards arranged in a row, and each card has an associated number of points.
The points are given in the integer array 'cardPoints'. In one step, you can take one card from
the beginning or from the end of the row. You have to take exactly 'k' cards.

Your score is the sum of the points of the cards you have taken. Given the integer array 'cardPoints'
and the integer 'k', return the maximum score you can obtain.

  > Example 1:
    Input: cardPoints = [1,2,3,4,5,6,1], k = 3
    Output: 12
    Explanation:
      After the first step, your score will always be 1. However, choosing the rightmost card first will
      maximize your total score. The optimal strategy is to take the three cards on the right, giving a
      final score of 1 + 6 + 5 = 12.

  > Example 2:
    Input: cardPoints = [2,2,2], k = 2
    Output: 4
    Explanation: Regardless of which two cards you take, your score will always be 4.

  > Example 3:
    Input: cardPoints = [9,7,7,9,7,7,9], k = 7
    Output: 55
    Explanation: You have to take all the cards. Your score is the sum of points of all cards.

--Inputs:
  - int[]: integer array 'cardPoints'
  - int: number of cards to be selected, 'k'

--Output:
  - int: maximum score obtained from selecting exactly 'k' cards

--Constraints:
    :: 1 <= cardPoints.length <= 10^5
    :: 1 <= cardPoints[i] <= 10^4
    :: 1 <= k <= cardPoints.length

--Reasoning: see comments below.

--Time complexity: O(N), where N is the size of the input array.

--Space complexity: O(1), since no input dependent memory needs to be allocated.

*/

#include <bits/stdc++.h>

class Solution {
public:
  static int maxScore(std::vector<int> &cardPoints, int k) {
    // if the number of cards that can be selected is greater than the total number of
    // cards on the input array, return the sum of all the array values:
    if (k >= cardPoints.size())
      return std::accumulate(cardPoints.begin(), cardPoints.end(), 0);

    const int N = cardPoints.size();
    // position pointers:
    int lIdx = 0, rIdx = N - k;
    // running sum:
    int currSum = std::accumulate(cardPoints.begin() + rIdx, cardPoints.end(), 0);
    // best card selection sum:
    int bestSum = currSum;

    while (rIdx < N) {
      // slide the window:
      currSum += cardPoints.at(lIdx) - cardPoints.at(rIdx);
      // update best result if a new maximum sum was found:
      bestSum = std::max(bestSum, currSum);

      ++rIdx;
      ++lIdx;
    }

    return bestSum;
  }
};

int main() {
  std::vector<int> points{};
  int k{0}, res{0}, expected{0};

  points = {1, 2, 3, 4, 5, 6, 1};
  k = 3;
  expected = 12;
  res = Solution::maxScore(points, k);
  std::cout << "-- Max. score possible when selecting <" << k << "> cards: " << res << (res == expected ? "\tPASSED" : "\tFAILED") << "\n";

  points = {2, 2, 2};
  k = 2;
  expected = 4;
  res = Solution::maxScore(points, k);
  std::cout << "-- Max. score possible when selecting <" << k << "> cards: " << res << (res == expected ? "\tPASSED" : "\tFAILED") << "\n";

  points = {9, 7, 7, 9, 7, 7, 9};
  k = 7;
  expected = 55;
  res = Solution::maxScore(points, k);
  std::cout << "-- Max. score possible when selecting <" << k << "> cards: " << res << (res == expected ? "\tPASSED" : "\tFAILED") << "\n";

  return 0;
}