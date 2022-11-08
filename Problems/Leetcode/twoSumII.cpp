/*********************************************************************************************/
/* Problem: LC 167. Two Sum II - Input Array Is Sorted ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
  find two numbers such that they add up to a specific target number. Let these two numbers be
  numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

  Return the indices of the two numbers, index1 and index2, added by one as an integer array
  [index1, index2] of length 2.

  The tests are generated such that there is exactly one solution. You may not use the same
  element twice.

  Your solution must use only constant extra space.

  > Example 1:
      Input: numbers = [2,7,11,15], target = 9
      Output: [1,2]
      Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

  > Example 2:
      Input: numbers = [2,3,4], target = 6
      Output: [1,3]
      Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

  > Example 3:
      Input: numbers = [-1,0], target = -1
      Output: [1,2]
      Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

--Input:
  int arr[n]: an array of sorted integers

--Output:
  int[2]: indices of two numbers such that they add up to a specific target number

--Constraints:
  :: 2 <= numbers.length <= 3 * 104
  :: -1000 <= numbers[i] <= 1000
  :: numbers is sorted in non-decreasing order.
  :: -1000 <= target <= 1000
  :: The tests are generated such that there is exactly one solution.

--Reasoning: See comments below.

--Time complexity: O(N), where N is the size of the input array.

--Space complexity: O(1), no additional input dependent space is allocated.

*/

#include <iostream>
#include <vector>

template <typename T>
void display1D(const std::vector<T> &arr);

std::vector<int> twoSum(std::vector<int> &numbers, int target) {
  std::vector<int> ans{};

  // return an empty array if:
  //  a. the array contain only 1 element or is empty
  //  b. the target value is a negative value and we don't have negative values in the input array.
  if (numbers.size() < 2 || (target < 0 && numbers.at(0) >= 0))
    return ans;

  // initialize two pointers:
  //  a. l_ptr: begins at the start, in the lower values.
  //  b. r_ptr: beign at the end, in the higher values.
  int l_ptr = 0, r_ptr = numbers.size() - 1, curr_sum{0};

  // iterate while pointers don't meet each other:
  while (l_ptr < r_ptr) {
    // calculate the current sum between elements at the pointers positions:
    curr_sum = numbers.at(l_ptr) + numbers.at(r_ptr);

    // if there's a match, return both pointers positions:
    if (curr_sum == target) {
      ans.push_back(l_ptr + 1);
      ans.push_back(r_ptr + 1);

      return ans;
    }
    // current sum is less smaller than target value: advance pointer in the lower side by 1:
    if (curr_sum < target)
      ++l_ptr;
    // current sum is more than target value: retreat pointer in the higher side by 1:
    else
      --r_ptr;
  }

  return ans;
}

int main() {
  std::vector<int> nums{}, res{};
  int target{};

  nums = {2, 7, 11, 15};
  target = 9;
  std::cout << "Input: [ 2 7 11 15 ]\n";
  std::cout << "Expected: [ 1 2 ]\n";
  res = twoSum(nums, target);
  std::cout << "Result: ";
  display1D<int>(res);

  nums = {2, 3, 4};
  target = 6;
  std::cout << "Input: [ 2 3 4 ]\n";
  std::cout << "Expected: [ 1 3 ]\n";
  res = twoSum(nums, target);
  std::cout << "Result: ";
  display1D<int>(res);

  nums = {-1, 0};
  target = -1;
  std::cout << "Input: [ -1 0 ]\n";
  std::cout << "Expected: [ 1 2 ]\n";
  res = twoSum(nums, target);
  std::cout << "Result: ";
  display1D<int>(res);

  return 0;
}

template <typename T>
void display1D(const std::vector<T> &arr) {
  std::cout << "[ ";
  for (const auto &a : arr)
    std::cout << a << " ";

  std::cout << "]\n\n";
}