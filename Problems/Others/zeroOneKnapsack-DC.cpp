/*******************************************************************************************/
/* Problem: Zero-One Knapsack - Divide & Conquer Approach                            *******/
/*******************************************************************************************/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

int knapSackHelper(std::vector<int> values, std::vector<int> weights, int totalCapacity, int currentId)
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

  int profitCurr = 0;

  // in case current element does not exceed the total capacity of the knapsack, add it:
  if (weights[currentId] <= totalCapacity)
  {
    profitCurr = values[currentId] + knapSackHelper(values, weights, totalCapacity - weights[currentId], currentId + 1);
  }

  // otherwise, add next element check next element:
  int profitNext = knapSackHelper(values, weights, totalCapacity, currentId + 1);

  return std::max(profitCurr, profitNext);
}

int main()
{
  std::vector<int> lootValues{31, 26, 72, 17};
  std::vector<int> lootWeights{3, 1, 5, 2};
  int maxWeight = 7;

  int maxLootValue = knapSackHelper(lootValues, lootWeights, maxWeight, 0);

  std::cout << "Max. Knapsack Value: " << maxLootValue << "\n";

  return 0;
}