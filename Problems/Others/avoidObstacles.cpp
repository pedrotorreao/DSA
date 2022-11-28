/*********************************************************************************************/
/* Problem: CS Avoid Obstacles ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are given an array of integers representing coordinates of obstacles situated on a straight
  line. Assume that you are jumping from the point with coordinate 0 to the right. You are allowed
  only to make jumps of the same length represented by some integer.

  Find the minimal length of the jump enough to avoid all the obstacles.

  > Example:
  Input: inputArray = [5, 3, 6, 7, 9],
  Output: 4.
 
--Inputs:
  -int[]: array of integers representing the obstacles' coordinates.

--Output:
  -int: minimum jump length to avoid all obstacles.

--Constraints:
  :: 2 ≤ inputArray.length ≤ 1000
  :: 1 ≤ inputArray[i] ≤ 1000

--Reasoning: See comments below.

--Time complexity: O(N^2), worst case. O(N), in average.
    The outer loop will run for at most N iterations, where N is the value of the max element in
    'obstacles', i.e. the furthest obtacle coordinate, since we increment 'jumpLength' by 1.
    Theoretically, the inner loop would iterate over all the elements in the input but, for most
    cases, it's safe to say that we'll break out of this loop earlier once we find an obstacle.

--Space complexity: O(1), no input dependent space needs to be allocated.

*/

#include <iostream>
#include <vector>

int avoidObstacles(std::vector<int> &obstacles) {
  int jumpLength{1};
  bool obstacleNotAvoided = true;

  while (obstacleNotAvoided) {

    obstacleNotAvoided = false;
    ++jumpLength;

    // Check if jumping with current 'jumpLength' hits an obstacle,
    // i.e. (obstacleCoord % jumpLength == 0):
    for (const auto &obstacleCoord : obstacles) {
      // If an obstacle is hit, increase the 'jumpLength' and
      // check again:
      if (obstacleCoord % jumpLength == 0) {
        obstacleNotAvoided = true;
        break;
      }
    }
  }

  return jumpLength;
}

int main() {
  std::vector<int> obstacles{};
  int expec{}, res{};

  obstacles = {5, 3, 6, 7, 9};
  expec = 4;
  res = avoidObstacles(obstacles);
  std::cout << "Min. jump length: " << res << "    -Expecting: " << expec
            << (expec == res ? "     [PASSED]\n\n" : "     [FAILED]\n\n");

  obstacles = {1, 4, 10, 6, 2};
  expec = 7;
  res = avoidObstacles(obstacles);
  std::cout << "Min. jump length: " << res << "    -Expecting: " << expec
            << (expec == res ? "     [PASSED]\n\n" : "     [FAILED]\n\n");

  obstacles = {1000, 999};
  expec = 6;
  res = avoidObstacles(obstacles);
  std::cout << "Min. jump length: " << res << "    -Expecting: " << expec
            << (expec == res ? "     [PASSED]\n\n" : "     [FAILED]\n\n");

  return 0;
}