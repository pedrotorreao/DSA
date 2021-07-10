/****************************************************************/
/* Problem: House Robber ********/
/****************************************************************/
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

int rob(std::vector<int> &nums)
{
  // if the array size is zero, there are no houses to rob, return 0:
  if (nums.size() == 0)
  {
    return 0;
  }
  // if the array size is one, there is only one house to rob, so return its value:
  if (nums.size() == 1)
  {
    return nums.at(0);
  }
  int currHouseVal = nums.at(0);

  // if the array size is two and considering the robber cannot rob adjacent houses,
  // return the highest loot value:
  if (nums.size() == 2)
  {
    return std::max(currHouseVal, nums.at(1));
  }
  int nextHouseVal = std::max(currHouseVal, nums.at(1));

  int maxPossibleLoot{0};

  // traverse the rest of the array, comparing both options and storing the maximum
  // option up until that point:
  for (size_t i{2}; i < nums.size(); i++)
  {
    maxPossibleLoot = std::max(currHouseVal + nums.at(i), nextHouseVal);
    currHouseVal = nextHouseVal;
    nextHouseVal = maxPossibleLoot;
  }

  return maxPossibleLoot;
}

int main()
{
  std::vector<int> housesVal{114, 117, 207, 117, 235, 82, 90, 67, 143, 146, 53, 108, 200, 91, 80, 223, 58, 170, 110, 236, 81, 90, 222, 160, 165, 195, 187, 199, 114, 235, 197, 187, 69, 129, 64, 214, 228, 78, 188, 67, 205, 94, 205, 169, 241, 202, 144, 240};

  std::cout << "Max possible value: " << rob(housesVal) << "\n";

  return 0;
}

/* -- another approach (too slow): 
int robHelper(std::vector<int> &nums, int houseIdx)
{
  if (houseIdx >= nums.size())
  {
    return 0;
  }
  int robCurrentHouse = nums.at(houseIdx) + robHelper(nums, houseIdx + 2);
  int robNextHouse = robHelper(nums, houseIdx + 1);

  return std::max(robCurrentHouse, robNextHouse);
}

int rob(std::vector<int> &nums)
{
  return robHelper(nums, 0);
}
*/