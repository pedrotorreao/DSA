/* * * * * * * * * * * * * * * * * *
Problem: LC 66. Plus One

--Problem statement:
You are given a large integer represented as an integer array digits, where
each digits[i] is the ith digit of the integer. The digits are ordered from most
significant to least significant in left-to-right order. The large integer does
not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

  > Example 1:
      Input: digits = [1,2,3]
      Output: [1,2,4]
      Explanation:
        The array represents the integer 123.
        Incrementing by one gives 123 + 1 = 124.
        Thus, the result should be [1,2,4].

  > Example 2:
      Input: digits = [4,3,2,1]
      Output: [4,3,2,2]
      Explanation:
        The array represents the integer 4321.
        Incrementing by one gives 4321 + 1 = 4322.
        Thus, the result should be [4,3,2,2].

  > Example 3;
      Input: digits = [9]
      Output: [1,0]
      Explanation: The array represents the integer 9.
      Incrementing by one gives 9 + 1 = 10.
      Thus, the result should be [1,0].

--Constraints:
    :: 1 <= digits.length <= 100
    :: 0 <= digits[i] <= 9
    :: digits does not contain any leading 0's.

--Inputs:
  - int[]: array of integers, digits

--Outputs:
  - int[]: resulting array of digits incremented by 1.

--Reasoning: Simple iterative approach.

--Time complexity:
    :: O(n), where n is the total number of elements in the input array.

--Space complexity:
    :: O(n), in the worst case scenario where the array is completely filled with 9s
    and there is a carry over to first element and a new array is created.
* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <vector>

void display1D(const std::vector<int> &nums);

class Solution {
public:
  static std::vector<int> plusOne(std::vector<int> &digits) {
    if (digits.empty())
      return digits;

    bool needCarry = false;
    if (digits.at(digits.size() - 1) == 9) {
      digits.at(digits.size() - 1) = 0;
      needCarry = true;
    } else {
      digits.at(digits.size() - 1) += 1;
      return digits;
    }

    int i = digits.size() - 2;
    while (needCarry && i >= 0) {
      if (digits.at(i) == 9) {
        digits.at(i) = 0;
      } else {
        digits.at(i) += 1;
        needCarry = false;
      }
      --i;
    }

    if (!needCarry)
      return digits;

    std::vector<int> res{1};

    res.insert(res.begin() + 1, digits.begin(), digits.end());

    return res;
  }
};

int main() {
  std::vector<int> digits{};
  std::vector<int> result{};

  digits = {1, 2, 3};
  std::cout << "Input array: ";
  display1D(digits);
  result = Solution::plusOne(digits);
  std::cout << "Result: ";
  display1D(result);
  std::cout << "\n";

  digits = {4, 3, 2, 1};
  std::cout << "Input array: ";
  display1D(digits);
  result = Solution::plusOne(digits);
  std::cout << "Result: ";
  display1D(result);
  std::cout << "\n";

  digits = {9};
  std::cout << "Input array: ";
  display1D(digits);
  result = Solution::plusOne(digits);
  std::cout << "Result: ";
  display1D(result);
  std::cout << "\n";
}

void display1D(const std::vector<int> &nums) {
  std::cout << "[ ";

  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " ";
  }

  std::cout << "]\n";
}