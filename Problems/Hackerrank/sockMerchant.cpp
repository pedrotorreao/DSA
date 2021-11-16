/*********************************************************************************************/
/* Problem: Sock Merchant (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  There is a large pile of socks that must be paired by color. Given an array of integers
  representing the color of each sock, determine how many pairs of socks with matching colors
  there are.
  > Example:
    n = 7         ar = [1,2,1,2,1,3,2]
    There is one pair of color 1 and one of color 2. There are three odd socks left, one of each
    color. The number of pairs is 2.

  > Input:
      int n: the number of socks in the pile
      int ar[n]: the colors of each sock

  > Output:
      int: the number of pairs

  > Constraints:
    1 <= n <= 100
    1 <= ar[i] <= 100 where 0 <= i < n

--Reasoning:
    Iterate over the input array mapping each element and checking if an element equal to the current
    element has already been mapped (i.e. socks[element]=true). If so, it means that we now have
    formed a new pair (the one mapped + the current), so add one more pair to the result and "remove"
    this one from the hash table. In case it has been mapped yet, add it to the hash table.

--Time complexity: O(n), where n is the size of the input array.

--Space complexity: O(n), due to the hash table created which, in the worst case, will have only
socks without pairs.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

int sockMerchant(const std::vector<int> &ar)
{
  int pairs{0};
  std::unordered_map<int, bool> socks;

  for (const auto &a : ar)
  {
    if (!socks[a])
    {
      socks[a] = true;
    }
    else
    {
      ++pairs;
      socks[a] = false;
    }
  }

  return pairs;
}

int main()
{
  std::vector<int> all_socks{1, 2, 1, 2, 1, 3, 2};
  int pairs = sockMerchant(all_socks);
  std::cout << "Number of pairs - Expected: 2\t\tResult: " << pairs << (pairs == 2 ? "\tPASSED\n" : "\tFAILED\n");

  all_socks = {10, 20, 20, 10, 10, 30, 50, 10, 20};
  pairs = sockMerchant(all_socks);
  std::cout << "Number of pairs - Expected: 3\t\tResult: " << pairs << (pairs == 3 ? "\tPASSED\n" : "\tFAILED\n");

  all_socks = {4, 5, 5, 5, 6, 6, 4, 1, 4, 4, 3, 6, 6, 3, 6, 1, 4, 5, 5, 5};
  pairs = sockMerchant(all_socks);
  std::cout << "Number of pairs - Expected: 9\t\tResult: " << pairs << (pairs == 9 ? "\tPASSED\n" : "\tFAILED\n");

  return 0;
}