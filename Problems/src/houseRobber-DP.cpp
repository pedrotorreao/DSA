/*****************************************************************/
/* Problem: House Robber - Dynamic Programming Approach ********/
/*****************************************************************/
/*
You are a professional robber planning to rob houses along a street. Each house has a 
certain amount of money stashed, the only constraint stopping you from robbing each of 
them is that adjacent houses have security systems connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the 
maximum amount of money you can rob tonight without alerting the police.

Example 1:
- Input: nums = [1,2,3,1]
- Output: 4
- Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.
*/
#include <iostream>
#include <vector>
#include <cmath>

// ---- Top Down Approach - Memoization ----:
int robHelper(std::vector<int> &nums, std::vector<int> &dp, int houseIdx)
{
  if (nums.size() == 0 || houseIdx >= nums.size())
  {
    return 0;
  }

  if (nums.size() == 1)
  {
    return nums.at(0);
  }

  if (dp.at(houseIdx) == 0)
  {
    int robCurrentHouse = nums.at(houseIdx) + robHelper(nums, dp, houseIdx + 2);
    int robNextHouse = robHelper(nums, dp, houseIdx + 1);

    dp.at(houseIdx) = std::max(robCurrentHouse, robNextHouse);
  }

  return dp.at(houseIdx);
}

int robTD(std::vector<int> &nums)
{
  std::vector<int> dp(nums.size() + 1);

  return robHelper(nums, dp, 0);
}

// ---- Bottom Up Approach - Tabulation ----:
int robBU(std::vector<int> &nums)
{
  std::vector<int> dp(nums.size() + 2);

  for (int i = nums.size() - 1; i >= 0; i--)
  {
    dp.at(i) = std::max(nums.at(i) + dp.at(i + 2), dp.at(i + 1));
  }
  return dp.at(0);
}

int main()
{
  std::vector<int> housesVal{114, 117, 207, 117, 235, 82, 90, 67, 143, 146, 53, 108, 200, 91, 80, 223, 58, 170, 110, 236, 81, 90, 222, 160, 165, 195, 187, 199, 114, 235, 197, 187, 69, 129, 64, 214, 228, 78, 188, 67, 205, 94, 205, 169, 241, 202, 144, 240};

  std::cout << "Max possible value - Top Down: " << robTD(housesVal) << "\tBottom Up: " << robBU(housesVal) << "\n"; // 4173

  housesVal = {6, 7, 1, 30, 8, 2, 4};
  std::cout << "Max possible value - Top Down: " << robTD(housesVal) << "\tBottom Up: " << robBU(housesVal) << "\n"; // 41

  housesVal = {20, 5, 1, 13, 6, 11, 40};
  std::cout << "Max possible value - Top Down: " << robTD(housesVal) << "\tBottom Up: " << robBU(housesVal) << "\n"; // 73

  return 0;
}