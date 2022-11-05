/******************************************************************************
Problem: LC 238. Product of Array Except Self
*******************************************************************************/
/*
--Problem statement:
  Given an integer array nums, return an array answer such that answer[i] is equal
  to the product of all the elements of nums except nums[i]. The product of any
  prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
  You must write an algorithm that runs in O(n) time and without using the division
  operation.

  > Example 1:
    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

   > Example 2:
    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]

--Inputs:
  int[]: array of integers

--Output:
  int[]: array of products

--Constraints:
    :: 2 <= nums.length <= 105
    :: -30 <= nums[i] <= 30
    :: The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does
not count as extra space for space complexity analysis.)

*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

void display1D(const std::vector<int> &arr);

std::vector<int> productExceptSelf_1(std::vector<int> &nums);

std::vector<int> productExceptSelf_2(std::vector<int> &nums);

std::vector<int> productExceptSelf_3(std::vector<int> &nums);

/*
  # Approach 4:
    --Reasoning:
      Instead of using two arrays for storing the products of all the elements before and after
      a given index 'i', we can store these product in two integer variables and update the output
      array as we go. We iterate from start and keep calculating 'left' product and updating the
      corresponding 'ans[i]' and, at the same time, we calculate the 'right' product from the end
      and update 'ans[n-1-i]'. When these products cross each other at the middle, we begin calculating
      the product
          'ans[i] = left[i] * right[i]',
      which, by the time 'i' reaches the end, is the same as the product of all the array elements
      except self at each index.

    --Time Complexity: O(N)

    --Space Complexity: O(1)
*/
std::vector<int> productExceptSelf(std::vector<int> &nums) {
  const int SIZE = nums.size();

  std::vector<int> ans(SIZE, 1);

  int left = 1, right = 1, i = 0;

  while (i < SIZE) {
    // product of the elements before nums[i]:
    ans.at(i) *= left;
    // update 'left' to include nums[i] in the next iteration:
    left *= nums.at(i);

    // product of the elements before nums[i]:
    ans.at(SIZE - i - 1) *= right;
    // update 'right' to include nums[SIZE-i-1] in the next iteration:
    right *= nums.at(SIZE - i - 1);

    ++i;
  }

  return ans;
}

int main() {
  std::vector<int> nums{}, res{};

  nums = {1, 2, 3, 4};
  res = productExceptSelf(nums);
  std::cout << "Expected: [24,12,8,6]\n"
            << "Result: ";
  display1D(res);

  nums = {-1, 1, 0, -3, 3};
  res = productExceptSelf(nums);
  std::cout << "Expected: [0,0,9,0,0]\n"
            << "Result: ";
  display1D(res);

  nums = {0, 0};
  res = productExceptSelf(nums);
  std::cout << "Expected: [0,0]\n"
            << "Result: ";
  display1D(res);

  nums = {2, 3, 0, 0};
  res = productExceptSelf(nums);
  std::cout << "Expected: [0,0,0,0]\n"
            << "Result: ";
  display1D(res);

  nums = {1, 2, 3, 0, 0};
  res = productExceptSelf(nums);
  std::cout << "Expected: [0,0,0,0]\n"
            << "Result: ";
  display1D(res);

  nums = {1, 0};
  res = productExceptSelf(nums);
  std::cout << "Expected: [0,1]\n"
            << "Result: ";
  display1D(res);

  return 0;
}

/*
  # Approach 1 - Naive Approach:
    --Reasoning: Use nested loops.

    --Time Complexity: O(N^2)

    --Space Complexity: O(1)
*/
std::vector<int> productExceptSelf_1(std::vector<int> &nums) {
  const int N = nums.size();
  std::vector<int> ans(N, 1);

  for (int i{0}; i < N; ++i) {
    for (int j{0}; j < N; ++j) {
      if (i == j)
        continue;

      ans.at(i) = ans.at(i) * nums.at(j);
    }
  }

  return ans;
}

/*
  # Approach 2:
    --Reasoning:
      First, we calculate the total product. Then, we iterate over 'nums[]' filling 'ans[]' with
      total_product divided by self. We only need to deal with the special cases in which 'nums[i]=0'.
      For these cases, we know the following:
          [I]. If there are more than 1 zero, then no matter which element is excluded during the product,
        there will always be a product by zero, so all the elements in the output array are zero.
          [II]. If there is only 1 zero in the array, all the elements in the output array will be zero,
        except for the position where the zero is present in nums[], since all the other elements except
        itself will be multiplied by this zero.
          [III]. If there are no zeros, then the element at position 'i' in the output array, 'ans[]', will
        be the total product divided by self, i.e.:
              ans[i] = total_product / nums[i].
      This approach is an improvement over the "# Approach 1" since there are no nested loops involved;
      however, it's not a valid solution to the problem according to the problem description since it
      uses the division operator.

    --Time Complexity: O(N)

    --Space Complexity: O(1)
*/
std::vector<int> productExceptSelf_2(std::vector<int> &nums) {
  const int SIZE = nums.size();

  // count zeros:
  int zeros = std::count(nums.begin(), nums.end(), 0);

  // [I] we have more than 1 zero present in nums[]:
  if (zeros > 1)
    return std::vector<int>(SIZE, 0);

  // calculate total product:
  int total_product{1};
  for (const auto &n : nums)
    if (n)
      total_product *= n;

  std::vector<int> ans(SIZE, 1);

  for (int i{0}; i < SIZE; ++i) {
    // [II] there is only 1 zero:
    if (zeros) {
      ans.at(i) = (nums.at(i) != 0) ? 0 : total_product;
      continue;
    }
    // [III] there are no zeros:
    ans.at(i) = total_product / nums.at(i);
  }

  return ans;
}

/*
  # Approach 3:
    --Reasoning:
      To solve the problem without using the division operator, we
      maintain two arrays, 'left[]' and 'right[]', where 'left[i]'
      has the product of all 'nums[j]' such that (j < i), and 'right[i]' has the product of all the
      elements 'num[j]' such that (j > i). Finally, the output array 'ans[]' can be
      calculated as
              'ans[i] = left[i] * right[i]',
      such that at a given position 'i' we have the product between all the elements before 'i', 'left[i]',
      multiplied by the product of all the elements after 'i', 'right[i]', which is the same as the product
      of all the array elements except self at each index.

    --Time Complexity:
      O(N), where N is the size of the 'nums[]' input array.

    --Space Complexity:
      O(N), since we allocate storage for the 'left[]' and 'right[]' arrays.
*/
std::vector<int> productExceptSelf_3(std::vector<int> &nums) {
  const int SIZE = nums.size();
  std::vector<int> ans(SIZE, 1), left(SIZE, 1), right(SIZE, 1);

  for (int l = 1; l < SIZE; ++l)
    left.at(l) = left.at(l - 1) * nums.at(l - 1);

  for (int r = SIZE - 2; r >= 0; --r)
    right.at(r) = right.at(r + 1) * nums.at(r + 1);

  for (int i = 0; i < SIZE; ++i)
    ans.at(i) = left.at(i) * right.at(i);

  return ans;
}

void display1D(const std::vector<int> &arr) {
  std::cout << "[ ";
  for (const auto &a : arr)
    std::cout << a << " ";

  std::cout << "]\n\n";
}