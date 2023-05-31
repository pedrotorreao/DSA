/*********************************************************************************************/
/*************************************** Problem: kSum ***************************************/
/*********************************************************************************************/
/*
--Problem statement:
  Given an array 'nums' of 'n' integers, return an array of all the unique k-plets
  [nums[a], nums[b], nums[c], nums[d], ... nums[k]] such that:
    :: 0 <= a, b, c, d, ... k < n
    :: a, b, c, d, ... k are distinct.
    :: nums[a] + nums[b] + nums[c] + nums[d] + ... + nums[k] == target

  You may return the answer in any order.

  > Example 1:
    Input: nums = [1,0,-1,0,-2,2], target = 0
    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

  > Example 2:
    Input: nums = [2,2,2,2,2], target = 8
    Output: [[2,2,2,2]]

--Inputs:
  -int nums[n]: integer array nums
  -int: target value
  -int: k indicating number of unique values to be found

--Output:
  -int arr[][]: array of k-plets which satisfy the stated condition.

--Reasoning: See comments below.

--Time Complexity: O(N^(k-1))

--Space Complexity: O(N)

*/

#include <algorithm>
#include <iostream>
#include <vector>

void display2D(const std::vector<std::vector<int>> &arr);

class KSum {
public:
  // output 2D array containing matching k-sums:
  std::vector<std::vector<int>> ans;

  // entry point to solution:
  std::vector<std::vector<int>> kSum(std::vector<int> &nums, int target, int k) {
    // sort input array - TC: O(n*log(n)):
    std::sort(nums.begin(), nums.end());
    // call generalized sum:
    this->anySum(nums, target, k);

    return this->ans;
  }

  void anySum(std::vector<int> &nums, int target, int k) {
    // temp array for storing quads being analyzed:
    std::vector<int> path;
    this->dfs(nums, 0, (int)nums.size() - 1, k, target, path);
  }

  void dfs(std::vector<int> &nums, int l, int r, int k, int target, std::vector<int> &path) {
    // same problem as 2Sum:
    if (k == 2) {
      while (l < r) {
        // a match was found:
        if (nums.at(l) + nums.at(r) == target) {
          // add the 2 missing values to the current sum path, i.e. quad:
          path.push_back(nums.at(l));
          path.push_back(nums.at(r));
          // add current quad to the answer:
          ans.push_back(path);
          // remove added from the current sum path to avoid duplicate values:
          path.pop_back();
          path.pop_back();

          // skip duplicate values:
          while (l + 1 < r && nums.at(l) == nums.at(l + 1))
            ++l; // this increment advances till the last duplicate,
          ++l;   // but we need to advance past it.

          // move right pointer closer:
          --r;
        }
        // current sum is too large, decrement right pointer to decrease it:
        else if (nums.at(l) + nums.at(r) > target)
          --r;
        // current sum is too small, increment left pointer to increase it:
        else
          ++l;
      }
    }

    // reduce the problem recursively to 2Sum:
    while (l < r) {
      // add 'nums.at(l)' to the current sum path:
      path.push_back(nums.at(l));
      // recursive call for (k-1)Sum taking 'nums.at(l)' as the leftmost element in the sum:
      dfs(nums, l + 1, r, k - 1, target - nums.at(l), path);
      // remove 'nums.at(l)' from the current sum path to avoid duplicate values:
      path.pop_back();

      // skip duplicate 'nums.at(l)':
      while (l + 1 < r && nums.at(l) == nums.at(l + 1))
        ++l; // this increment advances till the last duplicate,
      ++l;   // but we need to advance past it.
    }
  }

  void clearAns(void) {
    this->ans.clear();
  }
};

int main() {
  std::vector<int> nums{};
  int k{0}, target{0};

  KSum ks;

  nums = {-3, 0, 32, 8, 1, -4, -11, 10, 5, 72, -29, 44};
  // nums sorted: [-29,-11,-4,-3,0,1,5,8,10,32,44,72]

  k = 2;
  target = -40;
  display2D(ks.kSum(nums, target, k));
  ks.clearAns();

  k = 2;
  target = 15;
  display2D(ks.kSum(nums, target, k));
  ks.clearAns();

  k = 3;
  target = -2;
  display2D(ks.kSum(nums, target, k));
  ks.clearAns();

  k = 4;
  target = 40;
  display2D(ks.kSum(nums, target, k));
  ks.clearAns();

  k = 5;
  target = 36;
  display2D(ks.kSum(nums, target, k));
  ks.clearAns();

  k = 6;
  target = -21;
  display2D(ks.kSum(nums, target, k));
  ks.clearAns();

  k = 7;
  target = 64;
  display2D(ks.kSum(nums, target, k));
  ks.clearAns();
}

void display2D(const std::vector<std::vector<int>> &arr) {
  std::cout << "[";
  for (const auto &r : arr) {
    std::cout << "[";
    for (const auto &c : r)
      std::cout << c << " ";
    std::cout << "] ";
  }
  std::cout << "]\n";
}