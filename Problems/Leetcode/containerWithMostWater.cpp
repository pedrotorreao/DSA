/******************************************************************************
Problem: LC 11. Container With Most Water
*******************************************************************************/
/*
--Problem statement:
  You are given an integer array 'height' of length 'n'. There are 'n' vertical lines
  drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
  Find two lines that together with the x-axis form a container, such that the
  container contains the most water.
  Return the maximum amount of water a container can store.
  Notice that you may not slant the container.

  > Example 1:
  Input: height = [1,8,6,2,5,4,8,3,7]
  Output: 49
  Explanation:
    The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this
    case, the max area of water (blue section) the container can contain is 49.

  > Example 2:
  Input: height = [1,1]
  Output: 1

--Inputs:
  int[]: integer array height of length n

--Output:
  int: integer representing the maximum amount of water a container can store.

--Constraints:
    :: n == height.length
    :: 2 <= n <= 105
    :: 0 <= height[i] <= 104

--Reasoning: See comments below.

--Time complexity: O(N), where N is the size of the array.

--Space complexity: O(1), no additional input dependent memory needs to be allocated.

*/

#include <iostream>
#include <vector>

int maxArea(std::vector<int> &height) {
  const int SIZE = height.size();

  if (SIZE < 2)
    return 0;

  int left = 0, right = SIZE - 1, best_area{0}, curr_area{0};

  while (left < right) {
    // width: distance between pointers
    int curr_width = right - left;
    // height: height of the smallest line
    int curr_height = std::min(height.at(left), height.at(right));
    // area: width * height
    curr_area = curr_width * curr_height;

    // since moving either one of the pointers will decrease the width,
    // the max area will be smaller unless we find a higher line to compensate,
    // so, we move the pointers (shrink the window) until we find a good
    // candidate or the pointers meet:
    while (height.at(left) <= curr_height && left < right)
      ++left;
    while (height.at(right) <= curr_height && right > left)
      --right;

    // note: if the height[left] == h[right], it does not matter whether you
    // move the 'left' pointer (left++) or the right one (right--), because
    // if height[left] == h[right], neither (left+1, right) nor (left, right-1)
    // can be bettter solutions because the area obtained is necessarily smaller
    // than (left, right) since the 'height' will be constrained by the smaller
    // line and the width will have been made smaller.

    // keep track of the best area found so far:
    best_area = std::max(best_area, curr_area);
  }

  return best_area;
}

int main() {
  std::vector<int> nums{};
  int expec{0}, res{0};

  nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  expec = 49;
  res = maxArea(nums);
  std::cout << "Max area: " << res << "    -Expected: " << expec
            << (res == expec ? "     [PASSED]\n\n" : "     [FAILED]\n\n");

  nums = {1, 8, 6, 2, 5, 4, 7, 8, 3};
  expec = 48;
  res = maxArea(nums);
  std::cout << "Max area: " << res << "    -Expected: " << expec
            << (res == expec ? "     [PASSED]\n\n" : "     [FAILED]\n\n");

  nums = {8, 6, 2, 5, 4, 7, 8};
  expec = 48;
  res = maxArea(nums);
  std::cout << "Max area: " << res << "    -Expected: " << expec
            << (res == expec ? "     [PASSED]\n\n" : "     [FAILED]\n\n");

  return 0;
}
/*
One thing that is ignored in the explanation is the h[i] == h[j] case.
You need to prove that in this case,
*/