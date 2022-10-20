/******************************************************************************
Grokking Algorithms - Chapter 4: Recursive Sum
*******************************************************************************/

#include <iostream>
#include <vector>

int rec_sum(std::vector<int> nums) {
  // base case:
  if (nums.size() == 1)
    return nums.at(0);

  // recursive case:
  int curr = nums.back();
  nums.pop_back();

  return curr + rec_sum(nums);
}

int main() {
  std::vector<int> nums{};

  nums = {1, 2, 3, 4};
  std::cout << "Sum: " << rec_sum(nums) << "\n";

  nums = {11, 0, 0, 0, 0, 1};
  std::cout << "Sum: " << rec_sum(nums) << "\n";

  return 0;
}
