/*********************************************************************************************/
/* Problem: LC 904. Fruit Into Baskets ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are visiting a farm that has a single row of fruit trees arranged from left to right.
  The trees are represented by an integer array 'fruits' where fruits[i] is the type of fruit
  the ith tree produces.
  You want to collect as much fruit as possible. However, the owner has some strict rules that
  you must follow:
    a. You only have two baskets, and each basket can only hold a single type of fruit. There
      is no limit on the amount of fruit each basket can hold.
    b. Starting from any tree of your choice, you must pick exactly one fruit from every tree
      (including the start tree) while moving to the right. The picked fruits must fit in one of
      your baskets.
    c. Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

  Given the integer array fruits, return the maximum number of fruits you can pick.

  > Example 1:
      Input: fruits = [1,2,1]
      Output: 3
      Explanation: We can pick from all 3 trees.

  > Example 2:
      Input: fruits = [0,1,2,2]
      Output: 3
      Explanation: We can pick from trees [1,2,2].
      If we had started at the first tree, we would only pick from trees [0,1].

  > Example 3:
      Input: fruits = [1,2,3,2,2]
      Output: 4
      Explanation: We can pick from trees [2,3,2,2]. If we had started at the first tree, we would
      only pick from trees [1,2].

--Inputs:
  int[]: integer array fruits

--Output:
  int: maximum number of fruits you can pick

--Constraints:
    :: 1 <= fruits.length <= 105
    :: 0 <= fruits[i] < fruits.length

--Reasoning: Sliding window approach.

--Time complexity: O(N), where N is the size of the input array.

--Space complexity:
    O(1), since we allocate space for at most 3 characters and their frequencies, which is not
    dependent on the input size, i.e. the array size.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

int totalFruit(std::vector<int> &fruits) {
  std::unordered_map<int, int> freq;
  int l{0}, r{0}, res{0}, n = fruits.size();

  for (; r < n; ++r) {
    ++freq[fruits.at(r)];

    while (freq.size() > 2) {
      if (--freq[fruits.at(l)] == 0)
        freq.erase(fruits.at(l));
      ++l;
    }
    res = std::max(res, r - l + 1);
  }
  return res;
}

int main() {
  std::vector<int> fruits{1, 2, 1};
  int expec{3};
  int res = totalFruit(fruits);
  std::cout << "Total number of picked fruits: " << res
            << " \t--Expected: " << expec
            << (res == expec ? "\t--[PASSED]" : "\t--[FAILED]")
            << "\n";

  fruits = {0, 1, 2, 2};
  res = totalFruit(fruits);
  std::cout << "Total number of picked fruits: " << res
            << " \t--Expected: " << expec
            << (res == expec ? "\t--[PASSED]" : "\t--[FAILED]")
            << "\n";

  fruits = {1, 2, 3, 2, 2};
  expec = 4;
  res = totalFruit(fruits);
  std::cout << "Total number of picked fruits: " << res
            << " \t--Expected: " << expec
            << (res == expec ? "\t--[PASSED]" : "\t--[FAILED]")
            << "\n";

  fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  expec = 5;
  res = totalFruit(fruits);
  std::cout << "Total number of picked fruits: " << res
            << " \t--Expected: " << expec
            << (res == expec ? "\t--[PASSED]" : "\t--[FAILED]")
            << "\n";

  return 0;
}