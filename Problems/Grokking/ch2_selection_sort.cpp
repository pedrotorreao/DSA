/******************************************************************************
Grokking Algorithms - Chapter 2: Selection Sort - TC: O(N^2)
*******************************************************************************/
#include <iostream>
#include <limits>
#include <vector>

void print_arr(const std::vector<int> &nums);

// this algorithm manages the input array by processing it into two subarrays,
//    sorted: from 0 to i-1
//    unsorted: from i to N-1
// then, it sorts the input array by repeatedly finding the smallest value in
// the unsorted portion and moving it to its correct position:
std::vector<int> selection_sort(std::vector<int> nums) {
  const int N = nums.size();
  //
  for (int i{0}; i < N; i++) {
    // position of the smallest element in the unsorted portion:
    int min_idx = i;
    for (int j{i + 1}; j < N; j++) {
      // look for a smaller value in the unsorted subarray:
      if (nums.at(j) < nums.at(min_idx))
        min_idx = j;
    }

    int curr_min_val = nums.at(min_idx); // current smallest value
    nums.at(min_idx) = nums.at(i);       // move the element at the wrong position
    nums.at(i) = curr_min_val;           // place the smallest element at the correct position
  }

  return nums;
}

int main() {
  std::vector<int> nums{}, sorted{};

  nums = {9, 85, -5, 10, 0, -17, 123, 3, 67};
  sorted = selection_sort(nums);
  std::cout << "-- inital: ";
  print_arr(nums);
  std::cout << "-- sorted: ";
  print_arr(sorted);
}

void print_arr(const std::vector<int> &nums) {
  std::cout << "[ ";
  for (auto &num : nums)
    std::cout << num << "  ";
  std::cout << "]\n";
}