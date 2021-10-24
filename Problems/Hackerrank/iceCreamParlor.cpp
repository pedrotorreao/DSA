/*********************************************************************************************/
/* Problem: Ice Cream Parlor (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Each time Sunny and Johnny take a trip to the Ice Cream Parlor, they pool their money to buy
  ice cream. On any given day, the parlor offers a line of flavors. Each flavor has a cost
  associated with it. Given the value of money and the cost of each flavor for t trips to the
  Ice Cream Parlor, help Sunny and Johnny choose two distinct flavors such that they spend
  their entire pool of money during each visit. ID numbers are the 1-based index number
  associated with a cost. For each trip to the parlor, print the ID numbers for the two types
  of ice cream that Sunny and Johnny purchase as two space-separated integers on a new line. You
  must print the smaller ID first and the larger ID second.
  Example
    - cost = [2,1,3,5,6]
    - money = 5
    They would purchase flavor ID's 1 and 3 for a cost of 2+3=5. Use 1-based indexing for your
    response.
  Note:
    - Two ice creams having unique IDs i and j may have the same cost (i.e., cost[i] = cost[j])
    - There will always be a unique solution.
  Input:
    - int cost[n] the prices for each flavor
    - int money: the amount of money they have to spend
  Output:
    - int int: the indices of the two flavors they will purchase as two space-separated integers
    on a line
  Constraints:
    - 1<=t<=50
    - 2<=money<=10^9
    - 2<=n<=5*10^9
    - 1<=cost[i]<=10^9

--Reasoning:

--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <vector>
#include <unordered_map>

void whatFlavors(std::vector<int> cost, int money)
{
  std::unordered_map<int, int> cost_map;
  int diff{0};

  for (int i{1}; i < cost.size(); ++i)
  {
    diff = money - cost.at(i - 1);

    if (cost_map.find(diff) != cost_map.end())
    {
      std::cout << cost_map[diff] << " " << i << "\n";
      return;
    }

    if (cost_map.find(cost.at(i - 1)) == cost_map.end())
    {
      cost_map[cost.at(i - 1)] = i;
    }
  }
}

int main()
{
  std::vector<int> cost{2, 1, 3, 5, 6};
  int money{5};

  whatFlavors(cost, money);
  std::cout << "\n";

  cost = {1, 4, 5, 3, 2};
  money = 4;

  whatFlavors(cost, money);
  std::cout << "\n";

  cost = {2, 2, 4, 3};
  money = 4;

  whatFlavors(cost, money);
  std::cout << "\n";

  return 0;
}