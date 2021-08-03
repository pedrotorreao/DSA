/*******************************************************************************************/
/* Problem: Zero-One Knapsack - Dynamic Programming Approach                         *******/
/*******************************************************************************************/
/*
Given the weights and values of N items, add these items to a knapsack which has a total 
capacity. Find the maximum profit that can be made by adding items to the knapsack without
exceeding its total capacity.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

// ---- Top Down Approach - Memoization ----:
int knapSackHelper(std::vector<int> values, std::vector<int> weights, std::vector<std::vector<int>> &dp, int totalCapacity, int currentId)
{
  // invalid argument:
  if (currentId < 0)
  {
    throw std::invalid_argument("Invalid arguments for current index");
  }

  // base case:
  // - we've reached total capacity
  // - we've checked the whole dataset already
  if (totalCapacity <= 0 || currentId >= values.size())
  {
    return 0;
  }

  if (dp.at(currentId).at(totalCapacity) == -1)
  {
    int profitCurr = 0;

    // in case current element does not exceed the total capacity of the knapsack, add it:
    if (weights[currentId] <= totalCapacity)
    {
      profitCurr = values[currentId] + knapSackHelper(values, weights, dp, totalCapacity - weights[currentId], currentId + 1);
    }

    // otherwise, add next element check next element:
    int profitNext = knapSackHelper(values, weights, dp, totalCapacity, currentId + 1);

    dp.at(currentId).at(totalCapacity) = std::max(profitCurr, profitNext);
  }

  return dp.at(currentId).at(totalCapacity);
}

int knapSackTD(std::vector<int> values, std::vector<int> weights, int totalCapacity, int currentId)
{
  std::vector<std::vector<int>> dp(values.size(), std::vector<int>(totalCapacity + 1, -1));

  return knapSackHelper(values, weights, dp, totalCapacity, currentId);
}

// ---- Bottom Up Approach - Tabulation ----:
int knapSackBU(std::vector<int> values, std::vector<int> weights, int totalCapacity, int currentId)
{
  // invalid argument:
  if (currentId < 0 || currentId >= values.size())
  {
    throw std::invalid_argument("Invalid arguments for current index");
  }
  // base case:
  // - we've reached total capacity
  // - we've checked the whole dataset already
  if (totalCapacity <= 0 || values.size() == 0 || weights.size() != values.size())
  {
    return 0;
  }

  int numOfRows = values.size() + 1; // adding a dummy row to avoid array indexing issues
  int numOfCols = totalCapacity + 1; // adding a dummy col to avoid array indexing issues

  // matrix to store the calculated results - rows are loot values, cols represent total capacity left:
  std::vector<std::vector<int>> dp(numOfRows, std::vector<int>(numOfCols));

  for (int i{0}; i < numOfRows; i++)
  { // Fill 1st column w/ 0s as it is a dummy column:
    dp.at(i).at(0) = 0;
  }

  for (int i{0}; i < numOfCols; i++)
  { // Fill last row w/ 0s as it is a dummy row:
    dp.at(numOfRows - 1).at(i) = 0;
  }

  for (int row{numOfRows - 2}; row >= 0; row--)
  {
    for (int col{1}; col < numOfCols; col++)
    {
      int profitCurr{0}, profitNext{0};
      // col value represents current capacity:
      if (weights.at(row) <= col)
      { // choose current element in case its weight doesn't exceed total capacity left:
        profitCurr = values.at(row) + dp.at(row + 1).at(col - weights.at(row));
      }
      profitNext = dp.at(row + 1).at(col);

      dp.at(row).at(col) = std::max(profitCurr, profitNext);
    }
  }
  return dp.at(0).at(totalCapacity);
}

// ---- Driver code: ----:
int main()
{
  std::vector<int> lootValues{31, 26, 72, 17};
  std::vector<int> lootWeights{3, 1, 5, 2};
  int maxWeight = 7;

  std::cout << "Max. Knapsack Value:\n "
            << "\tTop Down: " << knapSackTD(lootValues, lootWeights, maxWeight, 0) << "\n"
            << "\tBottom Up: " << knapSackBU(lootValues, lootWeights, maxWeight, 0) << "\n";

  return 0;
}