/******************************************************************************
Problem: Sort Colors
*******************************************************************************/
/*
--Problem statement:
  Given an array nums with n objects colored red, white, or blue, sort them in-place
  so that objects of the same color are adjacent, with the colors in the order red,
  white, and blue.

  We will use the integers 0, 1, and 2 to represent the color red, white, and blue,
  respectively.

  You must solve this problem without using the library's sort function.

  > Example 1:
    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

  > Example 2:
    Input: nums = [2,0,1]
    Output: [0,1,2]

--Inputs:
  int[]: array of integers

--Output:
  void: array passed in as input should be updated

--Constraints:
    :: n == nums.length
    :: 1 <= n <= 300
    :: nums[i] is either 0, 1, or 2.

--Reasoning: See below.

--Time complexity: See b

--Space complexity: O(1), since there is no input dependent memory allocated.

*/

#include <iostream>
#include <map>
#include <vector>

void display1D(const std::vector<int> &arr);

/*
--Reasoning:
  We use a hashmap to map the colors to their frequencies. For this, we use a C++ map
  because it keeps the keys sorted, and since there are only 3 possible keys (0, 1 and 2),
  this will be at most O(N), where N is the amount of values in nums, instead of O(N*log(N)).
  After mapping the frequencies, we iterate over the map, replacing 'nums' elements according
  to their frequencies.

--Time complexity: O(N), where N is the amount of values in 'nums'.

--Space complexity: O(1), we allocate space for a map with size 3, which can be considered constant.
*/
void sortColors_1(std::vector<int> &nums) {
  std::map<int, int> hm;

  for (const auto &color : nums)
    ++hm[color];

  auto it = hm.begin();
  int i{0};

  while (it != hm.end()) {
    while (it->second) {
      nums.at(i) = it->first;
      --it->second;
      ++i;
    }
    ++it;
  }
}

/*
--Reasoning:
  We classify the array into four groups: red, white, unprocessed, and blue. Initially, all elements are
  considered unprocessed. Consider three pointers:
      left = 0,
      mid = 0,
      right = nums.size() - 1.
  The algorithm ensures that at any point, every element before left is 0 (red), every element after right
  is 2 (blue) and every element in between are either 0, 1 or 2 i.e. unprocessed. We'll use mid pointer (white)
  to traverse and check the array elements as long as the mid pointer (white) is less than the right pointer
  (blue), i.e. while(mid <= right).

  If the white pointer (mid) is red (nums[mid] == 0), we swap with the red pointer and move both white and red pointer forward. If the pointer is white (nums[white] == 1), the element is already in correct place, so we don't have to swap, just move the white pointer forward. If the white pointer is blue, we swap with the latest unclassified element.

  Three cases are possible:
    nums[mid] == 0:
      The 'white' pointer (mid) is 'red', swap(nums[left], nums[mid]) and move both 'white' and 'red' pointers
      forward, so we increment both left and mid variables, i.e. ++left and ++mid.
    nums[mid] == 1:
      The 'white' pointer is 'white', so the element is already in the correct position, there is no need for
      swapping, just move the 'white' pointer forward, i.e. ++mid.
    nums[mid] == 2:
      The 'white' pointer is 'blue', swap(nums[mid], nums[right]) and move the 'blue' pointer closer to 'white',
      i.e. decrement the 'right' variable, --right;

--Time complexity: O(N), where N is the amount of values in nums.

--Space complexity: O(1), there is no input dependent space allocated.
*/
void sortColors_2(std::vector<int> &nums) {
  int left = 0, mid = 0, right = nums.size() - 1;

  while (mid <= right) {
    switch (nums.at(mid)) {
    case 0:
      std::swap(nums.at(mid), nums.at(left));
      ++left, ++mid;
      break;
    case 1:
      ++mid;
      break;
    case 2:
      std::swap(nums.at(mid), nums.at(right));
      --right;
      break;
    }
  }
}

int main() {
  std::vector<int> colors{};

  std::cout << "original array: [2,0,2,1,1,0]\n";
  colors = {2, 0, 2, 1, 1, 0};
  sortColors_1(colors);
  display1D(colors);
  colors = {2, 0, 2, 1, 1, 0};
  sortColors_2(colors);
  display1D(colors);

  std::cout << "original array: [2,1,2,2,1,2,1,0,1,0,0,0,1,0,2,1,0]\n";
  colors = {2, 1, 2, 2, 1, 2, 1, 0, 1, 0, 0, 0, 1, 0, 2, 1, 0};
  sortColors_1(colors);
  display1D(colors);
  colors = {2, 1, 2, 2, 1, 2, 1, 0, 1, 0, 0, 0, 1, 0, 2, 1, 0};
  sortColors_2(colors);
  display1D(colors);

  return 0;
}

void display1D(const std::vector<int> &arr) {
  std::cout << "[ ";
  for (const auto &a : arr)
    std::cout << a << " ";

  std::cout << "]\n\n";
}