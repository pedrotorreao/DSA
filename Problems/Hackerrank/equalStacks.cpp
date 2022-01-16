/*********************************************************************************************/
/* Problem: Equal Stacks (HR)  ********/
/*********************************************************************************************/
/*
--Problem statement:
  You have three stacks of cylinders where each cylinder has the same diameter, but they may
  vary in height. You can change the height of a stack by removing and discarding its topmost
  cylinder any number of times. Find the maximum possible height of the stacks such that all of
  the stacks are exactly the same height. This means you must remove zero or more cylinders from
  the top of zero or more of the three stacks until they are all the same height, then return
  the height. Note: An empty stack is still a stack.
  > Example:
    a.) h1:[1,2,1,1]    h2:[1,1,2]    h3:[1,1]
      There are 4,3 and 2 cylinders in the three stacks, with their heights in the three arrays.
      Remove the top 2 cylinders from h1 (heights = [1, 2]) and from h2 (heights = [1, 1]) so that
      the three stacks all are 2 units tall. Return 2 as the answer.

--Inputs:
  - int h1[n1]: the first array of heights
  - int h2[n2]: the second array of heights
  - int h3[n3]: the third array of heights
  Note: The first element is the top cylinder of the stack.

--Output:
  - int: the height of the stacks when they are equalized

--Constraints:
  0 < n1,n2,n3 <= 10^3
  0 < height of any cylinder <= 100

--Reasoning: See comments below.

--Time complexity: O(N), where N is the number of plates in the largest stack.

--Space complexity: O(1), no additional input-dependent space is allocated.

*/
#include <algorithm>
#include <iostream>
#include <vector>

int equalStacks(std::vector<int> h1, std::vector<int> h2, std::vector<int> h3) {
  int sum_1{0}, sum_2{0}, sum_3{0};

  // reverse the input arrays to put the stack' tops at the back of the arrays:
  std::reverse(h1.begin(), h1.end());
  std::reverse(h2.begin(), h2.end());
  std::reverse(h3.begin(), h3.end());

  // get the total heigth (sum of plate values) of each stack:
  for (const auto &h : h1)
    sum_1 += h;
  for (const auto &h : h2)
    sum_2 += h;
  for (const auto &h : h3)
    sum_3 += h;

  // since we are only allowed to remove elements from the stacks, we begin by
  // tracking the min height (sum) among them and checking if it's possible to
  // match the other two to it by removing their top plates:
  int min_h = std::min(sum_1, std::min(sum_2, sum_3));

  // at each step we check if each stack has reached the min height, if not, we
  // pop its top and update its sum. If at the end of the current iteration the
  // stacks have the same height (sum), return this value; otherwise, update the
  // min height to be reached and keep iterating:
  while (true) {
    if (sum_1 > min_h) {
      sum_1 -= h1.back();
      h1.pop_back();
    }
    if (sum_2 > min_h) {
      sum_2 -= h2.back();
      h2.pop_back();
    }
    if (sum_3 > min_h) {
      sum_3 -= h3.back();
      h3.pop_back();
    }

    if (sum_1 == sum_2 && sum_2 == sum_3)
      return min_h;

    min_h = std::min(sum_1, std::min(sum_2, sum_3));
  }
}

int main() {
  std::vector<int> h1{1, 2, 1, 1};
  std::vector<int> h2{1, 1, 2};
  std::vector<int> h3{1, 1};

  std::cout << "Equalized height: " << equalStacks(h1, h2, h3) << "\n";

  h1 = {3, 2, 1, 1, 1};
  h2 = {4, 3, 2};
  h3 = {1, 1, 4, 1};

  std::cout << "Equalized height: " << equalStacks(h1, h2, h3) << "\n";

  return 0;
}